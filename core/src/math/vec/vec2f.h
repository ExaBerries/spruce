#pragma once
#include <types.h>
#include <util/simd.h>
#include <cmath>
#include <iostream>

namespace spruce {
	struct vec2f {
		float x = 0;
		float y = 0;

		vec2f() = default;
		vec2f(float scalar);
		vec2f(float x, float y);
		vec2f(const vec2f&) = default;
		vec2f(vec2f&&) noexcept = default;
		~vec2f() = default;

		vec2f& set(float scalar);
		vec2f& set(float x, float y);

		[[nodiscard]] float mag2() const;
		[[nodiscard]] float mag() const;
		vec2f& nor();
		[[nodiscard]] float dst2(const vec2f& vector) const;
		[[nodiscard]] float dst(const vec2f& vector) const;
		[[nodiscard]] float dot(const vec2f& vector) const;

		vec2f& add(const vec2f& vector);
		vec2f& sub(const vec2f& vector);

		vec2f& add(float value);
		vec2f& sub(float value);
		vec2f& scl(float value);
		vec2f& div(float value);

		[[nodiscard]] bool operator==(const vec2f& vector) const;
		[[nodiscard]] bool operator!=(const vec2f& vector) const;

		vec2f& operator+=(const vec2f& vector);
		vec2f& operator-=(const vec2f& vector);

		vec2f& operator+=(float value);
		vec2f& operator-=(float value);
		vec2f& operator*=(float value);
		vec2f& operator/=(float value);

		vec2f& operator=(const vec2f&) = default;
		vec2f& operator=(vec2f&&) noexcept = default;

		[[nodiscard]] static vec2f lerp(const vec2f& a, const vec2f& b, float alpha);
	};

	inline vec2f operator+(const vec2f& left, const vec2f& right);
	inline vec2f operator-(const vec2f& left, const vec2f& right);

	inline vec2f operator+(const vec2f& left, float value);
	inline vec2f operator-(const vec2f& left, float value);
	inline vec2f operator*(const vec2f& left, float value);
	inline vec2f operator/(const vec2f& left, float value);

	std::ostream& operator<<(std::ostream& stream, const vec2f& vector);
}

#include <math/vec/vec2fImpl.h>
