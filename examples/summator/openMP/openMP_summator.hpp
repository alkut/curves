#ifndef CURVES_OPENMP_SUMMATOR_HPP
#define CURVES_OPENMP_SUMMATOR_HPP

#include <curves/Circle.hpp>
#include <vector>

namespace curves::summators {

float sumOpenMP(const std::vector<std::shared_ptr<curves::ICurve>>& container);

}

#endif  // CURVES_OPENMP_SUMMATOR_HPP
