#pragma once
#include <types.h>
#include <log.h>
#include <cmath>

namespace spruce {
	struct vec2d {
		double x = 0;
		double y = 0;

		vec2d() = default;
		vec2d(double scalar);
		vec2d(double x, double y);
		vec2d(const vec2d&) = default;
		vec2d(vec2d&&) noexcept = default;
		~vec2d() = default;

		double mag2() const;
		double mag() const;
		vec2d& nor();
		double dst2(const vec2d& vector) const;
		double dst(const vec2d& vector) const;
		double dot(const vec2d& vector) const;

		vec2d& add(const vec2d& vector);
		vec2d& sub(const vec2d& vector);

		vec2d& add(double value);
		vec2d& sub(double value);
		vec2d& scl(double value);
		vec2d& div(double value);

		bool operator==(const vec2d& vector) const;
		bool operator!=(const vec2d& vector) const;

		vec2d& operator+=(const vec2d& vector);
		vec2d& operator-=(const vec2d& vector);

		vec2d& operator+=(double value);
		vec2d& operator-=(double value);
		vec2d& operator*=(double value);
		vec2d& operator/=(double value);

		vec2d& operator=(const vec2d&) = default;
		vec2d& operator=(vec2d&&) noexcept = default;

		static vec2d lerp(const vec2d& a, const vec2d& b, double alpha);
	};

	vec2d operator+(const vec2d& left, const vec2d& right);
	vec2d operator-(const vec2d& left, const vec2d& right);

	vec2d operator+(const vec2d& left, double value);
	vec2d operator-(const vec2d& left, double value);
	vec2d operator*(const vec2d& left, double value);
	vec2d operator/(const vec2d& left, double value);

	std::ostream& operator<<(std::ostream& stream, const vec2d& vector);
}

namespace std {
	template <>
	struct hash<spruce::vec2d> {
		size_t operator()(const spruce::vec2d& v) const {
			return std::hash<double>()(v.x) ^ (std::hash<double>()(v.y) << 1);
		}
	};
}
