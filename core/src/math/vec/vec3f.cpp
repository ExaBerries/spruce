#include <math/vec/vec3f.h>

namespace spruce {
	vec3f::vec3f(float scalar) : x(scalar), y(scalar), z(scalar) {}

	vec3f::vec3f(const vec2f& vector, float z) : x(vector.x), y(vector.y), z(z) {}

	vec3f::vec3f(float x, float y, float z) : x(x), y(y), z(z) {}

	vec3f& vec3f::set(const vec3f& vector) {
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
		return *this;
	}

	vec3f& vec3f::set(const vec2f& vector, float z) {
		this->x = vector.x;
		this->y = vector.y;
		this->z = z;
		return *this;
	}

	vec3f& vec3f::set(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
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

	vec3f& vec3f::add(float value) {
		x += value;
		y += value;
		z += value;
		return *this;
	}

	vec3f& vec3f::sub(float value) {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	vec3f& vec3f::scl(float value) {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	vec3f& vec3f::div(float value) {
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	bool vec3f::operator==(const vec3f& vector) const {
		return (x == vector.x && y == vector.y && z == vector.z);
	}

	bool vec3f::operator!=(const vec3f& vector) const {
		return (x != vector.x || y != vector.y || z != vector.z);
	}

	std::ostream& operator<<(std::ostream& stream, const vec3f& vector) {
		stream << "vec3f(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

	vec3f vec3f::lerp(const vec3f& a, const vec3f& b, float alpha) {
		return vec3f((1 - alpha) * a.x + alpha * b.x, (1 - alpha) * a.y + alpha * b.y, (1 - alpha) * a.z + alpha * b.z);
	}
}
