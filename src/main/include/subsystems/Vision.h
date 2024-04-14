#ifndef VISION_SUBSYSTEM_H
#define VISION_SUBSYSTEM_H

#include "VisionCamera.h"

#include <frc2/command/SubsystemBase.h>
#include <photon/simulation/PhotonCameraSim.h>
#include <photon/simulation/SimCameraProperties.h>
#include <photon/simulation/SimVisionSystem.h>
#include <photon/targeting/PhotonTrackedTarget.h>
#include <photon/PhotonCamera.h>
#include <photon/PhotonUtils.h>

namespace nerds {
    class Vision : public frc2::SubsystemBase {
    public:
        Vision() noexcept;
    private:
        std::array<VisionCamera, 1> cameras = {
            VisionCamera{}
        };
    };
}

#endif // VISION_SUBSYSTEM_H