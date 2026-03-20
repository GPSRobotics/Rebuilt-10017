#pragma once 

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include "GlobalConstants.h"


class IndexerSubsystem : public frc2::SubsystemBase {

public: 

    IndexerSubsystem();
    
    void RunIndexer();
    
    void StopIndexer();

    bool ToggleIndexer();

private: 

    rev::spark::SparkMax indexerMotor{

        IndexerConstants::kIndexerMotor,
        rev::spark::SparkMax::MotorType::kBrushless
    };

};