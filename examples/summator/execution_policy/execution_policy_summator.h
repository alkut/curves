#ifndef CURVES_EXECUTION_POLICY_SUMMATOR_H
#define CURVES_EXECUTION_POLICY_SUMMATOR_H

#include <curves/Circle.h>
#include <vector>

namespace curves::summators {
float sumPolicy(const std::vector<std::shared_ptr<curves::ICurve>>& container);
}

#endif  // CURVES_EXECUTION_POLICY_SUMMATOR_H
