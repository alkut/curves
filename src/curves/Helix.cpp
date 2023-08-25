#include "curves/Helix.hpp"

#include <cmath>
#include <limits>
#include <numbers>
#include <stdexcept>

namespace curves {

std::shared_ptr<ICurve> Helix::construct(float radius, float step,
                                         point2D<float> center) {
  Validate(radius);
  return std::shared_ptr<ICurve>(new Helix(radius, step, center));
}

point3D<float> Helix::Position(float time) const noexcept {
  return {center_[0] + radius_ * std::cos(time),
          center_[1] + radius_ * std::sin(time), step_ * time / (2.f * PI)};
}

vector3D<float> Helix::Derivative(float time) const noexcept {
  return {-radius_ * std::sin(time), radius_ * std::cos(time),
          step_ / (2.f * PI)};
}

Helix::Helix(float radius, float step, point2D<float> center)
    : center_(center),
      radius_(radius),
      step_(step) {}

void Helix::Validate(float radius) {
  if (radius <= std::numeric_limits<float>::epsilon()) {
    throw std::invalid_argument("radius is negative");
  }
}

}  // namespace curves
