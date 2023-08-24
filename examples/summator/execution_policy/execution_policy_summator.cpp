#include "execution_policy_summator.h"

#include <algorithm>
#include <execution>
#include <numeric>

inline float getRadius(const std::shared_ptr<curves::ICurve>& ptr) {
  return dynamic_cast<curves::Circle*>(ptr.get())->GetRadius();
}

float sumPolicy(const std::vector<std::shared_ptr<curves::ICurve>>& container) {
  std::vector<float> radii(container.size());
  std::transform(std::execution::unsequenced_policy(), container.cbegin(),
                 container.cend(), radii.begin(), getRadius);
  return std::reduce(std::execution::unsequenced_policy(), radii.cbegin(),
                     radii.cend());
}
