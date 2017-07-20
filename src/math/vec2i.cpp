#include <math/vec2i.h>

namespace spruce {
	vec2i::vec2i() : x(0), y(0) {
	}

	vec2i::vec2i(const vec2i& vector) : x(vector.x), y(vector.y) {
	}

	vec2i::vec2i(const int32& scalar) : x(scalar), y(scalar) {
	}

	vec2i::vec2i(const int32& x, const int32& y) : x(x), y(y){
	}

	float vec2i::mag2() const {
		return x * x + y * y;
	}

	float vec2i::mag() const {
		return sqrt(mag2());
	}

	float vec2i::dst2(const vec2i& vector) const {
		float dx = vector.x - x;
		float dy = vector.y - y;
		return dx * dx + dy * dy;
	}

	float vec2i::dst(const vec2i& vector) const {
		return sqrt(dst2(vector));
	}

	float vec2i::dot(const vec2i& vector) const {
		return vector.x * x + vector.y * y;
	}

	vec2i& vec2i::add(const vec2i& vector) {
		x += vector.x;
		y += vector.y;
		return *this;
	}

	vec2i& vec2i::sub(const vec2i& vector) {
		x -= vector.x;
		y -= vector.y;
		return *this;
	}

	vec2i& vec2i::add(const int32& value) {
		x += value;
		y += value;
		return *this;
	}

	vec2i& vec2i::sub(const int32& value) {
		x -= value;
		y -= value;
		return *this;
	}

	vec2i& vec2i::scl(const int32& value) {
		x *= value;
		y *= value;
		return *this;
	}

	vec2i& vec2i::div(const int32& value) {
		x /= value;
		y /= value;
		return *this;
	}

	vec2i operator+(const vec2i left, const vec2i& right) {
		int x = left.x + right.x;
		int y = left.y + right.y;
		return vec2i(x, y);
	}

	vec2i operator-(const vec2i left, const vec2i& right) {
		int x = left.x - right.x;
		int y = left.y - right.y;
		return vec2i(x, y);
	}

	vec2i operator+(const vec2i left, int32 value) {
		int x = left.x + value;
		int y  = left.y + value;
		return vec2i(x, y);
	}

	vec2i operator-(const vec2i left, int32 value) {
		int x = left.x - value;
		int y = left.y - value;
		return vec2i(x, y);
	}

	vec2i operator*(const vec2i left, int32 value) {
		int x = left.x * value;
		int y = left.y * value;
		return vec2i(x, y);
	}

	vec2i operator/(const vec2i left, int32 value) {
		int x = left.x / value;
		int y = left.y / value;
		return vec2i(x, y);
	}

	bool operator==(const vec2i& left, const vec2i& right) {
		return (left.x == right.x && left.y == right.y);
	}

	bool operator!=(const vec2i& left, const vec2i& right) {
		return (left.x != right.x || left.y != right.y);
	}

	vec2i& vec2i::operator+=(const vec2i& vector) {
		this->x += vector.x;
		this->y += vector.y;
		return *this;
	}

	vec2i& vec2i::operator-=(const vec2i& vector) {
		this->x -= vector.x;
		this->y -= vector.y;
		return *this;
	}

	vec2i& vec2i::operator+=(const int32& value) {
		this->x += value;
		this->y += value;
		return *this;
	}

	vec2i& vec2i::operator-=(const int32& value) {
		this->x -= value;
		this->y -= value;
		return *this;
	}

	vec2i& vec2i::operator*=(const int32& value) {
		this->x *= value;
		this->y *= value;
		return *this;
	}

	vec2i& vec2i::operator/=(const int32& value) {
		this->x /= value;
		this->y /= value;
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const vec2i& vector) {
		stream << "vec2i(" << vector.x << ", " << vector.y << ")";
		return stream;
	}

	void log(const vec2i& vector) {
		std::cout << "vec2i(" << vector.x << ", " << vector.y << ")" << std::endl;
	}
}
