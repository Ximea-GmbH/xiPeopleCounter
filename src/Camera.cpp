//
// Created by alex on 25.08.21.
//

#include "Camera.h"

auto Camera::GetDefault() -> Camera {
  auto cam = Camera();
  cam.OpenFirst();
  cam.SetImageDataFormat(XI_MONO8);
  constexpr auto kExposureTime = 1000.F;
  cam.SetExposureTime(kExposureTime);
  return cam;
}
