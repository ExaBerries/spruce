#pragma once
#include <types.h>
#include <math/vec/vec3f.h>
#include <util/simd.h>
#include <iostream>
#include <cmath>

namespace spruce {
	class alignas(alignof(simd::reg4f)) vec4f {
		public:
			float x = 0;
			float y = 0;
			float z = 0;
			float w = 0;

			vec4f() = default;
			vec4f(float scalar);
			vec4f(const vec3f& vector, float w);
			vec4f(float x, float y, float z, float w);
			vec4f(const vec4f&) = default;
			vec4f(vec4f&&) noexcept = default;
			~vec4f() = default;

			vec4f& set(const vec4f& vector) noexcept;
			vec4f& set(const vec3f& vector, float w) noexcept;
			vec4f& set(float x, float y, float z, float w) noexcept;

			[[nodiscard]] float mag2() const noexcept;
			[[nodiscard]] float mag() const noexcept;
			vec4f& nor() noexcept;
			[[nodiscard]] float dst2(const vec4f& vector) const noexcept;
			[[nodiscard]] float dst(const vec4f& vector) const noexcept;
			[[nodiscard]] float dot(const vec4f& vector) const noexcept;

			vec4f& add(const vec4f& vector) noexcept;
			vec4f& sub(const vec4f& vector) noexcept;

			vec4f& add(float value) noexcept;
			vec4f& sub(float value) noexcept;
			vec4f& scl(float value) noexcept;
			vec4f& div(float value) noexcept;

			[[nodiscard]] bool operator==(const vec4f& vector) const noexcept;
			[[nodiscard]] bool operator!=(const vec4f& vector) const noexcept;

			vec4f& operator+=(const vec4f& vector) noexcept;
			vec4f& operator-=(const vec4f& vector) noexcept;

			vec4f& operator+=(float value) noexcept;
			vec4f& operator-=(float value) noexcept;
			vec4f& operator*=(float value) noexcept;
			vec4f& operator/=(float value) noexcept;

			vec4f& operator=(const vec4f&) = default;
			vec4f& operator=(vec4f&&) noexcept = default;

			[[nodiscard]] static vec4f lerp(const vec4f& a, const vec4f& b, float alpha) noexcept;
	};

	inline vec4f operator+(const vec4f& left, const vec4f& right) noexcept;
	inline vec4f operator-(const vec4f& left, const vec4f& right) noexcept;

	inline vec4f operator+(const vec4f& left, float value) noexcept;
	inline vec4f operator-(const vec4f& left, float value) noexcept;
	inline vec4f operator*(const vec4f& left, float value) noexcept;
	inline vec4f operator/(const vec4f& left, float value) noexcept;

	std::ostream& operator<<(std::ostream& stream, const vec4f& vector);
}

#include <math/vec/vec4fImpl.h>
