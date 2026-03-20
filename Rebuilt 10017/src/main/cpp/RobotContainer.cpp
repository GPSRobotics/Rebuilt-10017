// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "GlobalConstants.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Commands.h>
#include "subsystems/Indexer/Indexer.h"
#include "subsystems/Feeder/Feeder.h"
#include "frc2/command/Commands.h"
#include "frc2/command/button/JoystickButton.h"
#include "frc2/command/WaitCommand.h"
#include <units/time.h>




RobotContainer::RobotContainer() {

drive.SetDefaultCommand(
    frc2::cmd::Run([this] {
        double left = -m_driverController.GetLeftY();
        double right = -m_driverController.GetRightY();
        double strafe = m_driverController.GetLeftX();
        drive.Drive(left, right, strafe);
    }, {&drive})
);
  ConfigureBindings();
};

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here
  m_driverController.X().OnTrue(frc2::cmd::Run([this](){
      
    Intake.Off();
    Indexer.StopIndexer();
    Feeder.StopFeeder();
    Shooter.ShooterStop();
  },{&Intake, &Indexer, &Feeder, &Shooter}));
  
 m_driverController.Y().OnTrue(frc2::cmd::Run([this](){

      Intake.On();
  },{&Intake}));
  //d pad up On
  //d pad down Off

  m_driverController.RightTrigger().WhileTrue(frc2::cmd::Run([this](){
  Shooter.ShooterShoot();
  }, {&shooter}));

  m_driverController.RightBumper().WhileTrue(frc2::cmd::Run([this](){
    Shooter.ShooterStop();
  }, {&shooter}));

  m_driverController.LeftTrigger().WhileTrue(frc2::cmd::Run([this](){
    Shooter.ShooterBack();
  }, {&shooter})); 
  
  //Runs Feeder 

  m_driverController.RightTrigger()
  .WhileTrue(

    frc2::cmd::RunOnce(
     
      [this] { 
        Feeder.RunFeeder(); 
        Indexer.RunIndexer();

      }, {&Feeder}
      
    )
  );
};

void RobotContainer::DriveForward(double SL, double SR, double SH) {

  Drive.Drive(SL, SR, SH);
  frc2::WaitCommand(2_s);
  Drive.Drive(0, 0, 0);
};

void RobotContainer::DriveBackwards(double SL, double SR, double SH) {

  Drive.Drive(SL, SR, SH);
  frc2::WaitCommand(2_s);
  Drive.Drive(0, 0, 0);
};

void RobotContainer::TurnLeft() {

  Drive.Drive(-0.5, 0.5, 0);
};

void RobotContainer::TurnRight() {

  Drive.Drive(0.5, -0.5, 0);
};

void RobotContainer::Shoot() {

  Indexer.RunIndexer();
  Feeder.RunFeeder();
  Shooter.ShooterShoot();
};

void RobotContainer::ShootStop() {

  Indexer.StopIndexer();
  Feeder.StopFeeder(); 
  Shooter.ShooterStop(); 
};


frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  using namespace frc2::cmd;

  return Sequence(

    // Shoot
    RunOnce([this] { Shoot(); }),
    Wait(5_s),
    RunOnce([this] { ShootStop(); }),

    // Drive forward
    RunOnce([this] { Drive.Drive(1, 1, 0); }),
    Wait(2_s),
    RunOnce([this] { Drive.Drive(0, 0, 0); }),

    // Turn right
    RunOnce([this] { TurnRight(); }),
    Wait(1_s),

    // Intake on
    RunOnce([this] { Intake.On(); }),

    // Drive forward slow
    RunOnce([this] { Drive.Drive(0.25, 0.25, 0); }),
    Wait(5_s),
    RunOnce([this] { Drive.Drive(0, 0, 0); }),

    // Turn again
    RunOnce([this] { TurnRight(); }),
    Wait(1_s),

    // Final move
    RunOnce([this] { Drive.Drive(0.25, 0.25, 0.25); }),
    Wait(5_s),
    RunOnce([this] { Drive.Drive(0, 0, 0); })
  );
}