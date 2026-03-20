#include "subsystems/Intake/IntakeSubsystem.h"
#include "GlobalConstants.h"
#include "rev/config/SparkMaxConfig.h"

IntakeSubsystem::IntakeSubsystem():
Intake{IntakeConstants::IntakePort, rev::spark::SparkLowLevel::MotorType::kBrushless}
{
    rev::spark::SparkMaxConfig config{};
    
    config.Inverted(false)
    .SetIdleMode(rev::spark::SparkMaxConfig::IdleMode::kBrake);

    Intake.Configure(config, rev::spark::SparkMax::ResetMode::kResetSafeParameters,
    rev::spark::SparkMax::PersistMode::kPersistParameters);
};


   

void IntakeSubsystem::On(){

     IntakeConstants::IntakeSpeed = 0.75;
     Intake.Set(IntakeConstants::IntakeSpeed);

};
void IntakeSubsystem::Off(){
    
    IntakeConstants::IntakeSpeed = 0.0;
    Intake.Set(IntakeConstants::IntakeSpeed); 
};
