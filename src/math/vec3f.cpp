#include "vec3f.h"

namespace spruce {
	vec3f::vec3f() : x(0), y(0), z(0) {
	}

	vec3f::vec3f(const float& scalar) : x(scalar), y(scalar), z(scalar) {
	}

	vec3f::vec3f(const vec2f& vector, const float& z) : x(vector.x), y(vector.y), z(z) {
	}

	vec3f::vec3f(const float& x, const float& y, const float& z) : x(x), y(y), z(z) {
	}

	float vec3f::mag2() const {
		return x * x + y * y + z * z;
	}

	float vec3f::mag() const {
		return sqrt(mag2());
	}

	vec3f& vec3f::nor() {
		float mag2 = vec3f::mag2();
		if (mag2 != 0 && mag2 != 1) {
			float mag = sqrt(mag2);
			x /= mag;
			y /= mag;
			z /= mag;
		}
		return *this;
	}

	float vec3f::dst2(const vec3f& vector) const {
		float dx = vector.x - x;
		float dy = vector.y - y;
		float dz = vector.z - z;
		return dx * dx + dy * dy + dz * dz;
	}

	float vec3f::dst(const vec3f& vector) const {
		return sqrt(dst2(vector));
	}

	float vec3f::dot(const vec3f& vector) const {
		return vector.x * x + vector.y * y + vector.z * z;
	}

	vec3f& vec3f::crs(const vec3f& vector) {
		float x = this->y * vector.z - this->z * vector.y;
		float y = this->z * vector.x - this->x * vector.z;
		float z = this->x * vector.y - this->y * vector.x;
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}

	vec3f& vec3f::add(const vec3f& vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	vec3f& vec3f::sub(const vec3f& vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	vec3f& vec3f::add(const float& value) {
		x += value;
		y += value;
		z += value;
		return *this;
	}

	vec3f& vec3f::sub(const float& value) {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	vec3f& vec3f::scl(const float& value) {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	vec3f& vec3f::div(const float& value) {
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	vec3f operator+(const vec3f left, const vec3f& right) {
		float x = left.x + right.x;
		float y = left.y + right.y;
		float z = left.z + right.z;
		return vec3f(x, y, z);
	}

	vec3f operator-(const vec3f left, const vec3f& right) {
		float x = left.x - right.x;
		float y = left.y - right.y;
		float z = left.z - right.z;
		return vec3f(x, y, z);
	}

	vec3f operator+(const vec3f left, float value) {
		float x = left.x + value;
		float y = left.y + value;
		float z = left.z + value;
		return vec3f(x, y, z);
	}

	vec3f operator-(const vec3f left, float value) {
		float x = left.x - value;
		float y = left.y - value;
		float z = left.z - value;
		return vec3f(x, y, z);
	}

	vec3f operator*(const vec3f left, float value) {
		float x = left.x * value;
		float y = left.y * value;
		float z = left.z * value;
		return vec3f(x, y, z);
	}

	vec3f operator/(const vec3f left, float value) {
		float x = left.x / value;
		float y = left.y / value;
		float z = left.z / value;
		return vec3f(x, y, z);
	}

	bool operator==(const vec3f& left, const vec3f& right) {
		return (left.x == right.x && left.y == right.y && left.z == right.z);
	}

	bool operator!=(const vec3f& left, const vec3f& right) {
		return (left.x != right.x || left.y != right.y || left.z != right.z);
	}

	vec3f& vec3f::operator+=(const vec3f& vector) {
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
		return *this;
	}

	vec3f& vec3f::operator-=(const vec3f& vector) {
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;
		return *this;
	}

	vec3f& vec3f::operator+=(const float& value) {
		this->x += value;
		this->y += value;
		this->z += value;
		return *this;
	}

	vec3f& vec3f::operator-=(const float& value) {
		this->x -= value;
		this->y -= value;
		this->z -= value;
		return *this;
	}

	vec3f& vec3f::operator*=(const float& value) {
		this->x *= value;
		this->y *= value;
		this->z *= value;
		return *this;
	}

	vec3f& vec3f::operator/=(const float& value) {
		this->x /= value;
		this->y /= value;
		this->z /= value;
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const vec2f& vector) {
		std::cout << "vec3f(" << vector.x << ", " << vector.y << ")" << std::endl;
		return stream;
	}

	extern void log(const vec3f& vector) {
		std::cout << "vec3f(" << vector.x << ", " << vector.y << ")" << std::endl;
	}
}
