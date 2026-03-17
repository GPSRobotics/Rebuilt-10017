#include "RobotContainer.h"
#include "GlobalConstants.h"
#include "subsystems/DriveSubsystem/Constants.h"

#include <frc2/command/Commands.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/MathUtil.h>
#include <units/time.h>

using namespace units::literals;

RobotContainer::RobotContainer() {
    ConfigureBindings();

    // ── Default drive command ─────────────────────────────────
    drive.SetDefaultCommand(frc2::RunCommand(
        [this] {
            double speed    = frc::ApplyDeadband( driverController.GetLeftY(),  0.1);
            double rotation = frc::ApplyDeadband(-driverController.GetRightX(), 0.1);
            double strafe   = frc::ApplyDeadband(driverController.GetLeftX(),  0.1);

            drive.ArcadeDrive(speed, rotation);
            drive.SetHWheelPower(strafe);
        },
        {&drive}
    ));
}

void RobotContainer::ConfigureBindings() {

    //  ── LT: intake off ───────────────────────────────────────
    // driverController.LeftTrigger().WhileTrue(frc2::cmd::Run([this]() {
    //     intake.IntakeOff();
    // }, {&intake}));

    /*driverController.A().OnTrue(
        frc2::cmd::Sequence(
            frc2::cmd::RunOnce([this]() {
                intake.Stow();
            }, {&intake}),
            frc2::cmd::WaitUntil([this]() {
                return intake.ArmAtTarget();
            }).WithTimeout(7_s),
            frc2::cmd::Run([this]() {
                intake.Deploy();
            }, {&intake})
        )
    );*/

    driverController.A().OnTrue(frc2::cmd::Run([this](){
        intake.Deploy();
    }, {&intake}));

    // ── B: stow intake ────────────────────────────────────────
    /*driverController.B().OnTrue(frc2::cmd::RunOnce([this]() {
        intake.Stow();
    }, {&intake}));
*/  
    driverController.B().WhileTrue(frc2::cmd::Run([this](){
        intake.IntakeOff();
    }, {&intake}));

    // ── RT: shoot sequence ────────────────────────────────────
    driverController.RightTrigger().WhileTrue(
        frc2::cmd::Sequence(
            frc2::cmd::RunOnce([this]() {
                shooter.ShooterCorner();
            }, {&shooter}),
            frc2::cmd::WaitUntil([this]() {
                return shooter.AtTargetRPM();
            }).WithTimeout(3_s),
            frc2::cmd::Run([this]() {
                injector.InjectorOut();
                agitator.AgitatorAgitate();
            }, {&injector, &agitator})
        )
    );
   

    // ── X: stop all ──────────────────────────────────────────
    driverController.X().OnTrue(frc2::cmd::RunOnce([this]() {
        shooter.ShooterOff();
        injector.InjectorOff();
        agitator.AgitatorOff();
    }, {&shooter, &injector, &agitator}));

     driverController.POVUp().WhileTrue(frc2::cmd::Run([this]() {
        shooter.ShooterCorner();
        injector.InjectorIn();
        agitator.AgitatorIn();
    }, {&shooter, &injector, &agitator}));

     driverController.POVDown().WhileTrue(frc2::cmd::Run([this]() {
        shooter.ShooterBarge();
        injector.InjectorIn();
        agitator.AgitatorIn();
    }, {&shooter, &injector, &agitator}));

     driverController.POVLeft().WhileTrue(frc2::cmd::Run([this]() {
        shooter.ShooterHub();
        injector.InjectorIn();
        agitator.AgitatorIn();
    }, {&shooter, &injector, &agitator}));
    
     driverController.POVRight().WhileTrue(frc2::cmd::Run([this]() {
        shooter.ShooterTower();
        injector.InjectorIn();
        agitator.AgitatorIn();
    }, {&shooter, &injector, &agitator}));
}

std::optional<frc2::CommandPtr> RobotContainer::GetAutonomousCommand() {
    return std::nullopt;
}