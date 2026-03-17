#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <rev/SparkMax.h>

class DriveSubsystem : public frc2::SubsystemBase {
public:
    DriveSubsystem();

    // ── Drive ─────────────────────────────────────────────────
    void ArcadeDrive(double speed, double rotation);

    void SetHWheelPower(double power);

    void Periodic() override;

private:
    // ── Left / right drive motors (Kraken on TalonFX) ─────────
    ctre::phoenix6::hardware::TalonFX leftMotor;
    ctre::phoenix6::hardware::TalonFX rightMotor;

    // ── H-wheel motor (NEO on SparkMax) ──────────────────────
    rev::spark::SparkMax middleMotor;

    // ── Encoder signals ───────────────────────────────────────
    ctre::phoenix6::StatusSignal<units::angle::turn_t>& leftPosition  = leftMotor.GetPosition();
    ctre::phoenix6::StatusSignal<units::angle::turn_t>& rightPosition = rightMotor.GetPosition();
};