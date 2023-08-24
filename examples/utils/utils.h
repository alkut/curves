#ifndef CURVES_UTILS_H
#define CURVES_UTILS_H

#include "curves/Circle.h"
#include <vector>

namespace curves::utils {

bool isActuallyCircle(const std::shared_ptr<curves::ICurve>& ptr);

float getRadius(const std::shared_ptr<curves::ICurve>& ptr);

}  // namespace curves::utils

#endif  // CURVES_UTILS_H
