#ifndef CURVES_UTILS_HPP
#define CURVES_UTILS_HPP

#include "curves/Circle.hpp"
#include <vector>

namespace curves::utils {

bool isActuallyCircle(const std::shared_ptr<curves::ICurve>& ptr);

float getRadius(const std::shared_ptr<curves::ICurve>& ptr);

}  // namespace curves::utils

#endif  // CURVES_UTILS_HPP
