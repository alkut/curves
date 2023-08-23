#ifndef CURVES_POINT_H
#define CURVES_POINT_H

#include "Point-forward.h"

namespace curves {

    template<std::size_t dimension, std::floating_point T>
    constexpr Vector<dimension, T> Vector<dimension, T>::operator * (T scalar) const noexcept {
        Vector<dimension, T> res = *this;
        res *= scalar;
        return res;
    }

    template<std::size_t dimension, std::floating_point T>
    constexpr Vector<dimension, T> &Vector<dimension, T>::operator*=(T scalar) noexcept {
        for (std::size_t i = 0; i < dimension; ++i) {
            (*this)[i] *= scalar;
        }
        return *this;
    }

    template<std::size_t dimension, std::floating_point T>
    constexpr Vector<dimension, T> &Vector<dimension, T>::operator-=(const Vector<dimension, T> &rhs) noexcept {
        for (std::size_t i = 0; i < dimension; ++i) {
            (*this)[i] -= rhs[i];
        }
        return *this;
    }

    template<std::size_t dimension, std::floating_point T>
    constexpr Vector<dimension, T> &Vector<dimension, T>::operator+=(const Vector<dimension, T> &rhs) noexcept {
        for (std::size_t i = 0; i < dimension; ++i) {
            (*this)[i] += rhs[i];
        }
        return *this;
    }

    template<std::size_t dimension, std::floating_point T>
    constexpr Vector<dimension, T> Vector<dimension, T>::operator-(const Vector<dimension, T> &rhs) const noexcept {
        Vector<dimension, T> res = *this;
        res -= rhs;
        return res;
    }

    template<std::size_t dimension, std::floating_point T>
    constexpr Vector<dimension, T> Vector<dimension, T>::operator+(const Vector<dimension, T> &rhs) const noexcept {
        Vector<dimension, T> res = *this;
        res += rhs;
        return res;
    }

    template<std::size_t dimension, std::floating_point T>
    constexpr Point<dimension, T> Vector<dimension, T>::operator+(const Point<dimension, T> &rhs) const noexcept {
        Point<dimension, T> res;
        for (std::size_t i = 0; i < dimension; ++i) {
            res[i] = (*this)[i] + rhs[i];
        }
        return res;
    }

    template <std::size_t dimension, std::floating_point T>
    constexpr Point<dimension, T>& Point<dimension, T>::operator-=(
        const Vector<dimension, T>& rhs) noexcept {
        for (std::size_t i = 0; i < dimension; ++i) {
            *this[i] -= rhs[i];
        }
        return *this;
    }
    template <std::size_t dimension, std::floating_point T>
    constexpr Point<dimension, T>& Point<dimension, T>::operator+=(
        const Vector<dimension, T>& rhs) noexcept {
        for (std::size_t i = 0; i < dimension; ++i) {
            *this[i] += rhs[i];
        }
        return *this;
    }
    template <std::size_t dimension, std::floating_point T>
    constexpr Point<dimension, T> Point<dimension, T>::operator-(
        const Vector<dimension, T>& rhs) const noexcept {
        Point<dimension, T> res = *this;
        res -= rhs;
        return res;
    }
    template <std::size_t dimension, std::floating_point T>
    constexpr Point<dimension, T> Point<dimension, T>::operator+(
        const Vector<dimension, T>& rhs) const noexcept {
        Point<dimension, T> res = *this;
        res += rhs;
        return res;
    }
    template <std::size_t dimension, std::floating_point T>
    constexpr Vector<dimension, T> Point<dimension, T>::operator-(
        const Point<dimension, T>& rhs) const noexcept {
        Vector<dimension, T> res;
        for (std::size_t i = 0; i < dimension; ++i) {
            res[i] = *this[i] - rhs[i];
        }
        return res;
    }
    }  // namespace curves

#endif //CURVES_POINT_H
