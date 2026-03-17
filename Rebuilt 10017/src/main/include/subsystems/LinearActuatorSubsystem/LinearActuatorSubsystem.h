#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Servo.h>
#include <units/length.h>
#include "constants.h"

class LinearActuatorSubsystem : public frc2::SubsystemBase {
public:
    LinearActuatorSubsystem();

    // ── Primary control ──────────────────────────────────────

    void SetPosition(double targetPosition_mm);

    void SetRetracted();

    void SetExtended();

    void SetNormalized(double value);

    // ── Telemetry ────────────────────────────────────────────
    double GetCommandedPosition_mm() const;

    double GetNormalizedPosition()   const;

    void Periodic() override;

private:
    frc::Servo m_servo;

    double m_commandedPosition_mm { 0.0 };
 
    static double MmToNormalized(double mm);

    static double Clamp(double value, double lo, double hi);
};