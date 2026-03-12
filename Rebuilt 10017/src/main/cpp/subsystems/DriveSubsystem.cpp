#include "subsystems/DriveSubsystem/DriveSubsystem.h"
#include <frc/smartdashboard/SmartDashboard.h>

DriveSubsystem::DriveSubsystem() {

// Shuffleboard test inputs
frc::SmartDashboard::PutNumber("Left Drive", 0.0);
frc::SmartDashboard::PutNumber("Right Drive", 0.0);


}

void DriveSubsystem::Drive(double leftSpeed, double rightSpeed) {

frc::SmartDashboard::PutNumber("Left Motor Output", leftSpeed);
frc::SmartDashboard::PutNumber("Right Motor Output", rightSpeed);

m_leftMotor.Set(leftSpeed);
m_rightMotor.Set(rightSpeed);

}

void DriveSubsystem::Periodic() {

double left = frc::SmartDashboard::GetNumber("Left Drive", 0.0);
double right = frc::SmartDashboard::GetNumber("Right Drive", 0.0);

Drive(left, right);

}
