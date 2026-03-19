#include "subsystems/Indexer/Indexer.h"


IndexerSubsystem::IndexerSubsystem() {
}

void IndexerSubsystem::RunIndexer() {
    
    indexerMotor.Set(IndexerConstants::kIndexerSpeed);

}

void IndexerSubsystem::StopIndexer() {

    indexerMotor.Set(0);
}

bool IndexerSubsystem::ToggleIndexer() {

    if (Toggles::toggleRB) {

        IndexerSubsystem::RunIndexer();
        Toggles::toggleRB == !Toggles::toggleRB;
    }

    else {

        IndexerSubsystem::StopIndexer();
        Toggles::toggleRB == !Toggles::toggleRB;
    }
}