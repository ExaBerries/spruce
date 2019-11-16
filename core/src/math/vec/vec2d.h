#pragma once
#include <types.h>
#include <math/functions.h>
#include <util/simd.h>
#include <iostream>
#include <type_traits>

namespace spruce {
	struct alignas(alignof(simd::reg2d)) vec2d {
		double x = 0;
		double y = 0;

		vec2d() = default;
		constexpr vec2d(double scalar) noexcept;
		constexpr vec2d(double x, double y) noexcept;
		vec2d(const vec2d&) = default;
		vec2d(vec2d&&) noexcept = default;
		~vec2d() = default;

		constexpr vec2d& set(double scalar) noexcept;
		constexpr vec2d& set(double x, double y) noexcept;

		[[nodiscard]] constexpr double mag2() const noexcept;
		[[nodiscard]] constexpr double mag() const noexcept;
		constexpr vec2d& nor() noexcept;
		[[nodiscard]] constexpr double dst2(const vec2d& vector) const noexcept;
		[[nodiscard]] constexpr double dst(const vec2d& vector) const noexcept;
		[[nodiscard]] constexpr double dot(const vec2d& vector) const noexcept;

		constexpr vec2d& add(const vec2d& vector) noexcept;
		constexpr vec2d& sub(const vec2d& vector) noexcept;

		constexpr vec2d& add(double value) noexcept;
		constexpr vec2d& sub(double value) noexcept;
		constexpr vec2d& scl(double value) noexcept;
		constexpr vec2d& div(double value) noexcept;

		[[nodiscard]] constexpr bool operator==(const vec2d& vector) const noexcept;
		[[nodiscard]] constexpr bool operator!=(const vec2d& vector) const noexcept;

		constexpr vec2d& operator+=(const vec2d& vector) noexcept;
		constexpr vec2d& operator-=(const vec2d& vector) noexcept;

		constexpr vec2d& operator+=(double value) noexcept;
		constexpr vec2d& operator-=(double value) noexcept;
		constexpr vec2d& operator*=(double value) noexcept;
		constexpr vec2d& operator/=(double value) noexcept;

		vec2d& operator=(const vec2d&) = default;
		vec2d& operator=(vec2d&&) noexcept = default;

		[[nodiscard]] constexpr static vec2d lerp(const vec2d& a, const vec2d& b, double alpha) noexcept;
	};

	constexpr vec2d operator+(const vec2d& left, const vec2d& right) noexcept;
	constexpr vec2d operator-(const vec2d& left, const vec2d& right) noexcept;

	constexpr vec2d operator+(const vec2d& left, double value) noexcept;
	constexpr vec2d operator-(const vec2d& left, double value) noexcept;
	constexpr vec2d operator*(const vec2d& left, double value) noexcept;
	constexpr vec2d operator/(const vec2d& left, double value) noexcept;

	std::ostream& operator<<(std::ostream& stream, const vec2d& vector);
}

#include <math/vec/vec2dImpl.h>
