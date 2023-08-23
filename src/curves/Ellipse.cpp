#include "curves/Ellipse.h"

#include <cmath>
#include <limits>
#include <stdexcept>
#include <utility>

namespace curves {

std::shared_ptr<Ellipse> Ellipse::construct(
    point2D<float> planeXYCenterPosition, float radiusX, float radiusY) {
  Validate(radiusX, radiusY);
  return std::shared_ptr<Ellipse>(
      new Ellipse(planeXYCenterPosition, radiusX, radiusY));
}

point3D<float> Ellipse::Position(float time) const noexcept {
  return {position_[0] + radiusX_ * std::cos(time),
          position_[1] + radiusY_ * std::sin(time), 0.f};
}

vector3D<float> Ellipse::Derivative(float time) const noexcept {
  return {-radiusX_ * std::sin(time), radiusY_ * std::cos(time), 0.f};
}

Ellipse::Ellipse(point2D<float> planeXYPosition, float radiusX, float radiusY)
    : position_(planeXYPosition),
      radiusX_(radiusX),
      radiusY_(radiusY) {}

void Ellipse::Validate(float radiusX, float radiusY) {
  if (std::min(radiusX, radiusY) <= std::numeric_limits<float>::epsilon()) {
    throw std::invalid_argument("radius is negative");
  }
}

}  // namespace curves
