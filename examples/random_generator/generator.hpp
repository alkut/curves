#ifndef CURVES_GENERATOR_HPP
#define CURVES_GENERATOR_HPP

#include "curves/Circle.hpp"
#include "curves/Ellipse.hpp"
#include "curves/Helix.hpp"

#include <random>
#include <limits>
#include <vector>

namespace curves::generator {
[[nodiscard]] std::shared_ptr<curves::ICurve> generate() noexcept;
[[nodiscard]] std::vector<std::shared_ptr<curves::ICurve>> generateCircles(
    std::size_t count) noexcept;

[[nodiscard]] std::shared_ptr<curves::ICurve> generateCircle() noexcept;
[[nodiscard]] std::shared_ptr<curves::ICurve> generateEllipse() noexcept;
[[nodiscard]] std::shared_ptr<curves::ICurve> generateHelix() noexcept;
}  // namespace curves::generator

#endif  // CURVES_GENERATOR_HPP
