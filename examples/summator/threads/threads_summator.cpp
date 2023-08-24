#include "theads_summator.h"

#include <thread>
#include <span>
#include <numeric>
#include <utility>

float sumThreads(
    const std::vector<std::shared_ptr<curves::ICurve>>& container) {
  const auto threadCount = std::thread::hardware_concurrency();
  std::vector<float> sumsOfRadii(threadCount, 0.f);
  std::vector<std::thread> threads(threadCount);

  const std::size_t partition_size =
      (container.size() + threadCount - 1) / threadCount;
  for (std::size_t i = 0; i < threadCount; ++i) {
    sumsOfRadii[i] = 0.f;
    threads[i]     = std::thread(
        [sum  = &sumsOfRadii[i],
         span = std::span(container.cbegin() + i * partition_size,
                              container.cbegin() +
                                  std::min((i + 1) * partition_size,
                                           container.size()))]() mutable -> void {
          for (const auto& circle : span) {
            *sum += dynamic_cast<curves::Circle*>(circle.get())->GetRadius();
          }
        });
  }
  for (std::size_t i = 0; i < threadCount; ++i) {
    threads[i].join();
  }
  return std::accumulate(sumsOfRadii.cbegin(), sumsOfRadii.cend(), 0.f);
}
