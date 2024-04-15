#include "subsystems/DriveTrain.h"

nerds::DriveTrain::DriveTrain() noexcept {
    left_motor.SetInverted(false);
    right_motor.SetInverted(true);
}

void nerds::DriveTrain::Periodic() {
    const double forward_input = Constants::IO::controller.GetLeftY();
    const double rotation_input = Constants::IO::controller.GetLeftX();
    differential_drive.ArcadeDrive(forward_input, rotation_input);
    UpdatePoseEstimation();
}

inline void nerds::DriveTrain::UpdatePoseEstimation() noexcept {
    odometry.Update(navx.GetRotation2d(), 0_m, 0_m);
    pose_estimator.Update(navx.GetRotation2d(), 0_m, 0_m);
}