#ifndef CURVES_HELIX_HPP
#define CURVES_HELIX_HPP

#include "curves/ICurve.hpp"

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
   * @param radius radius
   * @param step period: C(t + 2 * PI) = C(t) + {0, 0, step}
   * @param center center in oxy plane coordinates
   * @return shared_ptr if success
   * @throws std::invalid_argument if validation fails
   */
  static std::shared_ptr<ICurve> construct(float radius, float step,
                                           point2D<float> center = {0, 0});

      [[nodiscard]] point3D<float> Position(float time) const noexcept override;
      [[nodiscard]] vector3D<float> Derivative(
          float time) const noexcept override;

      ~Helix() override = default;

  private:
  Helix(float radius, float step, point2D<float> center);
  static void Validate(float radius);

  point2D<float> center_;
  float radius_;
  float step_;
};
}  // namespace curves

#endif  // CURVES_HELIX_HPP
