//
// Created by alex on 25.08.21.
//

#include "Ui.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <utility>

Ui::Ui(std::string name) : window_name_(std::move(name)) {
  cv::namedWindow(window_name_, cv::WINDOW_OPENGL | cv::WINDOW_AUTOSIZE);
}

Ui::~Ui() {
  cv::destroyWindow(window_name_);
}

auto Ui::ShowResult(cv::Mat &&image, DetectionResult const &results) -> void {
  constexpr auto kTextX{100};
  constexpr auto kTextY{100};
  constexpr auto kFontScale{1.0};
  constexpr auto kWhite{255.0};
  constexpr auto kThickness{5};
  auto text = std::string("Counted people:") + std::to_string(results.number_people_);
  cv::putText(image, text, cv::Point(kTextX, kTextY), cv::FONT_HERSHEY_DUPLEX, kFontScale, cv::Scalar(kWhite),
              kThickness, cv::LINE_AA);
  for (const auto &rect: results.detected_rects_) {
    cv::rectangle(image, rect, kWhite, kThickness );
  }
  cv::imshow(window_name_, image);
}

auto Ui::operator=(Ui &&other) noexcept -> Ui & {
  this->window_name_ = other.window_name_;
  other.window_name_ = "";
  return *this;
}
