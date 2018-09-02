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
		quaternion(const vec3f& a, const vec3f& b);
		~quaternion();

		quaternion& set(const quaternion& quaternion);
		quaternion& set(const float x, const float y, const float z, const float w);
		quaternion& set(const vec3f& axis, const float& angle);
		quaternion& set(const vec3f& a, const vec3f& b);
		quaternion& set(const float& yaw, const float& pitch, const float& roll);
		void toEuler(float& yaw, float& pitch, float& roll);

		float mag2() const;
		float mag() const;
		quaternion& nor();
		quaternion& conjugate();
		float dot(const quaternion& quaternion) const;

		friend quaternion operator+(const quaternion& left, const quaternion& right);
		friend quaternion operator-(const quaternion& left, const quaternion& right);
		friend quaternion operator*(const quaternion& left, const quaternion& right);
		friend quaternion operator/(const quaternion& left, const quaternion& right);
		friend vec3f operator*(const quaternion&, const vec3f& vector);
		friend vec3f operator*(const vec3f& vector, const quaternion& quaternion);

		quaternion& operator+=(const quaternion& quaternion);
		quaternion& operator-=(const quaternion& quaternion);
		quaternion& operator*=(const quaternion& quaternion);
		quaternion& operator/=(const quaternion& quaternion);

		friend std::ostream& operator<<(std::ostream& stream, const quaternion& quaternion);

		static quaternion lerp(const quaternion& a, const quaternion& b, float alpha);
	};
}

namespace std {
	template <>
	struct hash<spruce::quaternion> {
		size_t operator()(const spruce::quaternion& q) const {
			return std::hash<float>()(q.x) ^ (std::hash<float>()(q.y) << 1) ^ (std::hash<float>()(q.z) << 2) ^ (std::hash<float>()(q.w) << 3);
		}
	};
}

