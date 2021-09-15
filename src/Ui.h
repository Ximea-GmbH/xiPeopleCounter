//
// Created by alex on 25.08.21.
//
#ifndef XIPEOPLECOUNTER_SRC_UI_H_
#define XIPEOPLECOUNTER_SRC_UI_H_

#include<string>
#include <opencv2/core/mat.hpp>
#include "DetectionResult.h"

class Ui {
 public:
  explicit Ui(std::string name = "xiPeopleCounter");

  ~Ui();

  auto ShowResult(cv::Mat &&image, DetectionResult const &results) -> void;

  // Ui may not be copied as it directly refers to a window
  Ui(Ui const &other) = delete;

  auto operator=(Ui const &other) -> Ui & = delete;

  // Moving Ui is trivial
  Ui(Ui &&other) = default;
  auto operator=(Ui &&other) noexcept -> Ui &;

 private:
  std::string window_name_;
};

#endif
