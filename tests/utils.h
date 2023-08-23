#ifndef CURVES_UTILS_H
#define CURVES_UTILS_H

#include "point/Point.h"

#include <cmath>
#include <limits>

#include <gtest/gtest.h>

template<std::size_t dimension, std::floating_point T>
void VerifyEqual(const curves::Vector<dimension, T>& lhs, const curves::Vector<dimension, T>& rhs) {
    for (std::size_t i = 0; i < dimension; ++i) {
        ASSERT_LE(std::fabs(lhs[i] - rhs[i]), std::numeric_limits<T>::epsilon());
    }
}

template <std::size_t dimension, std::floating_point T>
void VerifyEqual(const curves::Point<dimension, T>& lhs,
                 const curves::Point<dimension, T>& rhs) {
    for (std::size_t i = 0; i < dimension; ++i) {
        ASSERT_LE(std::fabs(lhs[i] - rhs[i]),
                  std::numeric_limits<T>::epsilon());
    }
}

#endif //CURVES_UTILS_H
