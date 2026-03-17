#pragma once

#include <frc/AnalogInput.h>
#include <frc2/command/Command.h>
#include <frc2/command/Commands.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include <rev/SparkFlex.h>
#include <rev/SparkClosedLoopController.h>
#include <rev/RelativeEncoder.h>

#include <subsystems/ShooterSubsystem/Constants.h>
#include <GlobalConstants.h>

using namespace frc;

class ShooterSubsystem : public frc2::SubsystemBase {
public:
    ShooterSubsystem();

    void Periodic() override;

    // ── RPM control ──────────────────────────────────────────
    void ShooterCorner(); 
    void ShooterOff();  
    void ShooterIntake();  
    void ShooterIn(); 
    void ShooterBarge();
    void ShooterTower();
    void ShooterHub();
    void SetShooterRPM(double rpm);

    // ── Telemetry helpers ────────────────────────────────────
    double GetLeftRPM()  const;
    double GetRightRPM() const;
    bool   AtTargetRPM() const;

    void SetShooterPower(double newPower);
    void GetShooterPower();
    void SetShooterState(int newState);
    int  GetShooterStates();
    void SetShooterBrakeMode(bool state);
    void ConfigShooter();

private:
    rev::spark::SparkFlex leftShooterMotor;
    rev::spark::SparkFlex rightShooterMotor;

    rev::spark::SparkClosedLoopController leftPID;
    rev::spark::SparkClosedLoopController rightPID;

    rev::spark::SparkRelativeEncoder leftEncoder;
    rev::spark::SparkRelativeEncoder rightEncoder;

    int    ShooterState = ShooterConstants::ShooterStates::kShooterPowerMode;
    double targetRPM    = ShooterConstants::kStopRPM;
};