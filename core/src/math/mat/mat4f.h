#pragma once
#include <types.h>
#include <math/vec/vec3f.h>
#include <math/vec/vec4f.h>
#include <math/quaternion.h>
#include <cmath>
#include <iostream>

namespace spruce {
	struct mat4f {
		float values[16];

		mat4f();
		explicit mat4f(const float values[16]);
		mat4f(const vec3f& translation, const quaternion& rotation, const vec3f& scale);
		mat4f(const vec3f& direction, const vec3f& up);
		mat4f(const mat4f&) = default;
		mat4f(mat4f&&) noexcept = default;
		~mat4f() = default;

		mat4f& setIdentity();
		mat4f& set(const float values[16]);
		mat4f& set(const vec3f& translation, const quaternion& rotation, const vec3f& scale);
		mat4f& set(const vec3f& direction, const vec3f& up);

		float determinate();
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

	mat4f operator+(const mat4f& left, const mat4f& right);
	mat4f operator-(const mat4f& left, const mat4f& right);
	mat4f operator*(const mat4f& left, const mat4f& right);
	vec3f operator*(const vec3f& vector, const mat4f& matrix);
	vec3f operator*(const mat4f& matrix, const vec3f& vector);
	vec4f operator*(const vec4f& vector, const mat4f& matrix);
	vec4f operator*(const mat4f& matrix, const vec4f& vector);

	std::ostream& operator<<(std::ostream& stream, const mat4f& matrix);
}

namespace std {
	template <>
	struct hash<spruce::mat4f> {
		size_t operator()(const spruce::mat4f& m) const {
			size_t hashValue = 0;
			for (uint16 i = 0; i < 16; i++) {
				hashValue ^= std::hash<float>()(m.values[i]) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
			}
			return hashValue;
		}
	};
}
