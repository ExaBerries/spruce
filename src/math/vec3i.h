#pragma once
#include <common.h>
#include <math/vec2i.h>
#include <iostream>
#include <math.h>

namespace spruce {
	struct vec3i {
		int32 x;
		int32 y;
		int32 z;

		vec3i();
		vec3i(int32 x, int32 y, int32 z);
		vec3i(const vec2i vector, int32 z);
		~vec3i();

		float mag2() const;
		float mag() const;
		float dst2(const vec3i& vector) const;
		float dst(const vec3i& vector) const;
		float dot(const vec3i& vector) const;

		vec3i& add(const vec3i& vector);
		vec3i& sub(const vec3i& vector);

		vec3i& add(const int32& value);
		vec3i& sub(const int32& value);
		vec3i& scl(const int32& value);
		vec3i& div(const int32& value);

		friend vec3i operator+(const vec3i left, const vec3i& right);
		friend vec3i operator-(const vec3i left, const vec3i& right);

		friend vec3i operator+(const vec3i left, int32 value);
		friend vec3i operator-(const vec3i left, int32 value);
		friend vec3i operator%(const vec3i left, int32 value);
		friend vec3i operator*(const vec3i left, int32 value);
		friend vec3i operator/(const vec3i left, int32 value);

		vec3i& operator+=(const vec3i& vector);
		vec3i& operator-=(const vec3i& vector);

		vec3i& operator+=(int32 value);
		vec3i& operator-=(int32 value);
		vec3i& operator%=(int32 value);
		vec3i& operator*=(int32 value);
		vec3i& operator/=(int32 value);

		friend std::ostream& operator<<(std::ostream& stream, const vec3i& vector);
	};
}
