#include <math/vec/vec3i.h>

namespace spruce {
	vec3i::vec3i(int32 x, int32 y, int32 z) : x(x), y(y), z(z) {
	}

	vec3i::vec3i(const vec2i& vector, int32 z) : x(vector.x), y(vector.y), z(z) {
	}

	float vec3i::mag2() const {
		return static_cast<float>(x * x + y * y + z * z);
	}

	float vec3i::mag() const {
		return std::sqrt(mag2());
	}

	float vec3i::dst2(const vec3i& vector) const {
		int32 dx = vector.x - x;
		int32 dy = vector.y - y;
		int32 dz = vector.z - z;
		return static_cast<float>(dx * dx + dy * dy + dz * dz);
	}

	float vec3i::dst(const vec3i& vector) const {
		return sqrt(dst2(vector));
	}

	float vec3i::dot(const vec3i& vector) const {
		return static_cast<float>(vector.x * x + vector.y * y + vector.z * z);
	}

	vec3i& vec3i::add(const vec3i& vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	vec3i& vec3i::sub(const vec3i& vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	vec3i& vec3i::add(int32 value) {
		x += value;
		y += value;
		z += value;
		return *this;
	}

	vec3i& vec3i::sub(int32 value) {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	vec3i& vec3i::scl(int32 value) {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	vec3i& vec3i::div(int32 value) {
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	vec3i operator+(const vec3i left, const vec3i& right) {
		int32 x = left.x + right.x;
		int32 y = left.y + right.y;
		int32 z = left.z + right.z;
		return {x, y, z};
	}

	vec3i operator-(const vec3i left, const vec3i& right) {
		int32 x = left.x - right.x;
		int32 y = left.y - right.y;
		int32 z = left.z - right.z;
		return {x, y, z};
	}

	vec3i operator+(const vec3i left, int32 value) {
		int32 x = left.x + value;
		int32 y = left.y + value;
		int32 z = left.z + value;
		return {x, y, z};
	}

	vec3i operator-(const vec3i left, int32 value) {
		int32 x = left.x - value;
		int32 y = left.y - value;
		int32 z = left.z - value;
		return {x, y, z};
	}

	vec3i operator%(const vec3i left, int32 value) {
		int32 x = left.x % value;
		int32 y = left.y % value;
		int32 z = left.y % value;
		return {x, y, z};
	}

	vec3i operator*(const vec3i left, int32 value) {
		int32 x = left.x * value;
		int32 y = left.y * value;
		int32 z = left.z * value;
		return {x, y, z};
	}

	vec3i operator/(const vec3i left, int32 value) {
		int32 x = left.x / value;
		int32 y = left.y / value;
		int32 z = left.z / value;
		return {x, y, z};
	}

	bool vec3i::operator==(const vec3i& vector) const {
		return (x == vector.x && y == vector.y && z == vector.z);
	}

	bool vec3i::operator!=(const vec3i& vector) const {
		return (x != vector.x || y != vector.y || z != vector.z);
	}

	vec3i& vec3i::operator+=(const vec3i& vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	vec3i& vec3i::operator-=(const vec3i& vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	vec3i& vec3i::operator+=(int32 value) {
		x += value;
		y += value;
		z += value;
		return *this;
	}

	vec3i& vec3i::operator-=(int32 value) {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	vec3i& vec3i::operator %=(int32 value) {
		x %= value;
		y %= value;
		z %= value;
		return *this;
	}

	vec3i& vec3i::operator*=(int32 value) {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	vec3i& vec3i::operator/=(int32 value) {
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const vec3i& vector) {
		stream << "vec3i(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}
}
