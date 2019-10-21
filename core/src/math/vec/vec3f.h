#pragma once
#include <types.h>
#include <math/vec/vec2f.h>
#include <util/simd.h>
#include <iostream>
#include <cmath>

namespace spruce {
	struct alignas(alignof(simd::reg4f)) vec3f {
		float x = 0;
		float y = 0;
		float z = 0;

		private:
		[[maybe_unused]] float padding = 0;
		public:

		vec3f() = default;
		vec3f(float scalar);
		vec3f(const vec2f& vector, float z);
		vec3f(float x, float y, float z);
		vec3f(const vec3f&) = default;
		vec3f(vec3f&&) noexcept = default;
		~vec3f() = default;

		vec3f& set(const vec3f& vector) noexcept;
		vec3f& set(const vec2f& vector, float z) noexcept;
		vec3f& set(float x, float y, float z) noexcept;

		[[nodiscard]] float mag2() const noexcept;
		[[nodiscard]] float mag() const noexcept;
		vec3f& nor() noexcept;
		[[nodiscard]] float dst2(const vec3f& vector) const noexcept;
		[[nodiscard]] float dst(const vec3f& vector) const noexcept;
		[[nodiscard]] float dot(const vec3f& vector) const noexcept;
		vec3f& crs(const vec3f& vector) noexcept;

		vec3f& add(const vec3f& vector) noexcept;
		vec3f& sub(const vec3f& vector) noexcept;

		vec3f& add(float value) noexcept;
		vec3f& sub(float value) noexcept;
		vec3f& scl(float value) noexcept;
		vec3f& div(float value) noexcept;

		[[nodiscard]] bool operator==(const vec3f& vector) const noexcept;
		[[nodiscard]] bool operator!=(const vec3f& vector) const noexcept;

		vec3f& operator+=(const vec3f& vector) noexcept;
		vec3f& operator-=(const vec3f& vector) noexcept;

		vec3f& operator+=(float value) noexcept;
		vec3f& operator-=(float value) noexcept;
		vec3f& operator*=(float value) noexcept;
		vec3f& operator/=(float value) noexcept;

		vec3f& operator=(const vec3f&) = default;
		vec3f& operator=(vec3f&&) noexcept = default;

		[[nodiscard]] static vec3f lerp(const vec3f& a, const vec3f& b, float alpha) noexcept;
	};

	inline vec3f operator+(const vec3f& left, const vec3f& right) noexcept;
	inline vec3f operator-(const vec3f& left, const vec3f& right) noexcept;

	inline vec3f operator+(const vec3f& left, float value) noexcept;
	inline vec3f operator-(const vec3f& left, float value) noexcept;
	inline vec3f operator*(const vec3f& left, float value) noexcept;
	inline vec3f operator/(const vec3f& left, float value) noexcept;

	std::ostream& operator<<(std::ostream& stream, const vec3f& vector);
}

namespace std {
	template <>
	struct hash<spruce::vec3f>;
}

#include <math/vec/vec3fImpl.h>
