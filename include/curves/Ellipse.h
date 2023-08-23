#ifndef CURVES_ELLIPSE_H
#define CURVES_ELLIPSE_H

#include "curves/ICurve.h"

#include <memory>

namespace curves {
/**
 * @brief defined by {posX, posY} and radiusX, radiusY : <br>
 * x(t) = posX + radiusX * cos(t) <br>
 * y(t) = posY + radiusY * sin(t) <br>
 */
class Ellipse final : public ICurve {
  public:
  /**
   *
   * @return shared_ptr if success
   * @throws std::invalid_argument if validation fails
   */
      static std::shared_ptr<ICurve> construct(
          point2D<float> planeXYCenterPosition, float radiusX, float radiusY);

  point3D<float> Position(float time) const noexcept override;
  vector3D<float> Derivative(float time) const noexcept override;

  ~Ellipse() override = default;

  private:
  Ellipse(point2D<float> planeXYPosition, float radiusX, float radiusY);
  static void Validate(float radiusX, float radiusY);

  point2D<float> position_;
  float radiusX_;
  float radiusY_;
};
}  // namespace curves

#endif  // CURVES_ELLIPSE_H
