#pragma once
#include <types.h>
#include <math/vec/vec3f.h>
#include <math/vec/vec4f.h>
#include <math/quaternion.h>
#include <util/simd.h>
#include <cmath>
#include <iostream>

namespace spruce {
	struct alignas(2 * alignof(simd::reg8f)) mat4f {
		float values[16];

		mat4f();
		explicit mat4f(const float values[16]);
		mat4f(const vec3f& translation, const quaternion& rotation, const vec3f& scale);
		mat4f(const vec3f& direction, const vec3f& up);
		mat4f(float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9, float v10, float v11, float v12, float v13, float v14, float v15);
		mat4f(const mat4f&) = default;
		mat4f(mat4f&&) noexcept = default;
		~mat4f() = default;

		mat4f& setIdentity();
		mat4f& set(const float values[16]);
		mat4f& set(const vec3f& translation, const quaternion& rotation, const vec3f& scale);
		mat4f& set(const vec3f& direction, const vec3f& up);

		float determinant();
		mat4f& invert();
		mat4f& transpose();

		mat4f& operator+=(const mat4f& matrix);
		mat4f& operator-=(const mat4f& matrix);
		mat4f& operator*=(const mat4f& matrix);

		bool operator==(const mat4f& matrix) const;
		bool operator!=(const mat4f& matrix) const;

		mat4f& operator=(const mat4f&) = default;
		mat4f& operator=(mat4f&&) noexcept = default;
	};

	inline mat4f operator+(const mat4f& left, const mat4f& right);
	inline mat4f operator-(const mat4f& left, const mat4f& right);
	inline mat4f operator*(const mat4f& left, const mat4f& right);
	inline vec3f operator*(const vec3f& vector, const mat4f& matrix);
	inline vec3f operator*(const mat4f& matrix, const vec3f& vector);
	inline vec4f operator*(const vec4f& vector, const mat4f& matrix);
	inline vec4f operator*(const mat4f& matrix, const vec4f& vector);

	std::ostream& operator<<(std::ostream& stream, const mat4f& matrix);
}

#include <math/mat/mat4fImpl.h>
