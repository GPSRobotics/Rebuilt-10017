// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants {

    inline constexpr int kDriverControllerPort = 0;
};

namespace IntakeConstants{

    inline constexpr int IntakePort = 1;
    extern double IntakeSpeed;
};
 // namespace OperatorConstants

namespace IndexerConstants {

    inline constexpr int kIndexerMotor = 2;
    extern double kIndexerSpeed;
};

namespace FeederConstants {

    inline constexpr int kFeederMotor = 3;
    extern double kFeederSpeed;
}; 

namespace Toggles {

    extern bool toggleRB;
}


namespace ShooterConstants {

    inline constexpr int kLeftMotorPort = 4;
    inline constexpr int kRightMotorPort = 5;

    //------ PID ------
    inline constexpr double KP = 0;
    inline constexpr double KI = 0;
    inline constexpr double KD = 0;
    inline constexpr double KFF = 0;
    
};

