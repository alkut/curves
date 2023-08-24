#ifndef CURVES_NAIVE_SUMMATOR_H
#define CURVES_NAIVE_SUMMATOR_H

#include <curves/Circle.h>
#include <vector>

namespace curves::summators {

float sumNaive(const std::vector<std::shared_ptr<curves::ICurve>>& container);

}

#endif  // CURVES_NAIVE_SUMMATOR_H
