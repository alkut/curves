#ifndef CURVES_CURVE_H
#define CURVES_CURVE_H

#include "point/Point.hpp"

namespace curves {
class ICurve {
  public:
  virtual ~ICurve()                                             = default;
  virtual point3D<float> Position(float time) const noexcept = 0;
  virtual vector3D<float> Derivative(float time) const noexcept = 0;
};
}  // namespace curves

#endif  // CURVES_CURVE_H
