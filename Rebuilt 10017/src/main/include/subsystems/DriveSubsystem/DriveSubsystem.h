#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkFlex.h>

class DriveSubsystem : public frc2::SubsystemBase {
public:
    DriveSubsystem();

    void Drive(double leftSpeed, double rightSpeed);

    void Periodic() override;

private:

    rev::spark::SparkFlex m_leftMotor{
        1, rev::spark::SparkLowLevel::MotorType::kBrushless};

    rev::spark::SparkFlex m_rightMotor{
        2, rev::spark::SparkLowLevel::MotorType::kBrushless};
    

};