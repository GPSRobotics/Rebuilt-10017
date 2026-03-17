#pragma once

#include <units/time.h>

namespace ActuonixL16 {

    // ── PWM channel wired on the roboRIO ──────────────────────
    constexpr int kPwmChannel = 0;

    // ── PWM pulse widths ──────────────────────────────────────
    constexpr units::microsecond_t kPulseMax_us      = 2000_us;
    constexpr units::microsecond_t kPulseMin_us      = 1000_us; 
    constexpr units::microsecond_t kPulseCentre_us   = 1500_us; 
    constexpr units::microsecond_t kDeadbandHigh_us  = 1520_us; 
    constexpr units::microsecond_t kDeadbandLow_us   = 1480_us; 

    // ── Physical limits ───────────────────────────────────────
    constexpr double kStroke_mm           = 100.0;
    constexpr double kMinPosition_mm      =   0.0;
    constexpr double kMaxPosition_mm      = 100.0;

    // ── Safety / tuning ───────────────────────────────────────
    constexpr double kPositionTolerance_mm = 2.0;  

}