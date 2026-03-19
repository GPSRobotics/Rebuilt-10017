// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <GlobalConstants.h>
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



namespace IntakeConstants{
  constexpr int IntakePort = 1;
};
}  // namespace OperatorConstants

namespace IndexerConstants {

    constexpr int kIndexerMotor = 1;
    constexpr double kIndexerSpeed = 0.8; 
};

namespace FeederConstants {

    constexpr int kFeederMotor = 2; 
    constexpr double kFeederSpeed = 1; 
}; 

namespace Toggles {

    extern bool toggleRB;
}
