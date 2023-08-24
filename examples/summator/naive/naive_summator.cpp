#include "naive_summator.h"
#include "../../utils/utils.h"

#include <ranges>

namespace curves::summators {

float sumNaive(const std::vector<std::shared_ptr<curves::ICurve>>& container) {
  float sumOfRadii = 0.f;
  for (auto radius :
       container | std::ranges::views::transform(curves::utils::getRadius)) {
    sumOfRadii += radius;
  }
  return sumOfRadii;
}

}  // namespace curves::summators
