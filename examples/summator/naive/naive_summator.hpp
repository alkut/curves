#ifndef CURVES_NAIVE_SUMMATOR_HPP
#define CURVES_NAIVE_SUMMATOR_HPP

#include <curves/Circle.hpp>
#include <vector>
#include <memory>

namespace curves::summators {
[[nodiscard]] float sumNaive(
    const std::vector<std::shared_ptr<curves::ICurve>>& container) noexcept;
}

#endif  // CURVES_NAIVE_SUMMATOR_HPP
