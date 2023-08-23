#include "curves/Circle.h"

#include <cmath>
#include <limits>
#include <stdexcept>

namespace curves {

std::shared_ptr<Circle> Circle::construct(point2D<float> planeXYPosition,
                                          float radius) {
  Validate(radius);
  return std::shared_ptr<Circle>(new Circle(planeXYPosition, radius));
}

point3D<float> Circle::Position(float time) const noexcept {
  return {position_[0] + radius_ * std::cos(time) + radius_ * std::sin(time),
          position_[1] - radius_ * std::sin(time) + radius_ * std::cos(time),
          0.f};
}

vector3D<float> Circle::Derivative(float time) const noexcept {
  return {radius_ * std::cos(time) - radius_ * std::sin(time),
          -radius_ * std::sin(time) - radius_ * std::cos(time), 0.f};
}

Circle::Circle(point2D<float> planeXYPosition, float radius)
    : position_(planeXYPosition),
      radius_(radius) {}

void Circle::Validate(float radius) {
  if (std::fabs(radius) <= std::numeric_limits<float>::epsilon()) {
    throw std::invalid_argument("radius_ is negative");
  }
}

}  // namespace curves
