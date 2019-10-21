#pragma once
#include <types.h>
#include <util/simd.h>
#include <iostream>
#include <cmath>

namespace spruce {
	struct alignas(alignof(simd::reg2d)) vec2d {
		double x = 0;
		double y = 0;

		vec2d() = default;
		vec2d(double scalar);
		vec2d(double x, double y);
		vec2d(const vec2d&) = default;
		vec2d(vec2d&&) noexcept = default;
		~vec2d() = default;

		vec2d& set(double scalar) noexcept;
		vec2d& set(double x, double y) noexcept;

		[[nodiscard]] double mag2() const noexcept;
		[[nodiscard]] double mag() const noexcept;
		vec2d& nor() noexcept;
		[[nodiscard]] double dst2(const vec2d& vector) const noexcept;
		[[nodiscard]] double dst(const vec2d& vector) const noexcept;
		[[nodiscard]] double dot(const vec2d& vector) const noexcept;

		vec2d& add(const vec2d& vector) noexcept;
		vec2d& sub(const vec2d& vector) noexcept;

		vec2d& add(double value) noexcept;
		vec2d& sub(double value) noexcept;
		vec2d& scl(double value) noexcept;
		vec2d& div(double value) noexcept;

		[[nodiscard]] bool operator==(const vec2d& vector) const noexcept;
		[[nodiscard]] bool operator!=(const vec2d& vector) const noexcept;

		vec2d& operator+=(const vec2d& vector) noexcept;
		vec2d& operator-=(const vec2d& vector) noexcept;

		vec2d& operator+=(double value) noexcept;
		vec2d& operator-=(double value) noexcept;
		vec2d& operator*=(double value) noexcept;
		vec2d& operator/=(double value) noexcept;

		vec2d& operator=(const vec2d&) = default;
		vec2d& operator=(vec2d&&) noexcept = default;

		[[nodiscard]] static vec2d lerp(const vec2d& a, const vec2d& b, double alpha) noexcept;
	};

	inline vec2d operator+(const vec2d& left, const vec2d& right) noexcept;
	inline vec2d operator-(const vec2d& left, const vec2d& right) noexcept;

	inline vec2d operator+(const vec2d& left, double value) noexcept;
	inline vec2d operator-(const vec2d& left, double value) noexcept;
	inline vec2d operator*(const vec2d& left, double value) noexcept;
	inline vec2d operator/(const vec2d& left, double value) noexcept;

	std::ostream& operator<<(std::ostream& stream, const vec2d& vector);
}

#include <math/vec/vec2dImpl.h>
