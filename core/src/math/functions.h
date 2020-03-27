#pragma once
#include <types.h>
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#pragma clang diagnostic ignored "-Wimplicit-float-conversion"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wfloat-conversion"
#pragma GCC diagnostic ignored "-Wconversion"
#endif
#include <gcem.hpp>
#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#include <type_traits>
#include <cmath>

namespace spruce {
	template <typename T>
	[[nodiscard]] constexpr T clamp(const T& value, T min, T max) noexcept;

	template <typename T>
	[[nodiscard]] constexpr T lerp(T a, T b, T alpha) noexcept;

	template <typename T>
	[[nodiscard]] constexpr T sqrt(T value) noexcept;

	template <typename T>
	[[nodiscard]] constexpr T sin(T value) noexcept;

	template <typename T>
	[[nodiscard]] constexpr T cos(T value) noexcept;

	template <typename T>
	[[nodiscard]] constexpr T tan(T value) noexcept;

	template <typename T>
	[[nodiscard]] constexpr T asin(T value) noexcept;

	template <typename T>
	[[nodiscard]] constexpr T acos(T value) noexcept;

	template <typename T>
	[[nodiscard]] constexpr T atan(T value) noexcept;

	template <typename T>
	[[nodiscard]] constexpr T atan2(T a, T b) noexcept;
}

#include <math/functionsImpl.h>
