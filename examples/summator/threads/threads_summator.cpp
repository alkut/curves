#include "examples/summator/threads/threads_summator.hpp"
#include "examples/utils/utils.hpp"

#include <thread>
#include <span>
#include <numeric>
#include <ranges>
#include <algorithm>

namespace curves::summators {

float sumThreads(
    const std::vector<std::shared_ptr<curves::ICurve>>& container) noexcept {
  const auto threadCount = std::thread::hardware_concurrency();
  if (threadCount == 1 || container.size() < threadCount) {
    float ans = 0.f;
    for (auto radius :
         container | std::ranges::views::transform(curves::utils::getRadius)) {
      ans += radius;
    }
    return ans;
  }
  std::vector<float> sumsOfRadii(threadCount);
  std::vector<std::thread> threads(threadCount - 1);

  const std::size_t partition_size =
      (container.size() + threadCount - 1) / threadCount;

  for (std::size_t i = 0; i < threadCount - 1; ++i) {
    sumsOfRadii[i] = 0.f;
    threads[i]     = std::thread(
        [&sum = sumsOfRadii[i],
         span = std::span(container.cbegin() + i * partition_size,
             container.cbegin() + (i + 1) * partition_size)]() mutable -> void {
          for (auto radius :
               span | std::ranges::views::transform(curves::utils::getRadius)) {
            sum += radius;
          }
        });
  }

  sumsOfRadii.back() = 0.f;
  for (auto radius :
       container |
           std::ranges::views::drop((threadCount - 1) * partition_size) |
           std::ranges::views::transform(curves::utils::getRadius)) {
    sumsOfRadii.back() += radius;
  }

  for (auto& thread : threads) {
    thread.join();
  }
  return std::reduce(sumsOfRadii.cbegin(), sumsOfRadii.cend());
}

}  // namespace curves::summators
