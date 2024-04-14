// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"
#include "subsystems/DriveTrain.h"
#include "subsystems/Vision.h"

#include <frc2/command/CommandPtr.h>

class RobotContainer {
public:
    RobotContainer() noexcept;
    frc2::CommandPtr GetAutonomousCommand() noexcept;

    static nerds::DriveTrain drive_train;
    static nerds::Vision vision;
private:
    void ConfigureBindings() noexcept;
};
