#pragma once
#include <common.h>
#include <iostream>
#include <math/vec3f.h>

namespace spruce {
	struct quaternion {
		float x;
		float y;
		float z;
		float w;

		quaternion();
		quaternion(const quaternion& quaternion);
		quaternion(const float& x, const float& y, const float& z, const float& w);
		quaternion(const vec3f& axis, const float& angle);
		quaternion(const float& pitch, const float& yaw, const float& roll);

		float mag2() const;
		float mag() const;
		quaternion& nor();
		quaternion& conjugate();
		float dot(const quaternion& quaternion) const;

		friend quaternion operator+(const quaternion left, const quaternion& right);
		friend quaternion operator-(const quaternion left, const quaternion& right);
		friend quaternion operator*(const quaternion left, const quaternion& right);
		friend quaternion operator/(const quaternion left, const quaternion& right);

		quaternion& operator+=(const quaternion& quaternion);
		quaternion& operator-=(const quaternion& quaternion);
		quaternion& operator*=(const quaternion& quaternion);
		quaternion& operator/=(const quaternion& quaternion);

		friend std::ostream& operator<<(std::ostream& stream, const quaternion& quaternion);
	};

	void log(const quaternion& quaternion);
}
