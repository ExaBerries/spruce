#pragma once
#include <common.h>
#include <math/vec2d.h>
#include <iostream>
#include <math.h>

namespace spruce {
	struct vec3d {
		double x;
		double y;
		double z;

		vec3d();
		vec3d(const vec3d& vector);
		vec3d(const double& scalar);
		vec3d(const vec2d& vector, const double& z);
		vec3d(const double& x, const double& y, const double& z);
		virtual ~vec3d();

		vec3d& set(const vec3d& vector);
		vec3d& set(const double x, const double y, const double z);

		double mag2() const;
		double mag() const;
		vec3d& nor();
		double dst2(const vec3d& vector) const;
		double dst(const vec3d& vector) const;
		double dot(const vec3d& vector) const;
		vec3d& crs(const vec3d& vector);

		vec3d& add(const vec3d& vector);
		vec3d& sub(const vec3d& vector);

		vec3d& add(const double& value);
		vec3d& sub(const double& value);
		vec3d& scl(const double& value);
		vec3d& div(const double& value);

		friend vec3d operator+(const vec3d left, const vec3d& right);
		friend vec3d operator-(const vec3d left, const vec3d& right);

		friend vec3d operator+(const vec3d left, double value);
		friend vec3d operator-(const vec3d left, double value);
		friend vec3d operator*(const vec3d left, double value);
		friend vec3d operator/(const vec3d left, double value);

		bool operator==(const vec3d& vector) const;
		bool operator!=(const vec3d& vector) const;

		vec3d& operator+=(const vec3d& vector);
		vec3d& operator-=(const vec3d& vector);

		vec3d& operator+=(const double& value);
		vec3d& operator-=(const double& value);
		vec3d& operator*=(const double& value);
		vec3d& operator/=(const double& value);

		friend std::ostream& operator<<(std::ostream& stream, const vec3d& vector);
	};

	void log(const vec3d& vector);
}
