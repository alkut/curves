#include "curves/Helix.h"

#include <cmath>
#include <limits>
#include <numbers>
#include <stdexcept>

namespace curves {

std::shared_ptr<Helix> Helix::construct(point2D<float> planeXYCenterPosition,
                                        float radius, float step) {
  Validate(radius);
  return std::shared_ptr<Helix>(new Helix(planeXYCenterPosition, radius, step));
}

point3D<float> Helix::Position(float time) const noexcept {
  return {position_[0] + radius_ * std::cos(time),
          position_[1] + radius_ * std::sin(time),
          step_ * time / (2.f * std::numbers::pi_v<float>)};
}

vector3D<float> Helix::Derivative(float time) const noexcept {
  return {-radius_ * std::sin(time), radius_ * std::cos(time),
          step_ / (2.f * std::numbers::pi_v<float>)};
}

Helix::Helix(point2D<float> planeXYPosition, float radius, float step)
    : position_(planeXYPosition),
      radius_(radius),
      step_(step) {}

void Helix::Validate(float radius) {
  if (radius <= std::numeric_limits<float>::epsilon()) {
    throw std::invalid_argument("radius is negative");
  }
}

}  // namespace curves
