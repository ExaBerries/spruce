#pragma once
#include <types.h>
#include <math/vec/vec2d.h>
#include <iostream>
#include <cmath>

namespace spruce {
	struct vec3d {
		double x = 0;
		double y = 0;
		double z = 0;

		vec3d() = default;
		vec3d(double scalar);
		vec3d(const vec2d& vector, double z);
		vec3d(double x, double y, double z);
		vec3d(const vec3d&) = default;
		vec3d(vec3d&&) noexcept = default;
		~vec3d() = default;

		vec3d& set(const vec3d& vector);
		vec3d& set(double x, double y, double z);

		double mag2() const;
		double mag() const;
		vec3d& nor();
		double dst2(const vec3d& vector) const;
		double dst(const vec3d& vector) const;
		double dot(const vec3d& vector) const;
		vec3d& crs(const vec3d& vector);

		vec3d& add(const vec3d& vector);
		vec3d& sub(const vec3d& vector);

		vec3d& add(double value);
		vec3d& sub(double value);
		vec3d& scl(double value);
		vec3d& div(double value);

		bool operator==(const vec3d& vector) const;
		bool operator!=(const vec3d& vector) const;

		vec3d& operator+=(const vec3d& vector);
		vec3d& operator-=(const vec3d& vector);

		vec3d& operator+=(double value);
		vec3d& operator-=(double value);
		vec3d& operator*=(double value);
		vec3d& operator/=(double value);

		vec3d& operator=(const vec3d&) = default;
		vec3d& operator=(vec3d&&) noexcept = default;

		static vec3d lerp(const vec3d& a, const vec3d& b, double alpha);
	};

	vec3d operator+(const vec3d& left, const vec3d& right);
	vec3d operator-(const vec3d& left, const vec3d& right);

	vec3d operator+(const vec3d& left, double value);
	vec3d operator-(const vec3d& left, double value);
	vec3d operator*(const vec3d& left, double value);
	vec3d operator/(const vec3d& left, double value);

	std::ostream& operator<<(std::ostream& stream, const vec3d& vector);
}

namespace std {
	template <>
	struct hash<spruce::vec3d> {
		size_t operator()(const spruce::vec3d& v) const {
			return std::hash<double>()(v.x) ^ (std::hash<double>()(v.y) << 1) ^ (std::hash<double>()(v.z) << 2);
		}
	};
}
