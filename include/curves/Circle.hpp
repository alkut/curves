#ifndef CURVES_CIRCLE_HPP
#define CURVES_CIRCLE_HPP

#include "curves/ICurve.hpp"

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
   * @param radius radius of circle
   * @param center center in oxy plane coordinates
   * @return shared_ptr if success
   * @throws std::invalid_argument if validation fails
   */
  static std::shared_ptr<ICurve> construct(float radius,
                                           point2D<float> center = {0, 0});

      [[nodiscard]] point3D<float> Position(float time) const noexcept override;
      [[nodiscard]] vector3D<float> Derivative(
          float time) const noexcept override;
      [[nodiscard]] float GetRadius() const noexcept;

      ~Circle() override = default;

  private:
  Circle(float radius, point2D<float> center);
  static void Validate(float radius);

  point2D<float> center_;
  float radius_;
};
}  // namespace curves

#endif  // CURVES_CIRCLE_HPP
