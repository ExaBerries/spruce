#pragma once
#include <types.h>
#include <math/functions.h>
#include <iostream>

namespace spruce {
	struct vec2i {
		int32 x = 0;
		int32 y = 0;

		vec2i() = default;
		constexpr vec2i(int32 scalar) noexcept;
		constexpr vec2i(int32 x, int32 y) noexcept;
		vec2i(const vec2i&) = default;
		vec2i(vec2i&&) noexcept = default;
		~vec2i() = default;

		[[nodiscard]] constexpr float mag2() const noexcept;
		[[nodiscard]] constexpr float mag() const noexcept;
		[[nodiscard]] constexpr float dst2(const vec2i& vector) const noexcept;
		[[nodiscard]] constexpr float dst(const vec2i& vector) const noexcept;
		[[nodiscard]] constexpr float dot(const vec2i& vector) const noexcept;

		constexpr vec2i& add(const vec2i& vector) noexcept;
		constexpr vec2i& sub(const vec2i& vector) noexcept;

		constexpr vec2i& add(int32 value) noexcept;
		constexpr vec2i& sub(int32 value) noexcept;
		constexpr vec2i& scl(int32 value) noexcept;
		constexpr vec2i& div(int32 value) noexcept;

		[[nodiscard]] constexpr bool operator==(const vec2i& vector) const noexcept;
		[[nodiscard]] constexpr bool operator!=(const vec2i& vector) const noexcept;

		constexpr vec2i& operator+=(const vec2i& vector) noexcept;
		constexpr vec2i& operator-=(const vec2i& vector) noexcept;

		constexpr vec2i& operator+=(int32 value) noexcept;
		constexpr vec2i& operator-=(int32 value) noexcept;
		constexpr vec2i& operator%=(int32 value) noexcept;
		constexpr vec2i& operator*=(int32 value) noexcept;
		constexpr vec2i& operator/=(int32 value) noexcept;

		vec2i& operator=(const vec2i&) = default;
		vec2i& operator=(vec2i&&) noexcept = default;
	};

	constexpr vec2i operator+(const vec2i& left, const vec2i& right) noexcept;
	constexpr vec2i operator-(const vec2i& left, const vec2i& right) noexcept;

	constexpr vec2i operator+(const vec2i& left, int32 value) noexcept;
	constexpr vec2i operator-(const vec2i& left, int32 value) noexcept;
	constexpr vec2i operator%(const vec2i& left, int32 value) noexcept;
	constexpr vec2i operator*(const vec2i& left, int32 value) noexcept;
	constexpr vec2i operator/(const vec2i& left, int32 value) noexcept;

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

#include <math/vec/vec2iImpl.h>
