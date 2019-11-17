#pragma once
#include <types.h>
#include <math/vec/vec3f.h>
#include <math/functions.h>
#include <util/simd.h>
#include <iostream>

namespace spruce {
	struct alignas(alignof(simd::reg4f)) quaternion {
		float x = 0;
		float y = 0;
		float z = 0;
		float w = 1;

		quaternion() = default;
		constexpr quaternion(float x, float y, float z, float w) noexcept;
		constexpr quaternion(const vec3f& axis, const float& angle) noexcept;
		constexpr quaternion(float pitch, float yaw, float roll) noexcept;
		constexpr quaternion(const vec3f& a, const vec3f& b) noexcept;
		quaternion(const quaternion&) = default;
		quaternion(quaternion&&) noexcept = default;
		~quaternion() = default;

		constexpr quaternion& set(const quaternion& quaternion) noexcept;
		constexpr quaternion& set(float x, float y, float z, float w) noexcept;
		constexpr quaternion& set(const vec3f& axis, float angle) noexcept;
		constexpr quaternion& set(const vec3f& a, const vec3f& b) noexcept;
		constexpr quaternion& set(float yaw, float pitch, float roll) noexcept;
		[[nodiscard]] constexpr vec3f toEuler() const noexcept;

		[[nodiscard]] constexpr float mag2() const noexcept;
		[[nodiscard]] constexpr float mag() const noexcept;
		constexpr quaternion& nor() noexcept;
		constexpr quaternion& conjugate() noexcept;
		[[nodiscard]] constexpr float dot(const quaternion& quaternion) const noexcept;

		constexpr quaternion& operator+=(const quaternion& quaternion) noexcept;
		constexpr quaternion& operator-=(const quaternion& quaternion) noexcept;
		constexpr quaternion& operator*=(const quaternion& quaternion) noexcept;
		constexpr quaternion& operator/=(const quaternion& quaternion) noexcept;

		quaternion& operator=(const quaternion&) = default;
		quaternion& operator=(quaternion&&) noexcept = default;

		[[nodiscard]] constexpr static quaternion lerp(const quaternion& a, const quaternion& b, float alpha) noexcept;
	};

	constexpr quaternion operator+(const quaternion& left, const quaternion& right) noexcept;
	constexpr quaternion operator-(const quaternion& left, const quaternion& right) noexcept;
	constexpr quaternion operator*(const quaternion& left, const quaternion& right) noexcept;
	constexpr vec3f operator*(const quaternion& quaternion, const vec3f& vector) noexcept;
	constexpr vec3f operator*(const vec3f& vector, const quaternion& quaternion) noexcept;

	std::ostream& operator<<(std::ostream& stream, const quaternion& quaternion);
}

#include <math/quaternionImpl.h>

