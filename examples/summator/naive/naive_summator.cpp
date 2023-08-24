#include "examples/summator/naive/naive_summator.hpp"
#include "examples/utils/utils.hpp"

#include <ranges>
#include <algorithm>

namespace curves::summators {

float sumNaive(
    const std::vector<std::shared_ptr<curves::ICurve>>& container) noexcept {
  float sumOfRadii = 0.f;
  for (auto radius :
       container | std::ranges::views::transform(curves::utils::getRadius)) {
    sumOfRadii += radius;
  }
  return sumOfRadii;
}

}  // namespace curves::summators
