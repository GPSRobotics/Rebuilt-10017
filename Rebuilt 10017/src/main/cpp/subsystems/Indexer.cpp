#include "subsystems/Indexer/Indexer.h"


IndexerSubsystem::IndexerSubsystem() {
};

void IndexerSubsystem::RunIndexer() {
    
    indexerMotor.Set(IndexerConstants::kIndexerSpeed);

};

void IndexerSubsystem::StopIndexer() {

    indexerMotor.Set(0);
};

