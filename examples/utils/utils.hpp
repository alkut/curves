#ifndef CURVES_UTILS_HPP
#define CURVES_UTILS_HPP

#include "curves/Circle.hpp"
#include <vector>
#include <memory>

namespace curves::utils {

[[nodiscard]] bool isCircle(
    const std::shared_ptr<curves::ICurve>& ptr) noexcept;

[[nodiscard]] float getRadius(const std::shared_ptr<curves::ICurve>& ptr);

}  // namespace curves::utils

#endif  // CURVES_UTILS_HPP
