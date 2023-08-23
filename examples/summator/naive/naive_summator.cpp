#include "naive_summator.h"

float sumNaive(const std::vector<std::shared_ptr<curves::ICurve>>& container) {
  float sumOfRadii = 0.f;
  for (const auto& circle : container) {
    sumOfRadii += dynamic_cast<curves::Circle*>(circle.get())->GetRadius();
  }
  return sumOfRadii;
}
