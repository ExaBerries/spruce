#pragma once
#include <types.h>
#include <math/vec/vec2i.h>
#include <iostream>
#include <cmath>

namespace spruce {
	struct vec3i {
		int32 x = 0;
		int32 y = 0;
		int32 z = 0;

		vec3i() = default;
		vec3i(int32 x, int32 y, int32 z);
		vec3i(const vec2i& vector, int32 z);
		vec3i(const vec3i&) = default;
		vec3i(vec3i&&) noexcept = default;
		~vec3i() = default;

		[[nodiscard]] float mag2() const noexcept;
		[[nodiscard]] float mag() const noexcept;
		[[nodiscard]] float dst2(const vec3i& vector) const noexcept;
		[[nodiscard]] float dst(const vec3i& vector) const noexcept;
		[[nodiscard]] float dot(const vec3i& vector) const noexcept;

		vec3i& add(const vec3i& vector) noexcept;
		vec3i& sub(const vec3i& vector) noexcept;

		vec3i& add(int32 value) noexcept;
		vec3i& sub(int32 value) noexcept;
		vec3i& scl(int32 value) noexcept;
		vec3i& div(int32 value) noexcept;

		[[nodiscard]] bool operator==(const vec3i& vector) const noexcept;
		[[nodiscard]] bool operator!=(const vec3i& vector) const noexcept;

		vec3i& operator+=(const vec3i& vector) noexcept;
		vec3i& operator-=(const vec3i& vector) noexcept;

		vec3i& operator+=(int32 value) noexcept;
		vec3i& operator-=(int32 value) noexcept;
		vec3i& operator%=(int32 value) noexcept;
		vec3i& operator*=(int32 value) noexcept;
		vec3i& operator/=(int32 value) noexcept;

		vec3i& operator=(const vec3i&) = default;
		vec3i& operator=(vec3i&&) noexcept = default;
	};

	vec3i operator+(const vec3i& left, const vec3i& right) noexcept;
	vec3i operator-(const vec3i& left, const vec3i& right) noexcept;

	vec3i operator+(const vec3i& left, int32 value) noexcept;
	vec3i operator-(const vec3i& left, int32 value) noexcept;
	vec3i operator%(const vec3i& left, int32 value) noexcept;
	vec3i operator*(const vec3i& left, int32 value) noexcept;
	vec3i operator/(const vec3i& left, int32 value) noexcept;

	std::ostream& operator<<(std::ostream& stream, const vec3i& vector);
}

namespace std {
	template <>
	struct hash<spruce::vec3i> {
		size_t operator()(const spruce::vec3i& v) const {
			return std::hash<int32>()(v.x) ^ (std::hash<int32>()(v.y) << 1) ^ (std::hash<int32>()(v.z) << 2);
		}
	};
}
