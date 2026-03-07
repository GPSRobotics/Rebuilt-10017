#include "subsystems/ShooterSubsystem/ShooterSubsystem.h"
#include "rev/config/SparkFlexConfig.h"
#include <frc/smartdashboard/SmartDashboard.h>

using namespace rev::spark;
using namespace frc;

ShooterSubsystem::ShooterSubsystem():
    kRightShooterMotor{ShooterConstants::kRightMotorPort, SparkLowLevel::MotorType::kBrushless},
    kLeftShooterMotor{ShooterConstants::kLeftMotorPort, SparkLowLevel::MotorType::kBrushless},

    m_leftController{kLeftShooterMotor.GetClosedLoopController()},
    m_rightController{kRightShooterMotor.GetClosedLoopController()},

    m_leftEncoder{kLeftShooterMotor.GetEncoder()},
    m_rightEncoder{kRightShooterMotor.GetEncoder()}

    {       
        SparkFlexConfig rightConfig{};
        rightConfig.Inverted(false)
                    .SetIdleMode(rev::spark::SparkFlexConfig::IdleMode::kCoast);
        kRightShooterMotor.Configure(rightConfig,
            SparkFlex::ResetMode::kResetSafeParameters,
            SparkFlex::PersistMode::kPersistParameters);

         SparkFlexConfig leftConfig{};
        leftConfig.Inverted(true)
                    .SetIdleMode(rev::spark::SparkFlexConfig::IdleMode::kCoast);
        kLeftShooterMotor.Configure(leftConfig,
            SparkFlex::ResetMode::kResetSafeParameters,
            SparkFlex::PersistMode::kPersistParameters);            
    
    }

    void ShooterSubsystem::Periodic() {
        frc::SmartDashboard::PutNumber("RPM", GetRPM());
    }

    void ShooterSubsystem::ShooterShoot(){
        SetRPM(5000);
    }

    void ShooterSubsystem::ShooterStop(){
        SetRPM(0);
    }

    void ShooterSubsystem::ShooterBack(){
        SetRPM(-5000);
    }

    void ShooterSubsystem::SetRPM(double rpm){
        m_targetRPM = rpm;

        m_leftController.SetReference(rpm, rev::spark::SparkBase::ControlType::kVelocity);
        m_rightController.SetReference(rpm, rev::spark::SparkBase::ControlType::kVelocity);

    }

    double ShooterSubsystem::GetRPM(){
        return (m_leftEncoder.GetVelocity() + m_rightEncoder.GetVelocity()) / 2.0;
    
    }