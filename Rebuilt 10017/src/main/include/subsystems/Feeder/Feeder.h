#pragma once 

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkFlex.h>
#include "GlobalConstants.h"


class FeederSubsystem : public frc2::SubsystemBase {

public: 

    FeederSubsystem();
    
    void RunFeeder();
    
    void StopFeeder();

    bool ToggleFeeder();

private: 

    rev::spark::SparkFlex feederMotor{

        FeederConstants::kFeederMotor,
        rev::spark::SparkFlex::MotorType::kBrushless
    };

};