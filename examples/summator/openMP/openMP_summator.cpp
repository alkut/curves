#include "openMP_summator.h"

float sumOpenMP(const std::vector<std::shared_ptr<curves::ICurve>>& container) {
  float sumOfRadii = 0.f;
#pragma omp parallel for reduction(+ : sum)
  for (const auto& circle : container) {
    sumOfRadii += dynamic_cast<curves::Circle*>(circle.get())->GetRadius();
  }
  return sumOfRadii;
}
