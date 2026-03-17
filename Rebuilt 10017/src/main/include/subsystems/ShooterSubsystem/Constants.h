#pragma once

#include <units/time.h>
#include <units/angle.h>

namespace ShooterConstants {

    // ── Motor ports ───────────────────────────────────────────
    constexpr int kLeftShooterPort  = 5;
    constexpr int kRightShooterPort = 6;
    //H-Wheel is 9

    // ── RPM targets ───────────────────────────────────────────
    constexpr double kShootCornerRPM    = 7000.0;  
    constexpr double kShootBargeRPM     = 6300.0;  
    constexpr double kShootTowerRPM     = 5725.0;  
    constexpr double kShootHubRPM       = 4000.0;  
    constexpr double kIntakeRPM   =  800.0;
    constexpr double kReverseRPM  = -800.0;
    constexpr double kStopRPM     =    0.0;

    constexpr double kP           = 0.0003;
    constexpr double kI           = 0.0;
    constexpr double kD           = 0.0;
    constexpr double kFF          = 0.000175;
    constexpr double kMinOutput   = -1.0;
    constexpr double kMaxOutput   =  1.0;

    constexpr double kRPMTolerance = 100.0;

    // ── Shooter States ────────────────────────────────────────
    enum ShooterStates {
        kShooterOff,
        kShooterPowerMode
    };
}