#ifndef CURVES_THREADS_SUMMATOR_HPP
#define CURVES_THREADS_SUMMATOR_HPP

#include <curves/Circle.hpp>
#include <vector>
#include <memory>

namespace curves::summators {
[[nodiscard]] float sumThreads(
    const std::vector<std::shared_ptr<curves::ICurve>>& container) noexcept;
}

#endif  // CURVES_THREADS_SUMMATOR_HPP
