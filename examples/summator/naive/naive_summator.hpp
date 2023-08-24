#ifndef CURVES_NAIVE_SUMMATOR_HPP
#define CURVES_NAIVE_SUMMATOR_HPP

#include <curves/Circle.hpp>
#include <vector>

namespace curves::summators {

float sumNaive(const std::vector<std::shared_ptr<curves::ICurve>>& container);

}

#endif  // CURVES_NAIVE_SUMMATOR_HPP
