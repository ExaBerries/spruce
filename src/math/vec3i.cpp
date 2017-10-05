#include <math/vec3i.h>

namespace spruce {
	vec3i::vec3i() : x(0), y(0), z(0) {
	}

	vec3i::vec3i(int32 x, int32 y, int32 z) : x(x), y(y), z(z) {
	}

	vec3i::vec3i(const vec2i vector, int32 z) : x(vector.x), y(vector.y), z(z) {
	}

	vec3i::~vec3i() {
	}

	float vec3i::mag2() const {
		return x * x + y * y + z * z;
	}

	float vec3i::mag() const {
		return sqrt(mag2());
	}

	float vec3i::dst2(const vec3i& vector) const {
		float dx = vector.x - x;
		float dy = vector.y - y;
		float dz = vector.z - z;
		return dx * dx + dy * dy + dz * dz;
	}

	float vec3i::dst(const vec3i& vector) const {
		return sqrt(dst2(vector));
	}

	float vec3i::dot(const vec3i& vector) const {
		return vector.x * x + vector.y * y + vector.z * z;
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

	vec3i& vec3i::add(const int32& value) {
		x += value;
		y += value;
		z += value;
		return *this;
	}

	vec3i& vec3i::sub(const int32& value) {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	vec3i& vec3i::scl(const int32& value) {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	vec3i& vec3i::div(const int32& value) {
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	vec3i operator+(const vec3i left, const vec3i& right) {
		uint32 x = left.x + right.x;
		uint32 y = left.y + right.y;
		uint32 z = left.z + right.z;
		return vec3i(x, y, z);
	}

	vec3i operator-(const vec3i left, const vec3i& right) {
		uint32 x = left.x - right.x;
		uint32 y = left.y - right.y;
		uint32 z = left.z - right.z;
		return vec3i(x, y, z);
	}

	vec3i operator+(const vec3i left, int32 value) {
		uint32 x = left.x + value;
		uint32 y = left.y + value;
		uint32 z = left.z + value;
		return vec3i(x, y, z);
	}

	vec3i operator-(const vec3i left, int32 value) {
		uint32 x = left.x - value;
		uint32 y = left.y - value;
		uint32 z = left.z - value;
		return vec3i(x, y, z);
	}

	vec3i operator*(const vec3i left, int32 value) {
		uint32 x = left.x * value;
		uint32 y = left.y * value;
		uint32 z = left.z * value;
		return vec3i(x, y, z);
	}

	vec3i operator/(const vec3i left, int32 value) {
		uint32 x = left.x / value;
		uint32 y = left.y / value;
		uint32 z = left.z / value;
		return vec3i(x, y, z);
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

	vec3i& vec3i::operator*=(const uint32 value) {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	vec3i& vec3i::operator/=(const uint32 value) {
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
