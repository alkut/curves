#include "curves/Circle.h"

#include <cmath>
#include <limits>
#include <stdexcept>

namespace curves {

std::shared_ptr<ICurve> Circle::construct(float radius, point2D<float> center) {
  Validate(radius);
  return std::shared_ptr<ICurve>(new Circle(radius, center));
}

point3D<float> Circle::Position(float time) const noexcept {
  return {center_[0] + radius_ * std::cos(time),
          center_[1] + radius_ * std::sin(time), 0.f};
}

vector3D<float> Circle::Derivative(float time) const noexcept {
  return {-radius_ * std::sin(time), radius_ * std::cos(time), 0.f};
}

Circle::Circle(float radius, point2D<float> center)
    : center_(center),
      radius_(radius) {}

void Circle::Validate(float radius) {
  if (radius <= std::numeric_limits<float>::epsilon()) {
    throw std::invalid_argument("radius is negative");
  }
}
float Circle::GetRadius() const noexcept {
  return radius_;
}

}  // namespace curves
