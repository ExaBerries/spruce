#pragma once
#include <types.h>
#include <math/vec/vec2f.h>
#include <iostream>
#include <cmath>

namespace spruce {
	struct vec3f {
		float x = 0;
		float y = 0;
		float z = 0;

		vec3f() = default;
		vec3f(float scalar);
		vec3f(const vec2f& vector, float z);
		vec3f(float x, float y, float z);
		vec3f(const vec3f&) = default;
		vec3f(vec3f&&) noexcept = default;
		~vec3f() = default;

		vec3f& set(const vec3f& vector);
		vec3f& set(const vec2f& vector, float z);
		vec3f& set(float x, float y, float z);

		float mag2() const;
		float mag() const;
		vec3f& nor();
		float dst2(const vec3f& vector) const;
		float dst(const vec3f& vector) const;
		float dot(const vec3f& vector) const;
		vec3f& crs(const vec3f& vector);

		vec3f& add(const vec3f& vector);
		vec3f& sub(const vec3f& vector);

		vec3f& add(float value);
		vec3f& sub(float value);
		vec3f& scl(float value);
		vec3f& div(float value);

		bool operator==(const vec3f& vector) const;
		bool operator!=(const vec3f& vector) const;

		vec3f& operator+=(const vec3f& vector);
		vec3f& operator-=(const vec3f& vector);

		vec3f& operator+=(float value);
		vec3f& operator-=(float value);
		vec3f& operator*=(float value);
		vec3f& operator/=(float value);

		vec3f& operator=(const vec3f&) = default;
		vec3f& operator=(vec3f&&) noexcept = default;

		static vec3f lerp(const vec3f& a, const vec3f& b, float alpha);
	};

	vec3f operator+(const vec3f& left, const vec3f& right);
	vec3f operator-(const vec3f& left, const vec3f& right);

	vec3f operator+(const vec3f& left, float value);
	vec3f operator-(const vec3f& left, float value);
	vec3f operator*(const vec3f& left, float value);
	vec3f operator/(const vec3f& left, float value);

	std::ostream& operator<<(std::ostream& stream, const vec3f& vector);
}

namespace std {
	template <>
	struct hash<spruce::vec3f> {
		size_t operator()(const spruce::vec3f& v) const {
			return std::hash<float>()(v.x) ^ (std::hash<float>()(v.y) << 1) ^ (std::hash<float>()(v.z) << 2);
		}
	};
}
