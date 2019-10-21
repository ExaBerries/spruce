#pragma once
#include <types.h>
#include <math/vec/vec3f.h>
#include <util/simd.h>
#include <iostream>
#include <cmath>

namespace spruce {
	struct alignas(alignof(simd::reg4f)) quaternion {
		float x = 0;
		float y = 0;
		float z = 0;
		float w = 1;

		quaternion() = default;
		quaternion(float x, float y, float z, float w);
		quaternion(const vec3f& axis, const float& angle);
		quaternion(float pitch, float yaw, float roll);
		quaternion(const vec3f& a, const vec3f& b);
		quaternion(const quaternion&) = default;
		quaternion(quaternion&&) noexcept = default;
		~quaternion() = default;

		quaternion& set(const quaternion& quaternion);
		quaternion& set(float x, float y, float z, float w);
		quaternion& set(const vec3f& axis, float angle);
		quaternion& set(const vec3f& a, const vec3f& b);
		quaternion& set(float yaw, float pitch, float roll);
		void toEuler(float& yaw, float& pitch, float& roll);

		[[nodiscard]] float mag2() const;
		[[nodiscard]] float mag() const;
		quaternion& nor();
		quaternion& conjugate();
		[[nodiscard]] float dot(const quaternion& quaternion) const;

		quaternion& operator+=(const quaternion& quaternion);
		quaternion& operator-=(const quaternion& quaternion);
		quaternion& operator*=(const quaternion& quaternion);
		quaternion& operator/=(const quaternion& quaternion);

		quaternion& operator=(const quaternion&) = default;
		quaternion& operator=(quaternion&&) noexcept = default;

		[[nodiscard]] static quaternion lerp(const quaternion& a, const quaternion& b, float alpha);
	};

	inline quaternion operator+(const quaternion& left, const quaternion& right);
	inline quaternion operator-(const quaternion& left, const quaternion& right);
	inline quaternion operator*(const quaternion& left, const quaternion& right);
	inline vec3f operator*(const quaternion& quaternion, const vec3f& vector);
	inline vec3f operator*(const vec3f& vector, const quaternion& quaternion);

	std::ostream& operator<<(std::ostream& stream, const quaternion& quaternion);
}

#include <math/quaternionImpl.h>

