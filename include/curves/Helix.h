#ifndef CURVES_HELIX_H
#define CURVES_HELIX_H

#include "curves/ICurve.h"

#include <memory>

namespace curves {
/**
 * @brief defined by {posX, posY} and radius and step : <br>
 * x(t) = posX + radius * cos(t) <br>
 * y(t) = posY + radius * sin(t) <br>
 * z(t) = step * t / (2 * PI) <br>
 */
class Helix final : public ICurve {
  public:
  /**
   *
   * @return shared_ptr if success
   * @throws std::invalid_argument if validation fails
   */
  static std::shared_ptr<Helix> construct(point2D<float> planeXYCenterPosition,
                                          float radius, float step);

  point3D<float> Position(float time) const noexcept override;
  vector3D<float> Derivative(float time) const noexcept override;

  ~Helix() override = default;

  private:
  Helix(point2D<float> planeXYPosition, float radius, float step);
  static void Validate(float radius);

  point2D<float> position_;
  float radius_;
  float step_;
};
}  // namespace curves

#endif  // CURVES_HELIX_H
