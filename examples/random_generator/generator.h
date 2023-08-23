#ifndef CURVES_GENERATOR_H
#define CURVES_GENERATOR_H

#include "curves/Circle.h"
#include "curves/Ellipse.h"
#include "curves/Helix.h"

#include <random>
#include <limits>
#include <vector>

namespace curves::generator {
std::shared_ptr<curves::ICurve> generate();
std::vector<std::shared_ptr<curves::ICurve>> generateCircles(std::size_t count);

std::shared_ptr<curves::ICurve> generateCircle();
std::shared_ptr<curves::ICurve> generateEllipse();
std::shared_ptr<curves::ICurve> generateHelix();
}  // namespace curves::generator

#endif  // CURVES_GENERATOR_H
