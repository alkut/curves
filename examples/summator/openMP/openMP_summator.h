#ifndef CURVES_OPENMP_SUMMATOR_H
#define CURVES_OPENMP_SUMMATOR_H

#include <curves/Circle.h>
#include <vector>

namespace curves::summators {

float sumOpenMP(const std::vector<std::shared_ptr<curves::ICurve>>& container);

}

#endif  // CURVES_OPENMP_SUMMATOR_H
