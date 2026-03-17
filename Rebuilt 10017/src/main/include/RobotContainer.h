#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>
#include <frc2/command/button/CommandXboxController.h>

#include "subsystems/Drivesubsystem/DriveSubsystem.h"
#include "subsystems/ShooterSubsystem/ShooterSubsystem.h"
#include "subsystems/InjectorSubsystem/InjectorSubsystem.h"
#include "subsystems/LinearActuatorSubsystem/LinearActuatorSubsystem.h"
#include "subsystems/IntakeSubsystem/IntakeSubsystem.h"
#include "subsystems/AgitatorSubsystem/AgitatorSubsystem.h"

class RobotContainer {
public:
    RobotContainer();

    std::optional<frc2::CommandPtr> GetAutonomousCommand();

private:
    // Subsystems
    DriveSubsystem          drive;
    ShooterSubsystem        shooter{};
    InjectorSubsystem       injector{};
    LinearActuatorSubsystem actuator{};
    IntakeSubsystem         intake{};
    AgitatorSubsystem       agitator{};

    // Controller
    frc2::CommandXboxController driverController{0};
    frc2::CommandXboxController codriverController{1};

    void ConfigureBindings();
};