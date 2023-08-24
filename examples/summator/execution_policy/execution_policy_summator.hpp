#ifndef CURVES_EXECUTION_POLICY_SUMMATOR_HPP
#define CURVES_EXECUTION_POLICY_SUMMATOR_HPP

#include <curves/Circle.hpp>
#include <vector>

namespace curves::summators {
float sumPolicy(const std::vector<std::shared_ptr<curves::ICurve>>& container);
}

#endif  // CURVES_EXECUTION_POLICY_SUMMATOR_HPP
