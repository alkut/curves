#ifndef CURVES_UTILS_HPP
#define CURVES_UTILS_HPP

#include "curves/Circle.hpp"
#include <vector>

namespace curves::utils {

bool isCircle(const std::shared_ptr<curves::ICurve>& ptr) noexcept;

float getRadius(const std::shared_ptr<curves::ICurve>& ptr);

}  // namespace curves::utils

#endif  // CURVES_UTILS_HPP
