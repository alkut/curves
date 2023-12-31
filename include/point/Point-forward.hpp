#ifndef CURVES_POINT_FORWARD_HPP
#define CURVES_POINT_FORWARD_HPP

#include <array>
#include <concepts>
#include <iostream>

namespace curves {

template <std::size_t dimension, std::floating_point T>
struct Point;

template<std::size_t dimension, std::floating_point T>
    struct Vector;

    template<std::floating_point T>
    using point2D [[maybe_unused]] = Point<2, T>;

template<std::floating_point T>
    using point3D [[maybe_unused]] = Point<3, T>;

    template<std::floating_point T>
    using vector2D [[maybe_unused]] = Vector<2, T>;

template<std::floating_point T>
    using vector3D [[maybe_unused]] = Vector<3, T>;

    template <std::size_t dimension, std::floating_point T>
    struct Vector : public std::array<T, dimension> {
  [[nodiscard]] constexpr Vector<dimension, T> operator*(
          T scalar) const noexcept;

      constexpr Vector<dimension, T>& operator *= (T scalar) noexcept;

  [[nodiscard]] constexpr Point<dimension, T> operator+(
          const Point<dimension, T>& rhs) const noexcept;

      [[nodiscard]] constexpr Vector<dimension, T> operator+(
          const Vector<dimension, T>& rhs) const noexcept;

  [[nodiscard]] constexpr Vector<dimension, T> operator-(
          const Vector<dimension, T>& rhs) const noexcept;

      constexpr Vector<dimension, T>& operator+=(
          const Vector<dimension, T>& rhs) noexcept;

      constexpr Vector<dimension, T>& operator-=(
          const Vector<dimension, T>& rhs) noexcept;

      template <std::size_t size, typename U>
      friend std::ostream& operator<<(std::ostream& out,
                                      const Vector<size, U>& vector);
    };

    template <std::size_t dimension, std::floating_point T>
    struct Point : public std::array<T, dimension> {
      [[nodiscard]] constexpr Vector<dimension, T> operator-(
            const Point<dimension, T>& rhs) const noexcept;

      [[nodiscard]] constexpr Point<dimension, T> operator+(
            const Vector<dimension, T>& rhs) const noexcept;

      [[nodiscard]] constexpr Point<dimension, T> operator-(
            const Vector<dimension, T>& rhs) const noexcept;

      constexpr Point<dimension, T>& operator+=(
          const Vector<dimension, T>& rhs) noexcept;

      constexpr Point<dimension, T>& operator-=(
          const Vector<dimension, T>& rhs) noexcept;

      template <std::size_t size, typename U>
        friend std::ostream& operator<<(std::ostream& out,
                                        const Point<size, U>& vector);
    };
    }  // namespace curves

#endif  // CURVES_POINT_FORWARD_HPP
