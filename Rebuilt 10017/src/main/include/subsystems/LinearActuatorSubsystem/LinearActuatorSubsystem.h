//DOESN'T WORK





//DOESN'T WORK



#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Servo.h>
#include <units/length.h>
#include "constants.h"

/**
 * LinearActuatorSubsystem
 *
 *
 * Usage (in RobotContainer or a Command):
 *   m_actuator.SetPosition(75.0_mm);
 *
 *   // Extend fully
 *   m_actuator.SetExtended();
 *
 *   // Retract fully
 *   m_actuator.SetRetracted();
 */
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

    // ── SubsystemBase override ────────────────────────────────
    void Periodic() override;

private:
    frc::Servo m_servo;

    double m_commandedPosition_mm { 0.0 };

    static double MmToNormalized(double mm);

    static double Clamp(double value, double lo, double hi);
};