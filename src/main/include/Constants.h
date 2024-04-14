// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/XboxController.h>
#include <frc2/command/button/CommandXboxController.h>

namespace Constants {
    namespace IO {
        inline constexpr int kDriverControllerPort = 0;
        inline const frc::XboxController controller{kDriverControllerPort};
        inline frc2::CommandXboxController command_controller{kDriverControllerPort};
    }
}  // namespace Constants
