#ifndef DRIVE_TRAIN_SUBSYSTEM_H
#define DRIVE_TRAIN_SUBSYSTEM_H

#include <Constants.h>

#include <AHRS.h>
#include <frc/estimator/DifferentialDrivePoseEstimator.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/kinematics/DifferentialDriveWheelPositions.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <frc/simulation/DifferentialDrivetrainSim.h>

namespace nerds {
    class DriveTrain : public frc2::SubsystemBase {
    public:
        DriveTrain() noexcept;
        void Periodic() override;
        inline void UpdatePoseEstimation() noexcept;
    private:
        const wpi::array<double, 3> state_std_devs = wpi::array<double, 3>{0.1, 0.1, 0.1};
        const wpi::array<double, 3> vision_measurement_std_devs = wpi::array<double, 3>{1.0, 2.0, 5.0};
        const frc::DCMotor drive_motor = frc::DCMotor::NEO(2);
        const double gear_ratio = 1 / 1.0;
        const units::kilogram_square_meter_t center_inertia = 1_kg_sq_m;
        const units::kilogram_t mass = 18_kg;
        const units::meter_t wheel_radius = 8_in;
        const units::meter_t track_width = 0.5_m;

        units::second_t dt = 0_s;
        AHRS navx{frc::SerialPort::Port::kUSB1}; 
        frc::VictorSP left_motor{0};
        frc::VictorSP right_motor{1};
        frc::DifferentialDriveKinematics kinematics{0.7_m};
        frc::DifferentialDriveOdometry odometry{frc::Rotation2d(), 0_m, 0_m, frc::Pose2d()};
        frc::DifferentialDrivePoseEstimator pose_estimator{kinematics, frc::Rotation2d{}, 0_m, 0_m, frc::Pose2d{}, state_std_devs, vision_measurement_std_devs};
        frc::DifferentialDrive differential_drive{left_motor, right_motor};
        frc::sim::DifferentialDrivetrainSim differential_drive_sim{drive_motor, gear_ratio, center_inertia, mass, wheel_radius, track_width};
    };
}


#endif // DRIVE_TRAIN_SUBSYSTEM_H