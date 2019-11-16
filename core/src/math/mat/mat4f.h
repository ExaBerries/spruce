#pragma once
#include <types.h>
#include <math/vec/vec3f.h>
#include <math/vec/vec4f.h>
#include <math/quaternion.h>
#include <util/simd.h>
#include <cmath>
#include <iostream>

namespace spruce {
	struct alignas(alignof(simd::reg8f)) mat4f {
		float values[16] = {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};

		mat4f() = default;
		constexpr explicit mat4f(const float values[16]) noexcept;
		constexpr mat4f(const vec3f& translation, const quaternion& rotation, const vec3f& scale) noexcept;
		constexpr mat4f(const vec3f& direction, const vec3f& up) noexcept;
		constexpr mat4f(float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9, float v10, float v11, float v12, float v13, float v14, float v15) noexcept;
		mat4f(const mat4f&) = default;
		mat4f(mat4f&&) noexcept = default;
		~mat4f() = default;

		constexpr mat4f& setIdentity() noexcept;
		constexpr mat4f& set(const float values[16]) noexcept;
		constexpr mat4f& set(const vec3f& translation, const quaternion& rotation, const vec3f& scale) noexcept;
		constexpr mat4f& set(const vec3f& direction, const vec3f& up) noexcept;

		[[nodiscard]] constexpr float determinant() const noexcept;
		constexpr mat4f& invert() noexcept;
		constexpr mat4f& transpose() noexcept;

		constexpr mat4f& operator+=(const mat4f& matrix) noexcept;
		constexpr mat4f& operator-=(const mat4f& matrix) noexcept;
		constexpr mat4f& operator*=(const mat4f& matrix) noexcept;

		[[nodiscard]] constexpr bool operator==(const mat4f& matrix) const noexcept;
		[[nodiscard]] constexpr bool operator!=(const mat4f& matrix) const noexcept;

		mat4f& operator=(const mat4f&) = default;
		mat4f& operator=(mat4f&&) noexcept = default;
	};

	constexpr mat4f operator+(const mat4f& left, const mat4f& right) noexcept;
	constexpr mat4f operator-(const mat4f& left, const mat4f& right) noexcept;
	constexpr mat4f operator*(const mat4f& left, const mat4f& right) noexcept;
	constexpr vec3f operator*(const vec3f& vector, const mat4f& matrix) noexcept;
	constexpr vec3f operator*(const mat4f& matrix, const vec3f& vector) noexcept;
	constexpr vec4f operator*(const vec4f& vector, const mat4f& matrix) noexcept;
	constexpr vec4f operator*(const mat4f& matrix, const vec4f& vector) noexcept;

	std::ostream& operator<<(std::ostream& stream, const mat4f& matrix);
}

#include <math/mat/mat4fImpl.h>
