#pragma once
#include <types.h>
#include <math/vec/vec2f.h>
#include <iostream>
#include <math.h>

namespace spruce {
	struct vec3f {
		float x;
		float y;
		float z;

		vec3f();
		vec3f(const vec3f& vector);
		vec3f(const float& scalar);
		vec3f(const vec2f& vector, const float& z);
		vec3f(const float& x, const float& y, const float& z);
		~vec3f();

		vec3f& set(const vec3f& vector);
		vec3f& set(const vec2f& vector, const float z);
		vec3f& set(const float x, const float y, const float z);

		float mag2() const;
		float mag() const;
		vec3f& nor();
		float dst2(const vec3f& vector) const;
		float dst(const vec3f& vector) const;
		float dot(const vec3f& vector) const;
		vec3f& crs(const vec3f& vector);

		vec3f& add(const vec3f& vector);
		vec3f& sub(const vec3f& vector);

		vec3f& add(const float& value);
		vec3f& sub(const float& value);
		vec3f& scl(const float& value);
		vec3f& div(const float& value);

		friend vec3f operator+(const vec3f left, const vec3f& right);
		friend vec3f operator-(const vec3f left, const vec3f& right);

		friend vec3f operator+(const vec3f left, float value);
		friend vec3f operator-(const vec3f left, float value);
		friend vec3f operator*(const vec3f left, float value);
		friend vec3f operator/(const vec3f left, float value);

		bool operator==(const vec3f& vector) const;
		bool operator!=(const vec3f& vector) const;

		vec3f& operator+=(const vec3f& vector);
		vec3f& operator-=(const vec3f& vector);

		vec3f& operator+=(const float& value);
		vec3f& operator-=(const float& value);
		vec3f& operator*=(const float& value);
		vec3f& operator/=(const float& value);

		friend std::ostream& operator<<(std::ostream& stream, const vec3f& vector);

		static vec3f lerp(const vec3f& a, const vec3f& b, float alpha);
	};
}

namespace std {
	template <>
	struct hash<spruce::vec3f> {
		size_t operator()(const spruce::vec3f& v) const {
			return std::hash<float>()(v.x) ^ (std::hash<float>()(v.y) << 1) ^ (std::hash<float>()(v.z) << 2);
		}
	};
}