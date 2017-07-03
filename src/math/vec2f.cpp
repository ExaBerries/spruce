#include "vec2f.h"

namespace spruce {
	vec2f::vec2f() : x(0), y(0) {
	}

	vec2f::vec2f(const float& scalar) : x(scalar), y(scalar) {
	}

	vec2f::vec2f(const float& x, const float& y) : x(x), y(y) {
	}

	float vec2f::mag2() const {
		return x * x + y * y;
	}

	float vec2f::mag() const {
		return sqrt(mag2());
	}

	vec2f& vec2f::nor() {
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

	vec2f& vec2f::add(const float& value) {
		x += value;
		y += value;
		return *this;
	}

	vec2f& vec2f::sub(const float& value) {
		x -= value;
		y -= value;
		return *this;
	}

	vec2f& vec2f::scl(const float& value) {
		x *= value;
		y *= value;
		return *this;
	}

	vec2f& vec2f::div(const float& value) {
		x /= value;
		y /= value;
		return *this;
	}

	vec2f operator+(vec2f left, const vec2f& right) {
		float x = left.x + right.x;
		float y = left.y + right.y;
		return vec2f(x, y);
	}

	vec2f operator-(vec2f left, const vec2f& right) {
		float x = left.x - right.x;
		float y = left.y - right.y;
		return vec2f(x, y);
	}

	vec2f operator+(vec2f left, float value) {
		float x = left.x + value;
		float y = left.y + value;
		return vec2f(x, y);
	}

	vec2f operator-(vec2f left, float value) {
		float x = left.x - value;
		float y = left.y - value;
		return vec2f(x, y);
	}

	vec2f operator*(vec2f left, float value) {
		float x = left.x * value;
		float y = left.y * value;
		return vec2f(x, y);
	}

	vec2f operator/(vec2f left, float value) {
		float x = left.x / value;
		float y = left.y / value;
		return vec2f(x, y);
	}

	bool operator==(const vec2f& left, const vec2f& right) {
		return (left.x == right.x && left.y == right.y);
	}

	bool operator!=(const vec2f& left, const vec2f& right) {
		return (left.x != right.x || left.y != right.x);
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

	vec2f& vec2f::operator*=(const vec2f& vector) {
		this->x *= vector.x;
		this->y *= vector.y;
		return *this;
	}

	vec2f& vec2f::operator/=(const vec2f& vector) {
		this->x /= vector.x;
		this->y /= vector.y;
		return *this;
	}

	vec2f& vec2f::operator+=(const float& value) {
		this->x += value;
		this->y += value;
		return *this;
	}

	vec2f& vec2f::operator-=(const float& value) {
		return *this;
	}

	vec2f& vec2f::operator*=(const float& value) {
		return *this;
	}

	vec2f& vec2f::operator/=(const float& value) {
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const vec2f& vector) {
		stream << "vec2f: (" << vector.x << ", " << vector.y << ")";
		return stream;
	}

	extern void log(vec2f& vector) {
		std::cout << "vec2f(" << vector.x << ", " << vector.y << ")" << std::endl;
	}
}
