#include "theads_summator.h"

#include <thread>
#include <span>
#include <numeric>
#include <utility>

float sumThreads(
    const std::vector<std::shared_ptr<curves::ICurve>>& container) {
  const auto threadCount = std::thread::hardware_concurrency();
  std::vector<float> sumsOfRadii(threadCount, 0.f);
  std::vector<std::span<std::shared_ptr<curves::ICurve>, 0>> spans(threadCount);

  const std::size_t partition_size = container.size() / threadCount;
  for (std::size_t i = 0; i < threadCount; ++i) {
    sumsOfRadii[i] = 0.f;
    /*
    spans[i] = std::span<std::shared_ptr<curves::ICurve>, 0>
        (container.cbegin() + 2, container.cbegin() + 3);

    spans[i] = std::move((std::span {container}).subspan(i * partition_size,
    std::max(partition_size, container.size() - i * partition_size))); spans[i]
    = {container.begin() + i * partition_size, container.begin() + std::max((i +
    1) * partition_size, container.size())};
                      */
  }
  return std::accumulate(sumsOfRadii.cbegin(), sumsOfRadii.cend(), 0.f);
}
