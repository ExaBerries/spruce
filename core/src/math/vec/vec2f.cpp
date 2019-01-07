#include <math/vec/vec2f.h>

namespace spruce {
	vec2f::vec2f(float scalar) : x(scalar), y(scalar) {
	}

	vec2f::vec2f(float x, float y) : x(x), y(y) {
	}

	float vec2f::mag2() const {
		return x * x + y * y;
	}

	float vec2f::mag() const {
		return sqrt(mag2());
	}

	vec2f& vec2f::nor() {
		float mag2 = vec2f::mag2();
		if (mag2 != 0 && mag2 != 1) {
			float mag = sqrt(mag2);
			x /= mag;
			y /= mag;
		}
		return *this;
	}

	float vec2f::dst2(const vec2f& vector) const {
		float dx = vector.x - x;
		float dy = vector.y - y;
		return dx * dx + dy * dy;
	}

	float vec2f::dst(const vec2f& vector) const {
		return sqrt(dst2(vector));
	}

	float vec2f::dot(const vec2f& vector) const {
		return x * vector.x + y * vector.y;
	}

	vec2f& vec2f::add(const vec2f& vector) {
		x += vector.x;
		y += vector.y;
		return *this;
	}

	vec2f& vec2f::sub(const vec2f& vector) {
		x -= vector.x;
		y -= vector.y;
		return *this;
	}

	vec2f& vec2f::add(float value) {
		x += value;
		y += value;
		return *this;
	}

	vec2f& vec2f::sub(float value) {
		x -= value;
		y -= value;
		return *this;
	}

	vec2f& vec2f::scl(float value) {
		x *= value;
		y *= value;
		return *this;
	}

	vec2f& vec2f::div(float value) {
		x /= value;
		y /= value;
		return *this;
	}

	vec2f operator+(const vec2f& left, const vec2f& right) {
		float x = left.x + right.x;
		float y = left.y + right.y;
		return {x, y};
	}

	vec2f operator-(const vec2f& left, const vec2f& right) {
		float x = left.x - right.x;
		float y = left.y - right.y;
		return {x, y};
	}

	vec2f operator+(const vec2f& left, float value) {
		float x = left.x + value;
		float y = left.y + value;
		return {x, y};
	}

	vec2f operator-(const vec2f& left, float value) {
		float x = left.x - value;
		float y = left.y - value;
		return {x, y};
	}

	vec2f operator*(const vec2f& left, float value) {
		float x = left.x * value;
		float y = left.y * value;
		return {x, y};
	}

	vec2f operator/(const vec2f& left, float value) {
		float x = left.x / value;
		float y = left.y / value;
		return {x, y};
	}

	bool vec2f::operator==(const vec2f& vector) const {
		return (x == vector.x && y == vector.y);
	}

	bool vec2f::operator!=(const vec2f& vector) const {
		return (x != vector.x || y != vector.x);
	}

	vec2f& vec2f::operator+=(const vec2f& vector) {
		this->x += vector.x;
		this->y += vector.y;
		return *this;
	}

	vec2f& vec2f::operator-=(const vec2f& vector) {
		this->x -= vector.x;
		this->y -= vector.y;
		return *this;
	}

	vec2f& vec2f::operator+=(float value) {
		this->x += value;
		this->y += value;
		return *this;
	}

	vec2f& vec2f::operator-=(float value) {
		this->x -= value;
		this->y -= value;
		return *this;
	}

	vec2f& vec2f::operator*=(float value) {
		this->x *= value;
		this->y *= value;
		return *this;
	}

	vec2f& vec2f::operator/=(float value) {
		this->x /= value;
		this->y /= value;
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const vec2f& vector) {
		stream << "vec2f(" << vector.x << ", " << vector.y << ")";
		return stream;
	}

	vec2f vec2f::lerp(const vec2f& a, const vec2f& b, float alpha) {
		return vec2f((1 - alpha) * a.x + alpha * b.x, (1 - alpha) * a.y + alpha * b.y);
	}
}
