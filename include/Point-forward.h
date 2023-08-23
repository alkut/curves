#ifndef CURVES_POINT_FORWARD_H
#define CURVES_POINT_FORWARD_H

#include <array>
#include <concepts>

namespace curves {
    template<std::size_t dimension, std::floating_point T>
    struct Point;
    template<std::size_t dimension, std::floating_point T>
    struct Vector;

    template<std::floating_point T>
    using point2D = Point<2, T>;
    template<std::floating_point T>
    using point3D = Point<3, T>;
    template<std::floating_point T>
    using vector2D = Vector<2, T>;
    template<std::floating_point T>
    using vector3D = Vector<3, T>;

    template<std::size_t dimension, std::floating_point T>
    struct Vector : public std::array<T, dimension> {
        constexpr Vector<dimension, T> operator * (T scalar) const noexcept;
        constexpr Vector<dimension, T>& operator *= (T scalar) noexcept;
        constexpr Point<dimension, T> operator + (const Point<dimension, T>& rhs) const noexcept;
        constexpr Vector<dimension, T> operator + (const Vector<dimension, T>& rhs) const noexcept;
        constexpr Vector<dimension, T> operator - (const Vector<dimension, T>& rhs) const noexcept;
        constexpr Vector<dimension, T>& operator += (const Vector<dimension, T>& rhs) noexcept;
        constexpr Vector<dimension, T>& operator -= (const Vector<dimension, T>& rhs) noexcept;
    };

    template<std::size_t dimension, std::floating_point T>
    struct Point : public std::array<T, dimension> {
        constexpr Vector<dimension, T> operator - (const Point<dimension, T>& rhs) const noexcept;
        constexpr Point<dimension, T> operator + (const Vector<dimension, T>& rhs) const noexcept;
        constexpr Point<dimension, T> operator - (const Vector<dimension, T>& rhs) const noexcept;
        constexpr Point<dimension, T>& operator += (const Vector<dimension, T>& rhs) noexcept;
        constexpr Point<dimension, T>& operator -= (const Vector<dimension, T>& rhs) noexcept;
    };
}

#endif //CURVES_POINT_FORWARD_H
