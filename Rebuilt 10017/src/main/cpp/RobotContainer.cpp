// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here
    controller.X().WhileTrue(frc2::cmd::Run([this](){
        Intake.On();
    },{&Intake}));
    
    controller.Y().WhileTrue(frc2::cmd::Run([this](){
        Intake.Off();
    },{&Intake}));
   //d pad up On
    //d pad down Off
}
 
