#include "execution_policy_summator.hpp"
#include "../../utils/utils.hpp"

#include <algorithm>
#include <execution>
#include <numeric>

namespace curves::summators {

float sumPolicy(const std::vector<std::shared_ptr<curves::ICurve>>& container) {
  std::vector<float> radii(container.size());
#ifdef __GNUC__
  std::transform(container.cbegin(), container.cend(), radii.begin(),
                 curves::utils::getRadius);
  return std::reduce(radii.cbegin(), radii.cend());
#else
  std::transform(std::execution::unsequenced_policy(), container.cbegin(),
                 container.cend(), radii.begin(), curves::utils::getRadius);
  return std::reduce(std::execution::unsequenced_policy(), radii.cbegin(),
                     radii.cend());
#endif
}
}  // namespace curves::summators
