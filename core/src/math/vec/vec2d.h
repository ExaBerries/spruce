#pragma once
#include <types.h>
#include <log.h>
#include <math.h>

namespace spruce {
	struct vec2d {
		double x;
		double y;

		vec2d();
		vec2d(const vec2d& vector);
		vec2d(const double& scalar);
		vec2d(const double& x, const double& y);
		~vec2d();

		double mag2() const;
		double mag() const;
		vec2d& nor();
		double dst2(const vec2d& vector) const;
		double dst(const vec2d& vector) const;
		double dot(const vec2d& vector) const;

		vec2d& add(const vec2d& vector);
		vec2d& sub(const vec2d& vector);

		vec2d& add(const double& value);
		vec2d& sub(const double& value);
		vec2d& scl(const double& value);
		vec2d& div(const double& value);

		friend vec2d operator+(const vec2d left, const vec2d& right);
		friend vec2d operator-(const vec2d left, const vec2d& right);

		friend vec2d operator+(const vec2d left, double value);
		friend vec2d operator-(const vec2d left, double value);
		friend vec2d operator*(const vec2d left, double value);
		friend vec2d operator/(const vec2d left, double value);

		bool operator==(const vec2d& vector) const;
		bool operator!=(const vec2d& vector) const;

		vec2d& operator+=(const vec2d& vector);
		vec2d& operator-=(const vec2d& vector);

		vec2d& operator+=(const double& value);
		vec2d& operator-=(const double& value);
		vec2d& operator*=(const double& value);
		vec2d& operator/=(const double& value);

		friend std::ostream& operator<<(std::ostream& stream, const vec2d& vector);

		static vec2d lerp(const vec2d& a, const vec2d& b, double alpha);
	};
}

namespace std {
	template <>
	struct hash<spruce::vec2d> {
		size_t operator()(const spruce::vec2d& v) const {
			return std::hash<double>()(v.x) ^ (std::hash<double>()(v.y) << 1);
		}
	};
}