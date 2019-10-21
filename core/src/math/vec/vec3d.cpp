#include <math/vec/vec3d.h>

namespace spruce {

	vec3d::vec3d(double scalar) : x(scalar), y(scalar), z(scalar) {
	}

	vec3d::vec3d(const vec2d& vector, double z) : x(vector.x), y(vector.y), z(z) {
	}

	vec3d::vec3d(double x, double y, double z) : x(x), y(y), z(z) {
	}

	vec3d& vec3d::set(const vec3d& vector) noexcept {
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
		return *this;
	}

	vec3d& vec3d::set(double x, double y, double z) noexcept {
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}

	double vec3d::mag2() const noexcept {
		return x * x + y * y + z * z;
	}

	double vec3d::mag() const noexcept {
		return std::sqrt(mag2());
	}

	vec3d& vec3d::nor() noexcept {
		double mag2 = vec3d::mag2();
		if (mag2 != 0 && mag2 != 1) {
			double mag = std::sqrt(mag2);
			x /= mag;
			y /= mag;
			z /= mag;
		}
		return *this;
	}

	double vec3d::dst2(const vec3d& vector) const noexcept {
		double dx = vector.x - x;
		double dy = vector.y - y;
		double dz = vector.z - z;
		return dx * dx + dy * dy + dz * dz;
	}

	double vec3d::dst(const vec3d& vector) const noexcept {
		return std::sqrt(dst2(vector));
	}

	double vec3d::dot(const vec3d& vector) const noexcept {
		return vector.x * x + vector.y * y + vector.z * z;
	}

	vec3d& vec3d::crs(const vec3d& vector) noexcept {
		double x = this->y * vector.z - this->z * vector.y;
		double y = this->z * vector.x - this->x * vector.z;
		double z = this->x * vector.y - this->y * vector.x;
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}

	vec3d& vec3d::add(const vec3d& vector) noexcept {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	vec3d& vec3d::sub(const vec3d& vector) noexcept {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	vec3d& vec3d::add(double value) noexcept {
		x += value;
		y += value;
		z += value;
		return *this;
	}

	vec3d& vec3d::sub(double value) noexcept {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	vec3d& vec3d::scl(double value) noexcept {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	vec3d& vec3d::div(double value) noexcept {
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	bool vec3d::operator==(const vec3d& vector) const noexcept {
		return (x == vector.x && y == vector.y && z == vector.z);
	}

	bool vec3d::operator!=(const vec3d& vector) const noexcept {
		return (x != vector.x || y != vector.y || z != vector.z);
	}

	vec3d& vec3d::operator+=(const vec3d& vector) noexcept {
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
		return *this;
	}

	vec3d& vec3d::operator-=(const vec3d& vector) noexcept {
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;
		return *this;
	}

	vec3d& vec3d::operator+=(double value) noexcept {
		this->x += value;
		this->y += value;
		this->z += value;
		return *this;
	}

	vec3d& vec3d::operator-=(double value) noexcept {
		this->x -= value;
		this->y -= value;
		this->z -= value;
		return *this;
	}

	vec3d& vec3d::operator*=(double value) noexcept {
		this->x *= value;
		this->y *= value;
		this->z *= value;
		return *this;
	}

	vec3d& vec3d::operator/=(double value) noexcept {
		this->x /= value;
		this->y /= value;
		this->z /= value;
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const vec3d& vector) {
		stream << "vec3d(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

	vec3d vec3d::lerp(const vec3d& a, const vec3d& b, double alpha) noexcept {
		return vec3d((1 - alpha) * a.x + alpha * b.x, (1 - alpha) * a.y + alpha * b.y, (1 - alpha) * a.z + alpha * b.z);
	}
}
