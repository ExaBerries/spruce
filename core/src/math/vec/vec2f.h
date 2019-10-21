#pragma once
#include <types.h>
#include <util/simd.h>
#include <cmath>
#include <iostream>

namespace spruce {
	struct vec2f {
		float x = 0;
		float y = 0;

		vec2f() = default;
		vec2f(float scalar);
		vec2f(float x, float y);
		vec2f(const vec2f&) = default;
		vec2f(vec2f&&) noexcept = default;
		~vec2f() = default;

		vec2f& set(float scalar) noexcept;
		vec2f& set(float x, float y) noexcept;

		[[nodiscard]] float mag2() const noexcept;
		[[nodiscard]] float mag() const noexcept;
		vec2f& nor() noexcept;
		[[nodiscard]] float dst2(const vec2f& vector) const noexcept;
		[[nodiscard]] float dst(const vec2f& vector) const noexcept;
		[[nodiscard]] float dot(const vec2f& vector) const noexcept;

		vec2f& add(const vec2f& vector) noexcept;
		vec2f& sub(const vec2f& vector) noexcept;

		vec2f& add(float value) noexcept;
		vec2f& sub(float value) noexcept;
		vec2f& scl(float value) noexcept;
		vec2f& div(float value) noexcept;

		[[nodiscard]] bool operator==(const vec2f& vector) const noexcept;
		[[nodiscard]] bool operator!=(const vec2f& vector) const noexcept;

		vec2f& operator+=(const vec2f& vector) noexcept;
		vec2f& operator-=(const vec2f& vector) noexcept;

		vec2f& operator+=(float value) noexcept;
		vec2f& operator-=(float value) noexcept;
		vec2f& operator*=(float value) noexcept;
		vec2f& operator/=(float value) noexcept;

		vec2f& operator=(const vec2f&) = default;
		vec2f& operator=(vec2f&&) noexcept = default;

		[[nodiscard]] static vec2f lerp(const vec2f& a, const vec2f& b, float alpha) noexcept;
	};

	inline vec2f operator+(const vec2f& left, const vec2f& right) noexcept;
	inline vec2f operator-(const vec2f& left, const vec2f& right) noexcept;

	inline vec2f operator+(const vec2f& left, float value) noexcept;
	inline vec2f operator-(const vec2f& left, float value) noexcept;
	inline vec2f operator*(const vec2f& left, float value) noexcept;
	inline vec2f operator/(const vec2f& left, float value) noexcept;

	std::ostream& operator<<(std::ostream& stream, const vec2f& vector);
}

#include <math/vec/vec2fImpl.h>
