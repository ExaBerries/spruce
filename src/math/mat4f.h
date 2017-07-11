#pragma once
#include "vec3f.h"
#include "quaternion.h"
#include <math.h>

namespace spruce {
	struct mat4f {
		float values[16];

		mat4f();
		mat4f(float values[16]);
		mat4f(vec3f& translation, quaternion& rotation, vec3f& scale);
		mat4f(float& near, float& far, float& fov, float& aspectRatio);
		virtual ~mat4f();

		friend mat4f operator+(const mat4f left, const mat4f& right);
		friend mat4f operator-(const mat4f left, const mat4f& right);
		friend mat4f operator*(const mat4f left, const mat4f& right);
		friend vec3f operator*(const vec3f vector, const mat4f& matrix);
		friend vec3f operator*(const mat4f matrix, const vec3f vector);

		mat4f& operator+=(const mat4f& matrix);
		mat4f& operator-=(const mat4f& matrix);
		mat4f& operator*=(const mat4f& matrix);

		friend std::ostream& operator<<(std::ostream& stream, const mat4f& matrix);
	};

	extern void log(const mat4f& matrix);
}
