#include "subsystems/ShooterSubsystem/ShooterSubsystem.h"
#include "rev/config/SparkFlexConfig.h"

#include <iostream>
#include <cmath>

using namespace frc;
using namespace rev::spark;

ShooterSubsystem::ShooterSubsystem()
    : leftShooterMotor {ShooterConstants::kLeftShooterPort,  SparkLowLevel::MotorType::kBrushless},
      rightShooterMotor{ShooterConstants::kRightShooterPort, SparkLowLevel::MotorType::kBrushless},
      leftPID   {leftShooterMotor.GetClosedLoopController()},
      rightPID  {rightShooterMotor.GetClosedLoopController()},
      leftEncoder {leftShooterMotor.GetEncoder()},
      rightEncoder{rightShooterMotor.GetEncoder()}
{
    // ── Left motor ────────────────────────────────────────────
    SparkFlexConfig leftConfig{};
    leftConfig.Inverted(false)
              .SetIdleMode(SparkFlexConfig::IdleMode::kCoast);

    leftConfig.closedLoop
        .Pidf(ShooterConstants::kP,
              ShooterConstants::kI,
              ShooterConstants::kD,
              ShooterConstants::kFF)
        .OutputRange(ShooterConstants::kMinOutput,
                     ShooterConstants::kMaxOutput);

    leftShooterMotor.Configure(leftConfig,
        rev::ResetMode::kResetSafeParameters,
        rev::PersistMode::kPersistParameters);

    // ── Right motor (inverted) ────────────────────────────────
    SparkFlexConfig rightConfig{};
    rightConfig.Inverted(true)
               .SetIdleMode(SparkFlexConfig::IdleMode::kCoast);

    rightConfig.closedLoop
        .Pidf(ShooterConstants::kP,
              ShooterConstants::kI,
              ShooterConstants::kD,
              ShooterConstants::kFF)
        .OutputRange(ShooterConstants::kMinOutput,
                     ShooterConstants::kMaxOutput);

    rightShooterMotor.Configure(rightConfig,
        rev::ResetMode::kResetSafeParameters,
        rev::PersistMode::kPersistParameters);
}

// ─────────────────────────────────────────────────────────────────────────────
//  Periodic
// ─────────────────────────────────────────────────────────────────────────────
void ShooterSubsystem::Periodic()
{
    frc::SmartDashboard::PutNumber("Shooter/LeftRPM",   GetLeftRPM());
    frc::SmartDashboard::PutNumber("Shooter/RightRPM",  GetRightRPM());
    frc::SmartDashboard::PutNumber("Shooter/TargetRPM", targetRPM);
    frc::SmartDashboard::PutBoolean("Shooter/AtSpeed",  AtTargetRPM());
}

// ─────────────────────────────────────────────────────────────────────────────
//  RPM control
// ─────────────────────────────────────────────────────────────────────────────
void ShooterSubsystem::SetShooterRPM(double rpm)
{
    targetRPM = rpm;
    leftPID .SetReference(rpm, SparkLowLevel::ControlType::kVelocity);
    rightPID.SetReference(rpm, SparkLowLevel::ControlType::kVelocity);
}

void ShooterSubsystem::ShooterCorner()     { SetShooterRPM(ShooterConstants::kShootCornerRPM);   }
void ShooterSubsystem::ShooterOff()     { SetShooterRPM(ShooterConstants::kStopRPM);    }
void ShooterSubsystem::ShooterIntake()  { SetShooterRPM(ShooterConstants::kIntakeRPM);  }
void ShooterSubsystem::ShooterBarge()      { SetShooterRPM(ShooterConstants::kShootBargeRPM); }
void ShooterSubsystem::ShooterTower()      { SetShooterRPM(ShooterConstants::kShootTowerRPM); }
void ShooterSubsystem::ShooterHub()      { SetShooterRPM(ShooterConstants::kShootHubRPM); }

// ─────────────────────────────────────────────────────────────────────────────
//  Telemetry
// ─────────────────────────────────────────────────────────────────────────────
double ShooterSubsystem::GetLeftRPM()  const { return leftEncoder.GetVelocity();  }
double ShooterSubsystem::GetRightRPM() const { return rightEncoder.GetVelocity(); }

bool ShooterSubsystem::AtTargetRPM() const
{
    bool leftOk  = std::abs(GetLeftRPM()  - targetRPM) < ShooterConstants::kRPMTolerance;
    bool rightOk = std::abs(GetRightRPM() - targetRPM) < ShooterConstants::kRPMTolerance;
    return leftOk && rightOk;
}

// ─────────────────────────────────────────────────────────────────────────────
//  Legacy stubs
// ─────────────────────────────────────────────────────────────────────────────
void ShooterSubsystem::SetShooterPower(double newPower) {}
void ShooterSubsystem::GetShooterPower() {}
void ShooterSubsystem::SetShooterState(int newState)   { ShooterState = newState; }
int  ShooterSubsystem::GetShooterStates()              { return ShooterState; }
void ShooterSubsystem::SetShooterBrakeMode(bool state) {}
void ShooterSubsystem::ConfigShooter() {}