#ifndef CURVES_POINT_H
#define CURVES_POINT_H

#include "Point-forward.h"

namespace curves {
    template<size_t dimension, std::floating_point T>
    constexpr Vector<dimension, T> Vector<dimension, T>::operator * (T scalar) const noexcept {
        Vector<dimension, T> res;
        for (size_t i = 0; i < dimension; ++i) {
            res[i] = (*this)[i] * scalar;
        }
        return res;
    }
}

#endif //CURVES_POINT_H
