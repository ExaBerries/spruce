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

			vec4f& set(const vec4f& vector);
			vec4f& set(const vec3f& vector, float w);
			vec4f& set(float x, float y, float z, float w);

			[[nodiscard]] float mag2() const;
			[[nodiscard]] float mag() const;
			vec4f& nor();
			[[nodiscard]] float dst2(const vec4f& vector) const;
			[[nodiscard]] float dst(const vec4f& vector) const;
			[[nodiscard]] float dot(const vec4f& vector) const;

			vec4f& add(const vec4f& vector);
			vec4f& sub(const vec4f& vector);

			vec4f& add(float value);
			vec4f& sub(float value);
			vec4f& scl(float value);
			vec4f& div(float value);

			[[nodiscard]] bool operator==(const vec4f& vector) const;
			[[nodiscard]] bool operator!=(const vec4f& vector) const;

			vec4f& operator+=(const vec4f& vector);
			vec4f& operator-=(const vec4f& vector);

			vec4f& operator+=(float value);
			vec4f& operator-=(float value);
			vec4f& operator*=(float value);
			vec4f& operator/=(float value);

			vec4f& operator=(const vec4f&) = default;
			vec4f& operator=(vec4f&&) noexcept = default;

			[[nodiscard]] static vec4f lerp(const vec4f& a, const vec4f& b, float alpha);
	};

	inline vec4f operator+(const vec4f& left, const vec4f& right);
	inline vec4f operator-(const vec4f& left, const vec4f& right);

	inline vec4f operator+(const vec4f& left, float value);
	inline vec4f operator-(const vec4f& left, float value);
	inline vec4f operator*(const vec4f& left, float value);
	inline vec4f operator/(const vec4f& left, float value);

	std::ostream& operator<<(std::ostream& stream, const vec4f& vector);
}

#include <math/vec/vec4fImpl.h>
