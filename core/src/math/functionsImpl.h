#pragma once

namespace spruce {
	template <typename T>
	constexpr T clamp(const T& value, T min, T max) noexcept {
		static_assert(std::is_arithmetic_v<T>);
		if (value < min) {
			return min;
		} else if (value > max) {
			return max;
		}
		return value;
	}

	template <typename T>
	constexpr T lerp(T a, T b, T alpha) noexcept {
		static_assert(std::is_arithmetic_v<T>);
		return (1 - alpha) * a + alpha * b;
	}

	template <typename T>
	constexpr T sqrt(T value) noexcept {
		static_assert(std::is_arithmetic_v<T>);
		if (std::is_constant_evaluated()) {
			return gcem::sqrt(value);
		} else {
			return std::sqrt(value);
		}
	}

	template <typename T>
	constexpr T sin(T value) noexcept {
		static_assert(std::is_arithmetic_v<T>);
		if (std::is_constant_evaluated()) {
			return gcem::sin(value);
		} else {
			return std::sin(value);
		}
	}

	template <typename T>
	constexpr T cos(T value) noexcept {
		static_assert(std::is_arithmetic_v<T>);
		if (std::is_constant_evaluated()) {
			return gcem::cos(value);
		} else {
			return std::cos(value);
		}
	}

	template <typename T>
	constexpr T tan(T value) noexcept {
		static_assert(std::is_arithmetic_v<T>);
		if (std::is_constant_evaluated()) {
			return gcem::tan(value);
		} else {
			return std::tan(value);
		}
	}

	template <typename T>
	constexpr T asin(T value) noexcept {
		static_assert(std::is_arithmetic_v<T>);
		if (std::is_constant_evaluated()) {
			return gcem::asin(value);
		} else {
			return std::asin(value);
		}
	}

	template <typename T>
	constexpr T acos(T value) noexcept {
		static_assert(std::is_arithmetic_v<T>);
		if (std::is_constant_evaluated()) {
			return gcem::acos(value);
		} else {
			return std::acos(value);
		}
	}

	template <typename T>
	constexpr T atan(T value) noexcept {
		static_assert(std::is_arithmetic_v<T>);
		if (std::is_constant_evaluated()) {
			#pragma gcc diagnostic push
			#pragma gcc diagnostic ignored "-Wdouble-promotion"
			#pragma gcc diagnostic ignored "-Wfloat-conversion"
			#pragma gcc diagnostic ignored "-Wconversion"
			return gcem::atan(value);
			#pragma gcc diagnostic pop
		} else {
			return std::atan(value);
		}
	}

	template <typename T>
	constexpr T atan2(T a, T b) noexcept {
		static_assert(std::is_arithmetic_v<T>);
		if (std::is_constant_evaluated()) {
			#pragma gcc diagnostic push
			#pragma gcc diagnostic ignored "-Wdouble-promotion"
			#pragma gcc diagnostic ignored "-Wfloat-conversion"
			#pragma gcc diagnostic ignored "-Wconversion"
			return gcem::atan2(a, b);
			#pragma gcc diagnostic pop
		} else {
			return std::atan2(a, b);
		}
	}
}
