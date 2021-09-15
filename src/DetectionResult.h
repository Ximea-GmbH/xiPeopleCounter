//
// Created by alex on 25.08.21.
//

#ifndef XIPEOPLECOUNTER_SRC_DETECTIONRESULT_H_
#define XIPEOPLECOUNTER_SRC_DETECTIONRESULT_H_

#include <cstdint>
#include <vector>
#include <opencv2/imgproc.hpp>

class DetectionResult {
 public:
  uint64_t const number_people_;
  std::vector<cv::Rect> const detected_rects_;

};

#endif