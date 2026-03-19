#include "subsystems/Feeder/Feeder.h"


FeederSubsystem::FeederSubsystem() {
}

void FeederSubsystem::RunFeeder() {
    
    feederMotor.Set(FeederConstants::kFeederSpeed);

}

void FeederSubsystem::StopFeeder() {

    feederMotor.Set(0);
}

bool FeederSubsystem::ToggleFeeder() {

    if (Toggles::toggleRB) {

        FeederSubsystem::RunFeeder();
        Toggles::toggleRB == !Toggles::toggleRB;
    }

    else {

        FeederSubsystem::StopFeeder();
        Toggles::toggleRB == !Toggles::toggleRB;
    }
}