#pragma once
#include <types.h>
#include <math/vec/vec3f.h>
#include <math/functions.h>
#include <util/simd.h>
#include <iostream>

namespace spruce {
	class alignas(alignof(simd::reg4f)) vec4f {
		public:
			float x = 0;
			float y = 0;
			float z = 0;
			float w = 0;

			vec4f() = default;
			constexpr vec4f(float scalar) noexcept;
			constexpr vec4f(const vec3f& vector, float w) noexcept;
			constexpr vec4f(float x, float y, float z, float w) noexcept;
			vec4f(const vec4f&) = default;
			vec4f(vec4f&&) noexcept = default;
			~vec4f() = default;

			constexpr vec4f& set(const vec4f& vector) noexcept;
			constexpr vec4f& set(const vec3f& vector, float w) noexcept;
			constexpr vec4f& set(float x, float y, float z, float w) noexcept;

			[[nodiscard]] constexpr float mag2() const noexcept;
			[[nodiscard]] constexpr float mag() const noexcept;
			constexpr vec4f& nor() noexcept;
			[[nodiscard]] constexpr float dst2(const vec4f& vector) const noexcept;
			[[nodiscard]] constexpr float dst(const vec4f& vector) const noexcept;
			[[nodiscard]] constexpr float dot(const vec4f& vector) const noexcept;

			constexpr vec4f& add(const vec4f& vector) noexcept;
			constexpr vec4f& sub(const vec4f& vector) noexcept;

			constexpr vec4f& add(float value) noexcept;
			constexpr vec4f& sub(float value) noexcept;
			constexpr vec4f& scl(float value) noexcept;
			constexpr vec4f& div(float value) noexcept;

			[[nodiscard]] constexpr bool operator==(const vec4f& vector) const noexcept;
			[[nodiscard]] constexpr bool operator!=(const vec4f& vector) const noexcept;

			constexpr vec4f& operator+=(const vec4f& vector) noexcept;
			constexpr vec4f& operator-=(const vec4f& vector) noexcept;

			constexpr vec4f& operator+=(float value) noexcept;
			constexpr vec4f& operator-=(float value) noexcept;
			constexpr vec4f& operator*=(float value) noexcept;
			constexpr vec4f& operator/=(float value) noexcept;

			vec4f& operator=(const vec4f&) = default;
			vec4f& operator=(vec4f&&) noexcept = default;

			[[nodiscard]] constexpr static vec4f lerp(const vec4f& a, const vec4f& b, float alpha) noexcept;
	};

	constexpr vec4f operator+(const vec4f& left, const vec4f& right) noexcept;
	constexpr vec4f operator-(const vec4f& left, const vec4f& right) noexcept;

	constexpr vec4f operator+(const vec4f& left, float value) noexcept;
	constexpr vec4f operator-(const vec4f& left, float value) noexcept;
	constexpr vec4f operator*(const vec4f& left, float value) noexcept;
	constexpr vec4f operator/(const vec4f& left, float value) noexcept;

	std::ostream& operator<<(std::ostream& stream, const vec4f& vector);
}

#include <math/vec/vec4fImpl.h>
