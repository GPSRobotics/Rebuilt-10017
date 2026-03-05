#include "subsystems/ShooterSubsystem/Constants.h"

#include <frc2/command/Command.h>
#include <frc2/command/Commands.h>
#include <frc2/command/SubsystemBase.h>

#include <rev/SparkFlex.h>

class ShooterSubsystem : public frc2::SubsystemBase {
public:
    ShooterSubsystem();

    void Periodic() override;

    void ShooterShoot();
    void ShooterStop();
    void ShooterBack();

private:
    
rev::spark::SparkFlex kLeftShooterMotor;
rev::spark::SparkFlex kRightShooterMotor;

};
