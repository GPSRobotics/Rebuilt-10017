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
  m_driverController.X().WhileTrue(frc2::cmd::Run([this](){
      Intake.On();
  },{&Intake}));
  
 m_driverController.Y().WhileTrue(frc2::cmd::Run([this](){
      Intake.Off();
  },{&Intake}));
  //d pad up On
  //d pad down Off

  m_driverController.RightTrigger().WhileTrue(frc2::cmd::Run([this](){
  shooter.ShooterShoot();
  }, {&shooter}));

  m_driverController.RightBumper().WhileTrue(frc2::cmd::Run([this](){
    shooter.ShooterStop();
  }, {&shooter}));

  m_driverController.LeftTrigger().WhileTrue(frc2::cmd::Run([this](){
    shooter.ShooterBack();
  }, {&shooter})); 
  
  //Runs Feeder 

  frc2::JoystickButton(&driverController, frc::XboxController::Button::kRightBumper)
  .OnTrue(

    frc2::cmd::RunOnce(
     
      [this] { Feeder.ToggleFeeder(); }, {&Feeder}
      
    )
  );

  //Runs Indexer

  frc2::JoystickButton(&driverController, frc::XboxController::Button::kRightBumper)
  .OnTrue(

    frc2::cmd::RunOnce(
     
      [this] { Indexer.ToggleIndexer(); }, {&Indexer}

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
  
  Shoot(); 
  frc2::WaitCommand(5_s);
  ShootStop(); 
  DriveForward(2);
  TurnRight();
  Intake.On();
  DriveForward(0.25,0.25,0);
  frc2::WaitCommand(5);
  TurnRight();
  DriveForward(0.25,0.25,0.25);
  frc2::WaitCommand(5);
  return frc2::cmd::None();
};