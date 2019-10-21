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

		[[nodiscard]] float mag2() const;
		[[nodiscard]] float mag() const;
		[[nodiscard]] float dst2(const vec3i& vector) const;
		[[nodiscard]] float dst(const vec3i& vector) const;
		[[nodiscard]] float dot(const vec3i& vector) const;

		vec3i& add(const vec3i& vector);
		vec3i& sub(const vec3i& vector);

		vec3i& add(int32 value);
		vec3i& sub(int32 value);
		vec3i& scl(int32 value);
		vec3i& div(int32 value);

		[[nodiscard]] bool operator==(const vec3i& vector) const;
		[[nodiscard]] bool operator!=(const vec3i& vector) const;

		vec3i& operator+=(const vec3i& vector);
		vec3i& operator-=(const vec3i& vector);

		vec3i& operator+=(int32 value);
		vec3i& operator-=(int32 value);
		vec3i& operator%=(int32 value);
		vec3i& operator*=(int32 value);
		vec3i& operator/=(int32 value);

		vec3i& operator=(const vec3i&) = default;
		vec3i& operator=(vec3i&&) noexcept = default;
	};

	vec3i operator+(const vec3i& left, const vec3i& right);
	vec3i operator-(const vec3i& left, const vec3i& right);

	vec3i operator+(const vec3i& left, int32 value);
	vec3i operator-(const vec3i& left, int32 value);
	vec3i operator%(const vec3i& left, int32 value);
	vec3i operator*(const vec3i& left, int32 value);
	vec3i operator/(const vec3i& left, int32 value);

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
