#ifndef VISION_CAMERA_H
#define VISION_CAMERA_H

#include <vector>
#include <string>

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
        typedef photon::PhotonTrackedTarget Yolov5Detection;

        VisionCamera() noexcept;
        void Periodic() override;
        const std::vector<Yolov5Detection> &GetYolov5Detections() const noexcept { return yolov5_detections; }
    private:
        photon::PhotonCamera photon_camera;
        std::vector<Yolov5Detection> yolov5_detections;
};

}

#endif // VISION_CAMERA_H