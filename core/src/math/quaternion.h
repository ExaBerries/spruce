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

		quaternion& set(const quaternion& quaternion) noexcept;
		quaternion& set(float x, float y, float z, float w) noexcept;
		quaternion& set(const vec3f& axis, float angle) noexcept;
		quaternion& set(const vec3f& a, const vec3f& b) noexcept;
		quaternion& set(float yaw, float pitch, float roll) noexcept;
		void toEuler(float& yaw, float& pitch, float& roll) const noexcept;

		[[nodiscard]] float mag2() const noexcept;
		[[nodiscard]] float mag() const noexcept;
		quaternion& nor() noexcept;
		quaternion& conjugate() noexcept;
		[[nodiscard]] float dot(const quaternion& quaternion) const noexcept;

		quaternion& operator+=(const quaternion& quaternion) noexcept;
		quaternion& operator-=(const quaternion& quaternion) noexcept;
		quaternion& operator*=(const quaternion& quaternion) noexcept;
		quaternion& operator/=(const quaternion& quaternion) noexcept;

		quaternion& operator=(const quaternion&) = default;
		quaternion& operator=(quaternion&&) noexcept = default;

		[[nodiscard]] static quaternion lerp(const quaternion& a, const quaternion& b, float alpha) noexcept;
	};

	inline quaternion operator+(const quaternion& left, const quaternion& right) noexcept;
	inline quaternion operator-(const quaternion& left, const quaternion& right) noexcept;
	inline quaternion operator*(const quaternion& left, const quaternion& right) noexcept;
	inline vec3f operator*(const quaternion& quaternion, const vec3f& vector) noexcept;
	inline vec3f operator*(const vec3f& vector, const quaternion& quaternion) noexcept;

	std::ostream& operator<<(std::ostream& stream, const quaternion& quaternion);
}

#include <math/quaternionImpl.h>

