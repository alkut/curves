#include "curves/Ellipse.hpp"

#include <cmath>
#include <limits>
#include <stdexcept>
#include <utility>

namespace curves {

std::shared_ptr<ICurve> Ellipse::construct(float radiusX, float radiusY,
                                           point2D<float> center) {
  Validate(radiusX, radiusY);
  return std::shared_ptr<ICurve>(new Ellipse(radiusX, radiusY, center));
}

point3D<float> Ellipse::Position(float time) const noexcept {
  return {center_[0] + radiusX_ * std::cos(time),
          center_[1] + radiusY_ * std::sin(time), 0.f};
}

vector3D<float> Ellipse::Derivative(float time) const noexcept {
  return {-radiusX_ * std::sin(time), radiusY_ * std::cos(time), 0.f};
}

Ellipse::Ellipse(float radiusX, float radiusY, point2D<float> center)
    : center_(center),
      radiusX_(radiusX),
      radiusY_(radiusY) {}

void Ellipse::Validate(float radiusX, float radiusY) {
  if (std::min(radiusX, radiusY) <= std::numeric_limits<float>::epsilon()) {
    throw std::invalid_argument("radius is negative");
  }
}

}  // namespace curves
