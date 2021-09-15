#include <iostream>
#include "Camera.h"
#include "Ui.h"
#include "Detector.h"

auto main() -> int {
  auto cam = Camera::GetDefault();
  auto ui = Ui{};
  auto detector = Detector{};
  cam.StartAcquisition();
  constexpr auto kNumImages = 1000;
#pragma unroll 20
  for (int i = 0; i < kNumImages; i++) {
    auto image = cam.GetNextImageOcvMat();
    auto results = detector.Detect(image);
    ui.ShowResult(std::move(image), results);
    auto const kPressedKey{cv::waitKey(1)};
    if (static_cast<unsigned char>(kPressedKey) == '\e') {
      break;
    }
  }
  cam.StopAcquisition();
  cam.Close();
  return 0;
}
