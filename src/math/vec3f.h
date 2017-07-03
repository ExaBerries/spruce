#pragma once
#include <iostream>
#include "vec2f.h"
#include <math.h>

namespace spruce {
	struct vec3f {
		float x;
		float y;
		float z;

		vec3f();
		vec3f(const float& scalar);
		vec3f(const vec2f& vector, const float& z);
		vec3f(const float& x, const float& y, const float& z);

		float mag2() const;
		float mag() const;
		vec3f& nor();
		float dst2(const vec3f& vector) const;
		float dst(const vec3f& vector) const;
		float dot(const vec3f& vector) const;
		vec3f& crs(const vec3f& vector);

		vec3f& add(const vec3f& vector);
		vec3f& sub(const vec3f& vector);

		vec3f& add(const float& value);
		vec3f& sub(const float& value);
		vec3f& scl(const float& value);
		vec3f& div(const float& value);

		friend vec3f operator+(const vec3f left, const vec3f& right);
		friend vec3f operator-(const vec3f left, const vec3f& right);

		friend vec3f operator+(const vec3f left, float value);
		friend vec3f operator-(const vec3f left, float value);
		friend vec3f operator*(const vec3f left, float value);
		friend vec3f operator/(const vec3f left, float value);

		bool operator==(const vec3f& vector) const;
		bool operator!=(const vec3f& vector) const;

		vec3f& operator+=(const vec3f& vector);
		vec3f& operator-=(const vec3f& vector);

		vec3f& operator+=(const float& value);
		vec3f& operator-=(const float& value);
		vec3f& operator*=(const float& value);
		vec3f& operator/=(const float& value);

		friend std::ostream& operator<<(std::ostream& stream, const vec2f& vector);
	};

	extern void log(const vec3f& vector);
}
