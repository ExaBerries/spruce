#pragma once
#include <types.h>
#include <math/vec/vec3f.h>
#include <cmath>

namespace spruce {
	class vec4f {
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

			float mag2() const;
			float mag() const;
			vec4f& nor();
			float dst2(const vec4f& vector) const;
			float dst(const vec4f& vector) const;
			float dot(const vec4f& vector) const;

			vec4f& add(const vec4f& vector);
			vec4f& sub(const vec4f& vector);

			vec4f& add(float value);
			vec4f& sub(float value);
			vec4f& scl(float value);
			vec4f& div(float value);

			bool operator==(const vec4f& vector) const;
			bool operator!=(const vec4f& vector) const;

			vec4f& operator+=(const vec4f& vector);
			vec4f& operator-=(const vec4f& vector);

			vec4f& operator+=(float value);
			vec4f& operator-=(float value);
			vec4f& operator*=(float value);
			vec4f& operator/=(float value);

			vec4f& operator=(const vec4f&) = default;
			vec4f& operator=(vec4f&&) noexcept = default;

			static vec4f lerp(const vec4f& a, const vec4f& b, float alpha);
	};

	vec4f operator+(const vec4f& left, const vec4f& right);
	vec4f operator-(const vec4f& left, const vec4f& right);

	vec4f operator+(const vec4f& left, float value);
	vec4f operator-(const vec4f& left, float value);
	vec4f operator*(const vec4f& left, float value);
	vec4f operator/(const vec4f& left, float value);

	std::ostream& operator<<(std::ostream& stream, const vec4f& vector);
}

namespace std {
	template <>
	struct hash<spruce::vec4f> {
		size_t operator()(const spruce::vec4f& v) const {
			return std::hash<float>()(v.x) ^ (std::hash<float>()(v.y) << 1) ^ (std::hash<float>()(v.z) << 2) ^ (std::hash<float>()(v.w) << 3);
		}
	};
}
