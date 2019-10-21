#include <math/vec/vec2i.h>

namespace spruce {
	vec2i::vec2i(int32 scalar) : x(scalar), y(scalar) {
	}

	vec2i::vec2i(int32 x, int32 y) : x(x), y(y){
	}

	float vec2i::mag2() const noexcept {
		return static_cast<float>(x * x + y * y);
	}

	float vec2i::mag() const noexcept {
		return std::sqrt(mag2());
	}

	float vec2i::dst2(const vec2i& vector) const noexcept {
		int32 dx = vector.x - x;
		int32 dy = vector.y - y;
		return static_cast<float>(dx * dx + dy * dy);
	}

	float vec2i::dst(const vec2i& vector) const noexcept {
		return sqrt(dst2(vector));
	}

	float vec2i::dot(const vec2i& vector) const noexcept {
		return static_cast<float>(vector.x * x + vector.y * y);
	}

	vec2i& vec2i::add(const vec2i& vector) noexcept {
		x += vector.x;
		y += vector.y;
		return *this;
	}

	vec2i& vec2i::sub(const vec2i& vector) noexcept {
		x -= vector.x;
		y -= vector.y;
		return *this;
	}

	vec2i& vec2i::add(int32 value) noexcept {
		x += value;
		y += value;
		return *this;
	}

	vec2i& vec2i::sub(int32 value) noexcept {
		x -= value;
		y -= value;
		return *this;
	}

	vec2i& vec2i::scl(int32 value) noexcept {
		x *= value;
		y *= value;
		return *this;
	}

	vec2i& vec2i::div(int32 value) noexcept {
		x /= value;
		y /= value;
		return *this;
	}

	vec2i operator+(const vec2i& left, const vec2i& right) noexcept {
		int32 x = left.x + right.x;
		int32 y = left.y + right.y;
		return {x, y};
	}

	vec2i operator-(const vec2i& left, const vec2i& right) noexcept {
		int32 x = left.x - right.x;
		int32 y = left.y - right.y;
		return {x, y};
	}

	vec2i operator+(const vec2i& left, int32 value) noexcept {
		int32 x = left.x + value;
		int32 y  = left.y + value;
		return {x, y};
	}

	vec2i operator-(const vec2i& left, int32 value) noexcept {
		int32 x = left.x - value;
		int32 y = left.y - value;
		return {x, y};
	}

	vec2i operator%(const vec2i& left, int32 value) noexcept {
		int32 x = left.x % value;
		int32 y = left.y % value;
		return vec2i(x, y);
	}

	vec2i operator*(const vec2i& left, int32 value) noexcept {
		int32 x = left.x * value;
		int32 y = left.y * value;
		return {x, y};
	}

	vec2i operator/(const vec2i& left, int32 value) noexcept {
		int32 x = left.x / value;
		int32 y = left.y / value;
		return {x, y};
	}

	bool vec2i::operator==(const vec2i& vector) const noexcept {
		return (x == vector.x && y == vector.y);
	}

	bool vec2i::operator!=(const vec2i& vector) const noexcept {
		return (x != vector.x || y != vector.y);
	}

	vec2i& vec2i::operator+=(const vec2i& vector) noexcept {
		this->x += vector.x;
		this->y += vector.y;
		return *this;
	}

	vec2i& vec2i::operator-=(const vec2i& vector) noexcept {
		this->x -= vector.x;
		this->y -= vector.y;
		return *this;
	}

	vec2i& vec2i::operator+=(int32 value) noexcept {
		this->x += value;
		this->y += value;
		return *this;
	}

	vec2i& vec2i::operator-=(int32 value) noexcept {
		this->x -= value;
		this->y -= value;
		return *this;
	}

	vec2i& vec2i::operator %=(int32 value) noexcept {
		this->x %= value;
		this->y %= value;
		return *this;
	}

	vec2i& vec2i::operator*=(int32 value) noexcept {
		this->x *= value;
		this->y *= value;
		return *this;
	}

	vec2i& vec2i::operator/=(int32 value) noexcept {
		this->x /= value;
		this->y /= value;
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const vec2i& vector) {
		stream << "vec2i(" << vector.x << ", " << vector.y << ")";
		return stream;
	}
}
