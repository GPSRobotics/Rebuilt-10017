#include "subsystems/DriveSubsystem/DriveSubsystem.h"
#include "subsystems/DriveSubsystem/Constants.h"

#include <ctre/phoenix6/controls/DutyCycleOut.hpp>
#include <rev/config/SparkMaxConfig.h>
#include <algorithm>

using namespace ctre::phoenix6;
using namespace DriveConstants;

// ─────────────────────────────────────────────────────────────────────────────
//  Constructor
// ─────────────────────────────────────────────────────────────────────────────
DriveSubsystem::DriveSubsystem()
    : leftMotor  { kLeftMotorID  }
    , rightMotor { kRightMotorID }
    , middleMotor{ kMiddleMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless }
{
    // ── Left TalonFX ──────────────────────────────────────────
    configs::TalonFXConfiguration leftConfig{};
    leftConfig.MotorOutput.Inverted = signals::InvertedValue::CounterClockwise_Positive;
    leftMotor.GetConfigurator().Apply(leftConfig);

    // ── Right TalonFX (inverted) ──────────────────────────────
    configs::TalonFXConfiguration rightConfig{};
    rightConfig.MotorOutput.Inverted = signals::InvertedValue::Clockwise_Positive;
    rightMotor.GetConfigurator().Apply(rightConfig);

    // ── H-wheel SparkMax (NEO) ────────────────────────────────
    rev::spark::SparkMaxConfig middleConfig{};
    middleConfig.SetIdleMode(rev::spark::SparkMaxConfig::IdleMode::kBrake);
    middleConfig.Inverted(false);

    middleMotor.Configure(middleConfig,
        rev::ResetMode::kResetSafeParameters,
        rev::PersistMode::kPersistParameters);
}

// ─────────────────────────────────────────────────────────────────────────────
//  Periodic
// ─────────────────────────────────────────────────────────────────────────────
void DriveSubsystem::Periodic()
{
    leftPosition.Refresh();
    rightPosition.Refresh();

    frc::SmartDashboard::PutNumber("Drive/LeftEncoder",   leftPosition.GetValue().value());
    frc::SmartDashboard::PutNumber("Drive/RightEncoder",  rightPosition.GetValue().value());
    frc::SmartDashboard::PutNumber("Drive/HWheelPower",   middleMotor.Get());
}

// ─────────────────────────────────────────────────────────────────────────────
//  ArcadeDrive — left/right drive motors
// ─────────────────────────────────────────────────────────────────────────────
void DriveSubsystem::ArcadeDrive(double speed, double rotation)
{
    double leftOutput  = std::clamp(speed + rotation, -1.0, 1.0);
    double rightOutput = std::clamp(speed - rotation, -1.0, 1.0);

    controls::DutyCycleOut leftControl  {leftOutput};
    controls::DutyCycleOut rightControl {rightOutput};

    leftMotor.SetControl(leftControl);
    rightMotor.SetControl(rightControl);
}

// ─────────────────────────────────────────────────────────────────────────────
//  SetHWheelPower — centre strafing wheel
// ─────────────────────────────────────────────────────────────────────────────
void DriveSubsystem::SetHWheelPower(double power)
{
    // Clamp to safe range and apply
    middleMotor.Set(std::clamp(power, -1.0, 1.0));
}