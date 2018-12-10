#pragma once
#include <types.h>
#include <math/vec/vec3f.h>
#include <math/vec/vec4f.h>
#include <math/quaternion.h>
#include <math.h>
#include <iostream>

namespace spruce {
	struct mat4f {
		float values[16];

		mat4f();
		mat4f(float values[16]);
		mat4f(vec3f& translation, quaternion& rotation, vec3f& scale);
		mat4f(vec3f& direction, vec3f& up);
		mat4f(const mat4f& matrix);
		~mat4f();

		mat4f& setIdentity();
		mat4f& set(float values[16]);
		mat4f& set(vec3f& translation, quaternion& rotation, vec3f& scale);
		mat4f& set(vec3f& direction, vec3f& up);

		float determinate();
		mat4f& invert();
		mat4f& transpose();

		friend mat4f operator+(const mat4f& left, const mat4f& right);
		friend mat4f operator-(const mat4f& left, const mat4f& right);
		friend mat4f operator*(const mat4f& left, const mat4f& right);
		friend vec3f operator*(const vec3f& vector, const mat4f& matrix);
		friend vec3f operator*(const mat4f& matrix, const vec3f& vector);
		friend vec4f operator*(const vec4f& vector, const mat4f& matrix);
		friend vec4f operator*(const mat4f& matrix, const vec4f& vector);

		mat4f& operator+=(const mat4f& matrix);
		mat4f& operator-=(const mat4f& matrix);
		mat4f& operator*=(const mat4f& matrix);

		bool operator==(const mat4f& matrix) const;
		bool operator!=(const mat4f& matrix) const;

		friend std::ostream& operator<<(std::ostream& stream, const mat4f& matrix);
	};
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
