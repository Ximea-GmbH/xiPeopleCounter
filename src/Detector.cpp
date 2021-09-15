//
// Created by alex on 14.09.21.
//

#include "Detector.h"
#include <vector>

auto Detector::Detect(const cv::_InputArray &input_image) -> DetectionResult {
  cv::cuda::GpuMat const kImageGpu{input_image};
  std::vector<cv::Rect> detections{};
  histogram_oriented_gradient_->detectMultiScale(kImageGpu, detections);
  return DetectionResult{detections.size()};

}

Detector::Detector() : histogram_oriented_gradient_(cv::cuda::HOG::create()) {
  histogram_oriented_gradient_->setSVMDetector(histogram_oriented_gradient_->getDefaultPeopleDetector());
}
