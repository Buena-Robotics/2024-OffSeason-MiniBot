#ifndef VISION_CAMERA_H
#define VISION_CAMERA_H

#include <frc2/command/SubsystemBase.h>
#include <photon/simulation/PhotonCameraSim.h>
#include <photon/simulation/SimCameraProperties.h>
#include <photon/simulation/SimVisionSystem.h>
#include <photon/targeting/PhotonTrackedTarget.h>
#include <photon/PhotonCamera.h>
#include <photon/PhotonUtils.h>

namespace nerds {
    class VisionCamera : public frc2::SubsystemBase {
    public:
        VisionCamera() noexcept;
        void Periodic() override;
    private:
        photon::PhotonCamera photon_camera;
    };
}

#endif // VISION_CAMERA_H