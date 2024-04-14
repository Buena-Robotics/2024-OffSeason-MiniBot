// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/WaitCommand.h>

#include "commands/Autos.h"

RobotContainer::RobotContainer() noexcept {
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() noexcept {
  // frc2::Trigger([this] {
    // return m_subsystem.ExampleCondition();
  // }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  // pressed, cancelling on release.
  // m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() noexcept {
  return frc2::WaitCommand(units::second_t{1}).ToPtr();
  // return autos::ExampleAuto(&m_subsystem);
}
