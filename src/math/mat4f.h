#pragma once
#include <common.h>
#include <math/vec3f.h>
#include <math/quaternion.h>
#include <math.h>

namespace spruce {
	struct mat4f {
		float values[16];

		mat4f();
		mat4f(float values[16]);
		mat4f(vec3f& translation, quaternion& rotation, vec3f& scale);
		mat4f(float& near, float& far, float& fov, float& aspectRatio);
		mat4f(vec3f& direction, vec3f& up);
		mat4f(float left, float right, float bottom, float top, float near, float far);
		virtual ~mat4f();

		mat4f& setIdentity();
		mat4f& set(float values[16]);
		mat4f& set(vec3f& translation, quaternion& rotation, vec3f& scale);
		mat4f& set(float& near, float& far, float& fov, float& aspectRatio);
		mat4f& set(vec3f& direction, vec3f& up);
		mat4f& set(float left, float right, float bottom, float top, float near, float far);

		float determinate();
		mat4f& invert();
		mat4f& transpose();

		friend mat4f operator+(const mat4f& left, const mat4f& right);
		friend mat4f operator-(const mat4f& left, const mat4f& right);
		friend mat4f operator*(const mat4f& left, const mat4f& right);
		friend vec3f operator*(const vec3f& vector, const mat4f& matrix);
		friend vec3f operator*(const mat4f& matrix, const vec3f& vector);

		mat4f& operator+=(const mat4f& matrix);
		mat4f& operator-=(const mat4f& matrix);
		mat4f& operator*=(const mat4f& matrix);

		friend std::ostream& operator<<(std::ostream& stream, const mat4f& matrix);
	};

	void log(const mat4f& matrix);
}
