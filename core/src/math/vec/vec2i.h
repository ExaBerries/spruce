#pragma once
#include <types.h>
#include <cmath>
#include <iostream>

namespace spruce {
	struct vec2i {
		int32 x = 0;
		int32 y = 0;

		vec2i() = default;
		vec2i(int32 scalar);
		vec2i(int32 x, int32 y);
		vec2i(const vec2i&) = default;
		vec2i(vec2i&&) noexcept = default;
		~vec2i() = default;

		[[nodiscard]] float mag2() const noexcept;
		[[nodiscard]] float mag() const noexcept;
		[[nodiscard]] float dst2(const vec2i& vector) const noexcept;
		[[nodiscard]] float dst(const vec2i& vector) const noexcept;
		[[nodiscard]] float dot(const vec2i& vector) const noexcept;

		vec2i& add(const vec2i& vector) noexcept;
		vec2i& sub(const vec2i& vector) noexcept;

		vec2i& add(int32 value) noexcept;
		vec2i& sub(int32 value) noexcept;
		vec2i& scl(int32 value) noexcept;
		vec2i& div(int32 value) noexcept;

		[[nodiscard]] bool operator==(const vec2i& vector) const noexcept;
		[[nodiscard]] bool operator!=(const vec2i& vector) const noexcept;

		vec2i& operator+=(const vec2i& vector) noexcept;
		vec2i& operator-=(const vec2i& vector) noexcept;

		vec2i& operator+=(int32 value) noexcept;
		vec2i& operator-=(int32 value) noexcept;
		vec2i& operator%=(int32 value) noexcept;
		vec2i& operator*=(int32 value) noexcept;
		vec2i& operator/=(int32 value) noexcept;

		vec2i& operator=(const vec2i&) = default;
		vec2i& operator=(vec2i&&) noexcept = default;
	};

	vec2i operator+(const vec2i& left, const vec2i& right) noexcept;
	vec2i operator-(const vec2i& left, const vec2i& right) noexcept;

	vec2i operator+(const vec2i& left, int32 value) noexcept;
	vec2i operator-(const vec2i& left, int32 value) noexcept;
	vec2i operator%(const vec2i& left, int32 value) noexcept;
	vec2i operator*(const vec2i& left, int32 value) noexcept;
	vec2i operator/(const vec2i& left, int32 value) noexcept;

	std::ostream& operator<<(std::ostream& stream, const vec2i& vector);
}

namespace std {
	template <>
	struct hash<spruce::vec2i> {
		size_t operator()(const spruce::vec2i& v) const {
			return std::hash<int32>()(v.x) ^ (std::hash<int32>()(v.y) << 1);
		}
	};
}
