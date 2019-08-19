#include <math/vec/vec4f.h>

namespace spruce {
	vec4f::vec4f(float scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {
	}

	vec4f::vec4f(const vec3f& vector, float w) : x(vector.x), y(vector.y), z(vector.z), w(w) {
	}

	vec4f::vec4f(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {
	}

	vec4f& vec4f::set(const vec4f& vector) {
		x = vector.x;
		y = vector.y;
		z = vector.z;
		w = vector.w;
		return *this;
	}

	vec4f& vec4f::set(const vec3f& vector, float w) {
		x = vector.x;
		y = vector.y;
		z = vector.z;
		this->w = w;
		return *this;
	}

	vec4f& vec4f::set(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		return *this;
	}

	float vec4f::mag2() const {
		return x * x + y * y + z * z + w * w;
	}

	float vec4f::mag() const {
		return sqrt(mag2());
	}

	vec4f& vec4f::nor() {
		float mag2 = vec4f::mag2();
		if (mag2 != 0 && mag2 != 1) {
			float mag = sqrt(mag2);
			x /= mag;
			y /= mag;
			z /= mag;
			w /= mag;
		}
		return *this;
	}

	float vec4f::dst2(const vec4f& vector) const {
		float dx = vector.x - x;
		float dy = vector.y - y;
		float dz = vector.z - z;
		float dw = vector.w - w;
		return dx * dx + dy * dy + dz * dz + dw * dw;
	}

	float vec4f::dst(const vec4f& vector) const {
		return sqrt(dst2(vector));
	}

	float vec4f::dot(const vec4f& vector) const {
		return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
	}

	vec4f& vec4f::add(const vec4f& vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
		return *this;
	}

	vec4f& vec4f::sub(const vec4f& vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
		return *this;
	}

	vec4f& vec4f::add(float value) {
		x += value;
		y += value;
		z += value;
		w += value;
		return *this;
	}

	vec4f& vec4f::sub(float value) {
		x -= value;
		y -= value;
		z -= value;
		w -= value;
		return *this;
	}

	vec4f& vec4f::scl(float value) {
		x *= value;
		y *= value;
		z *= value;
		w *= value;
		return *this;
	}

	vec4f& vec4f::div(float value) {
		x /= value;
		y /= value;
		z /= value;
		w /= value;
		return *this;
	}

	vec4f operator+(const vec4f left, const vec4f& right) {
		float x = left.x + right.x;
		float y = left.y + right.y;
		float z = left.z + right.z;
		float w = left.w + right.w;
		return {x, y, z, w};
	}

	vec4f operator-(const vec4f& left, const vec4f& right) {
		float x = left.x - right.x;
		float y = left.y - right.y;
		float z = left.z - right.z;
		float w = left.w - right.w;
		return {x, y, z, w};
	}

	vec4f operator+(const vec4f& left, float value) {
		float x = left.x + value;
		float y = left.y + value;
		float z = left.z + value;
		float w = left.w + value;
		return {x, y, z, w};
	}

	vec4f operator-(const vec4f &left, float value) {
		float x = left.x - value;
		float y = left.y - value;
		float z = left.z - value;
		float w = left.w - value;
		return {x, y, z, w};
	}

	vec4f operator*(const vec4f& left, float value) {
		float x = left.x * value;
		float y = left.y * value;
		float z = left.z * value;
		float w = left.w * value;
		return {x, y, z, w};
	}

	vec4f operator/(const vec4f& left, float value) {
		float x = left.x / value;
		float y = left.y / value;
		float z = left.z / value;
		float w = left.w / value;
		return {x, y, z, w};
	}

	bool vec4f::operator==(const vec4f& vector) const {
		return (x == vector.x && y == vector.y && z == vector.z && w == vector.w);
	}

	bool vec4f::operator!=(const vec4f& vector) const {
		return (x != vector.x || y != vector.y || z != vector.z || w != vector.w);
	}

	vec4f& vec4f::operator+=(const vec4f& vector) {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
		return *this;
	}

	vec4f& vec4f::operator-=(const vec4f& vector) {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
		return *this;
	}

	vec4f& vec4f::operator+=(float value) {
		x += value;
		y += value;
		z += value;
		w += value;
		return *this;
	}

	vec4f& vec4f::operator-=(float value) {
		x -= value;
		y -= value;
		z -= value;
		w -= value;
		return *this;
	}

	vec4f& vec4f::operator*=(float value) {
		x *= value;
		y *= value;
		z *= value;
		w *= value;
		return *this;
	}

	vec4f& vec4f::operator/=(float value) {
		x /= value;
		y /= value;
		z /= value;
		w /= value;
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const vec4f& vector) {
		std::cout << "vec4f(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return stream;
	}

	vec4f lerp(const vec4f& a, const vec4f& b, float alpha) {
		float oneMinuaAlpha = 1 - alpha;
		return vec4f(oneMinuaAlpha * a.x + alpha * b.x, oneMinuaAlpha * a.y + alpha * b.y, oneMinuaAlpha * a.z + alpha * b.z, oneMinuaAlpha * a.w + alpha * b.w);
	}

}
