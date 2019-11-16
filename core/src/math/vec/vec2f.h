#pragma once
#include <types.h>
#include <math/functions.h>
#include <util/simd.h>
#include <type_traits>
#include <iostream>

namespace spruce {
	struct vec2f {
		float x = 0;
		float y = 0;

		vec2f() = default;
		constexpr vec2f(float scalar) noexcept;
		constexpr vec2f(float x, float y) noexcept;
		vec2f(const vec2f&) = default;
		vec2f(vec2f&&) noexcept = default;
		~vec2f() = default;

		constexpr vec2f& set(float scalar) noexcept;
		constexpr vec2f& set(float x, float y) noexcept;

		[[nodiscard]] constexpr float mag2() const noexcept;
		[[nodiscard]] constexpr float mag() const noexcept;
		constexpr vec2f& nor() noexcept;
		[[nodiscard]] constexpr float dst2(const vec2f& vector) const noexcept;
		[[nodiscard]] constexpr float dst(const vec2f& vector) const noexcept;
		[[nodiscard]] constexpr float dot(const vec2f& vector) const noexcept;

		constexpr vec2f& add(const vec2f& vector) noexcept;
		constexpr vec2f& sub(const vec2f& vector) noexcept;

		constexpr vec2f& add(float value) noexcept;
		constexpr vec2f& sub(float value) noexcept;
		constexpr vec2f& scl(float value) noexcept;
		constexpr vec2f& div(float value) noexcept;

		[[nodiscard]] constexpr bool operator==(const vec2f& vector) const noexcept;
		[[nodiscard]] constexpr bool operator!=(const vec2f& vector) const noexcept;

		constexpr vec2f& operator+=(const vec2f& vector) noexcept;
		constexpr vec2f& operator-=(const vec2f& vector) noexcept;

		constexpr vec2f& operator+=(float value) noexcept;
		constexpr vec2f& operator-=(float value) noexcept;
		constexpr vec2f& operator*=(float value) noexcept;
		constexpr vec2f& operator/=(float value) noexcept;

		vec2f& operator=(const vec2f&) = default;
		vec2f& operator=(vec2f&&) noexcept = default;

		[[nodiscard]] constexpr static vec2f lerp(const vec2f& a, const vec2f& b, float alpha) noexcept;
	};

	constexpr vec2f operator+(const vec2f& left, const vec2f& right) noexcept;
	constexpr vec2f operator-(const vec2f& left, const vec2f& right) noexcept;

	constexpr vec2f operator+(const vec2f& left, float value) noexcept;
	constexpr vec2f operator-(const vec2f& left, float value) noexcept;
	constexpr vec2f operator*(const vec2f& left, float value) noexcept;
	constexpr vec2f operator/(const vec2f& left, float value) noexcept;

	std::ostream& operator<<(std::ostream& stream, const vec2f& vector);
}

#include <math/vec/vec2fImpl.h>
