#include <math/vec3d.h>

namespace spruce {
	vec3d::vec3d() : x(0), y(0), z(0) {
	}

	vec3d::vec3d(const vec3d& vector) : x(vector.x), y(vector.y), z(vector.z) {
	}

	vec3d::vec3d(const double& scalar) : x(scalar), y(scalar), z(scalar) {
	}

	vec3d::vec3d(const vec2d& vector, const double& z) : x(vector.x), y(vector.y), z(z) {
	}

	vec3d::vec3d(const double& x, const double& y, const double& z) : x(x), y(y), z(z) {
	}

	vec3d::~vec3d() {
	}

	vec3d& vec3d::set(const vec3d& vector) {
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
		return *this;
	}

	vec3d& vec3d::set(const double x, const double y, const double z) {
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}

	double vec3d::mag2() const {
		return x * x + y * y + z * z;
	}

	double vec3d::mag() const {
		return sqrt(mag2());
	}

	vec3d& vec3d::nor() {
		double mag2 = vec3d::mag2();
		if (mag2 != 0 && mag2 != 1) {
			double mag = sqrt(mag2);
			x /= mag;
			y /= mag;
			z /= mag;
		}
		return *this;
	}

	double vec3d::dst2(const vec3d& vector) const {
		double dx = vector.x - x;
		double dy = vector.y - y;
		double dz = vector.z - z;
		return dx * dx + dy * dy + dz * dz;
	}

	double vec3d::dst(const vec3d& vector) const {
		return sqrt(dst2(vector));
	}

	double vec3d::dot(const vec3d& vector) const {
		return vector.x * x + vector.y * y + vector.z * z;
	}

	vec3d& vec3d::crs(const vec3d& vector) {
		double x = this->y * vector.z - this->z * vector.y;
		double y = this->z * vector.x - this->x * vector.z;
		double z = this->x * vector.y - this->y * vector.x;
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}

	vec3d& vec3d::add(const vec3d& vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	vec3d& vec3d::sub(const vec3d& vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	vec3d& vec3d::add(const double& value) {
		x += value;
		y += value;
		z += value;
		return *this;
	}

	vec3d& vec3d::sub(const double& value) {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	vec3d& vec3d::scl(const double& value) {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	vec3d& vec3d::div(const double& value) {
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	vec3d operator+(const vec3d left, const vec3d& right) {
		double x = left.x + right.x;
		double y = left.y + right.y;
		double z = left.z + right.z;
		return vec3d(x, y, z);
	}

	vec3d operator-(const vec3d left, const vec3d& right) {
		double x = left.x - right.x;
		double y = left.y - right.y;
		double z = left.z - right.z;
		return vec3d(x, y, z);
	}

	vec3d operator+(const vec3d left, double value) {
		double x = left.x + value;
		double y = left.y + value;
		double z = left.z + value;
		return vec3d(x, y, z);
	}

	vec3d operator-(const vec3d left, double value) {
		double x = left.x - value;
		double y = left.y - value;
		double z = left.z - value;
		return vec3d(x, y, z);
	}

	vec3d operator*(const vec3d left, double value) {
		double x = left.x * value;
		double y = left.y * value;
		double z = left.z * value;
		return vec3d(x, y, z);
	}

	vec3d operator/(const vec3d left, double value) {
		double x = left.x / value;
		double y = left.y / value;
		double z = left.z / value;
		return vec3d(x, y, z);
	}

	bool operator==(const vec3d& left, const vec3d& right) {
		return (left.x == right.x && left.y == right.y && left.z == right.z);
	}

	bool operator!=(const vec3d& left, const vec3d& right) {
		return (left.x != right.x || left.y != right.y || left.z != right.z);
	}

	vec3d& vec3d::operator+=(const vec3d& vector) {
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
		return *this;
	}

	vec3d& vec3d::operator-=(const vec3d& vector) {
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;
		return *this;
	}

	vec3d& vec3d::operator+=(const double& value) {
		this->x += value;
		this->y += value;
		this->z += value;
		return *this;
	}

	vec3d& vec3d::operator-=(const double& value) {
		this->x -= value;
		this->y -= value;
		this->z -= value;
		return *this;
	}

	vec3d& vec3d::operator*=(const double& value) {
		this->x *= value;
		this->y *= value;
		this->z *= value;
		return *this;
	}

	vec3d& vec3d::operator/=(const double& value) {
		this->x /= value;
		this->y /= value;
		this->z /= value;
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const vec3d& vector) {
		std::cout << "vec3d(" << vector.x << ", " << vector.y << ", " << vector.z << ")" << std::endl;
		return stream;
	}

	void log(const vec3d& vector) {
		std::cout << vector << std::endl;
	}
}
