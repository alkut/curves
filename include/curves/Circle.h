#ifndef CURVES_CIRCLE_H
#define CURVES_CIRCLE_H

#include "curves/ICurve.h"

#include <memory>

namespace curves {
/**
 * @brief defined by {posX, posY} and radius : <br>
 * x(t) = posX + R * cos(t) <br>
 * y(t) = posY + R * sin(t) <br>
 */
class Circle final : public ICurve {
  public:
  /**
   *
   * @return shared_ptr if success
   * @throws std::invalid_argument if validation fails
   */
      static std::shared_ptr<Circle> construct(
          point2D<float> planeXYCenterPosition, float radius);

  point3D<float> Position(float time) const noexcept override;
  vector3D<float> Derivative(float time) const noexcept override;
  float GetRadius() const noexcept;

  ~Circle() override = default;

  private:
  Circle(point2D<float> planeXYPosition, float radius);
  static void Validate(float radius);

  point2D<float> position_;
  float radius_;
};
}  // namespace curves

#endif  // CURVES_CIRCLE_H
