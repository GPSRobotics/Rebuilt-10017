#include "subsystems/ShooterSubsystem/ShooterSubsystem.h"
#include "rev/config/SparkFlexConfig.h"

using namespace rev::spark;
using namespace frc;

ShooterSubsystem::ShooterSubsystem():
    kRightShooterMotor{ShooterConstants::kRightMotorPort, SparkLowLevel::MotorType::kBrushless},
    kLeftShooterMotor{ShooterConstants::kLeftMotorPort, SparkLowLevel::MotorType::kBrushless}
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

    void ShooterSubsystem::Periodic() {}

    void ShooterSubsystem::ShooterShoot(){
        kRightShooterMotor.Set(1.0);
        kLeftShooterMotor.Set(1.0);
    }

    void ShooterSubsystem::ShooterStop(){
        kRightShooterMotor.Set(0.0);
        kLeftShooterMotor.Set(0.0);
    }

    void ShooterSubsystem::ShooterBack(){
        kRightShooterMotor.Set(-1.0);
        kLeftShooterMotor.Set(-1.0);
    }