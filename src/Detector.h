//
// Created by alex on 14.09.21.
//

#ifndef XIPEOPLECOUNTER_SRC_DETECTOR_H_
#define XIPEOPLECOUNTER_SRC_DETECTOR_H_

#include "DetectionResult.h"
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudaobjdetect.hpp>

class Detector {
 public:
  Detector();

  auto Detect(cv::InputArray input_image) -> DetectionResult;

 private:
  cv::Ptr<cv::cuda::HOG> const histogram_oriented_gradient_;
};

#endif
