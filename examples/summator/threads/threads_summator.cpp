#include "theads_summator.h"

#include <thread>
#include <span>
#include <numeric>

float sumThreads(
    const std::vector<std::shared_ptr<curves::ICurve>>& container) {
  const auto threadCount = std::thread::hardware_concurrency();
  std::vector<float> sumsOfRadii(threadCount, 0.f);
  std::vector<std::span<std::shared_ptr<curves::ICurve>>> spans(threadCount);

  for (std::size_t i = 0; i < threadCount; ++i) {
    sumsOfRadii[i] = 0.f;
  }
  return std::accumulate(sumsOfRadii.cbegin(), sumsOfRadii.cend(), 0.f);
}
