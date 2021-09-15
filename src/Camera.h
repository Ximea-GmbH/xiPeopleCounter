//
// Created by alex on 25.08.21.
//
#ifndef XIPEOPLECOUNTER_SRC_CAMERA_H_
#define XIPEOPLECOUNTER_SRC_CAMERA_H_

#include "../xiApiPlusOcv/xiApiPlusOcv.hpp"

class Camera : public xiAPIplusCameraOcv {
 public:
  static auto GetDefault() -> Camera;

 private:
  Camera() = default;

};

#endif
