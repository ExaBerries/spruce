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
		float values[16];

		mat4f();
		explicit mat4f(const float values[16]);
		mat4f(const vec3f& translation, const quaternion& rotation, const vec3f& scale);
		mat4f(const vec3f& direction, const vec3f& up);
		mat4f(float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9, float v10, float v11, float v12, float v13, float v14, float v15);
		mat4f(const mat4f&) = default;
		mat4f(mat4f&&) noexcept = default;
		~mat4f() = default;

		mat4f& setIdentity() noexcept;
		mat4f& set(const float values[16]) noexcept;
		mat4f& set(const vec3f& translation, const quaternion& rotation, const vec3f& scale) noexcept;
		mat4f& set(const vec3f& direction, const vec3f& up) noexcept;

		[[nodiscard]] float determinant() noexcept;
		mat4f& invert() noexcept;
		mat4f& transpose() noexcept;

		mat4f& operator+=(const mat4f& matrix) noexcept;
		mat4f& operator-=(const mat4f& matrix) noexcept;
		mat4f& operator*=(const mat4f& matrix) noexcept;

		[[nodiscard]] bool operator==(const mat4f& matrix) const noexcept;
		[[nodiscard]] bool operator!=(const mat4f& matrix) const noexcept;

		mat4f& operator=(const mat4f&) = default;
		mat4f& operator=(mat4f&&) noexcept = default;
	};

	inline mat4f operator+(const mat4f& left, const mat4f& right) noexcept;
	inline mat4f operator-(const mat4f& left, const mat4f& right) noexcept;
	inline mat4f operator*(const mat4f& left, const mat4f& right) noexcept;
	inline vec3f operator*(const vec3f& vector, const mat4f& matrix) noexcept;
	inline vec3f operator*(const mat4f& matrix, const vec3f& vector) noexcept;
	inline vec4f operator*(const vec4f& vector, const mat4f& matrix) noexcept;
	inline vec4f operator*(const mat4f& matrix, const vec4f& vector) noexcept;

	std::ostream& operator<<(std::ostream& stream, const mat4f& matrix);
}

#include <math/mat/mat4fImpl.h>
