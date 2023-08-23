#ifndef CURVES_GENERATOR_H
#define CURVES_GENERATOR_H

#include "curves/Circle.h"
#include "curves/Ellipse.h"
#include "curves/Helix.h"

#include <random>
#include <limits>

std::shared_ptr<curves::ICurve> generate();

std::shared_ptr<curves::ICurve> generateCircle();
std::shared_ptr<curves::ICurve> generateEllipse();
std::shared_ptr<curves::ICurve> generateHelix();

#endif  // CURVES_GENERATOR_H
