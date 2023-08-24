#include "openMP_summator.h"
#include "../../utils/utils.h"

namespace curves::summators {

float sumOpenMP(const std::vector<std::shared_ptr<curves::ICurve>>& container) {
  float sumOfRadii = 0.f;
#pragma omp parallel for reduction(+ : sum)
  for (const auto& circle : container) {
    sumOfRadii += curves::utils::getRadius(circle);
  }
  return sumOfRadii;
}

}  // namespace curves::summators
