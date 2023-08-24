#ifndef CURVES_OPENMP_SUMMATOR_HPP
#define CURVES_OPENMP_SUMMATOR_HPP

#include <curves/Circle.hpp>
#include <vector>
#include <memory>

namespace curves::summators {
[[nodiscard]] float sumOpenMP(
    const std::vector<std::shared_ptr<curves::ICurve>>& container) noexcept;
}

#endif  // CURVES_OPENMP_SUMMATOR_HPP
