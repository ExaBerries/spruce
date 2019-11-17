#pragma once
#include <types.h>
#include <math/functions.h>
#include <math/vec/vec2i.h>
#include <iostream>

namespace spruce {
	struct vec3i {
		int32 x = 0;
		int32 y = 0;
		int32 z = 0;

		vec3i() = default;
		constexpr vec3i(int32 scalar) noexcept;
		constexpr vec3i(int32 x, int32 y, int32 z) noexcept;
		constexpr vec3i(const vec2i& vector, int32 z) noexcept;
		vec3i(const vec3i&) = default;
		vec3i(vec3i&&) noexcept = default;
		~vec3i() = default;

		[[nodiscard]] constexpr float mag2() const noexcept;
		[[nodiscard]] constexpr float mag() const noexcept;
		[[nodiscard]] constexpr float dst2(const vec3i& vector) const noexcept;
		[[nodiscard]] constexpr float dst(const vec3i& vector) const noexcept;
		[[nodiscard]] constexpr float dot(const vec3i& vector) const noexcept;

		constexpr vec3i& add(const vec3i& vector) noexcept;
		constexpr vec3i& sub(const vec3i& vector) noexcept;

		constexpr vec3i& add(int32 value) noexcept;
		constexpr vec3i& sub(int32 value) noexcept;
		constexpr vec3i& scl(int32 value) noexcept;
		constexpr vec3i& div(int32 value) noexcept;

		[[nodiscard]] constexpr bool operator==(const vec3i& vector) const noexcept;
		[[nodiscard]] constexpr bool operator!=(const vec3i& vector) const noexcept;

		constexpr vec3i& operator+=(const vec3i& vector) noexcept;
		constexpr vec3i& operator-=(const vec3i& vector) noexcept;

		constexpr vec3i& operator+=(int32 value) noexcept;
		constexpr vec3i& operator-=(int32 value) noexcept;
		constexpr vec3i& operator%=(int32 value) noexcept;
		constexpr vec3i& operator*=(int32 value) noexcept;
		constexpr vec3i& operator/=(int32 value) noexcept;

		vec3i& operator=(const vec3i&) = default;
		vec3i& operator=(vec3i&&) noexcept = default;
	};

	constexpr vec3i operator+(const vec3i& left, const vec3i& right) noexcept;
	constexpr vec3i operator-(const vec3i& left, const vec3i& right) noexcept;

	constexpr vec3i operator+(const vec3i& left, int32 value) noexcept;
	constexpr vec3i operator-(const vec3i& left, int32 value) noexcept;
	constexpr vec3i operator%(const vec3i& left, int32 value) noexcept;
	constexpr vec3i operator*(const vec3i& left, int32 value) noexcept;
	constexpr vec3i operator/(const vec3i& left, int32 value) noexcept;

	std::ostream& operator<<(std::ostream& stream, const vec3i& vector);
}

namespace std {
	template <>
	struct hash<spruce::vec3i>;
}

#include <math/vec/vec3iImpl.h>
