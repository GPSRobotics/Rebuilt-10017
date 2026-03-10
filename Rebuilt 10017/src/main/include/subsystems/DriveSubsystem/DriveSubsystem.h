#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>

class DriveSubsystem : public frc2::SubsystemBase {
public:
DriveSubsystem();

void Drive(double leftSpeed, double rightSpeed);

void Periodic() override;

private:

ctre::phoenix6::hardware::TalonFX m_leftMotor{1};
ctre::phoenix6::hardware::TalonFX m_rightMotor{2};


};
