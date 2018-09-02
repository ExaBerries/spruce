#pragma once
#include <common.h>
#include <math/vec3f.h>
#include <math.h>

namespace spruce {
	class vec4f {
		public:
			float x;
			float y;
			float z;
			float w;

			vec4f();
			vec4f(const vec4f& vector);
			vec4f(const float& scalar);
			vec4f(const vec3f& vector, const float& w);
			vec4f(const float& x, const float& y, const float& z, const float& w);
			~vec4f();

			vec4f& set(const vec4f& vector);
			vec4f& set(const vec3f& vector, const float w);
			vec4f& set(const float x, const float y, const float z, const float w);

			float mag2() const;
			float mag() const;
			vec4f& nor();
			float dst2(const vec4f& vector) const;
			float dst(const vec4f& vector) const;
			float dot(const vec4f& vector) const;

			vec4f& add(const vec4f& vector);
			vec4f& sub(const vec4f& vector);

			vec4f& add(const float& value);
			vec4f& sub(const float& value);
			vec4f& scl(const float& value);
			vec4f& div(const float& value);

			friend vec4f operator+(const vec4f left, const vec4f& right);
			friend vec4f operator-(const vec4f left, const vec4f& right);

			friend vec4f operator+(const vec4f left, float value);
			friend vec4f operator-(const vec4f left, float value);
			friend vec4f operator*(const vec4f left, float value);
			friend vec4f operator/(const vec4f left, float value);

			bool operator==(const vec4f& vector) const;
			bool operator!=(const vec4f& vector) const;

			vec4f& operator+=(const vec4f& vector);
			vec4f& operator-=(const vec4f& vector);

			vec4f& operator+=(const float& value);
			vec4f& operator-=(const float& value);
			vec4f& operator*=(const float& value);
			vec4f& operator/=(const float& value);

			friend std::ostream& operator<<(std::ostream& stream, const vec4f& vector);

			static vec4f lerp(const vec4f& a, const vec4f& b, float alpha);
	};
}

namespace std {
	template <>
	struct hash<spruce::vec4f> {
		size_t operator()(const spruce::vec4f& v) const {
			return std::hash<float>()(v.x) ^ (std::hash<float>()(v.y) << 1) ^ (std::hash<float>()(v.z) << 2) ^ (std::hash<float>()(v.w) << 3);
		}
	};
}
