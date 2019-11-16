#pragma once

namespace spruce {
	constexpr vec2i::vec2i(int32 scalar) noexcept : x(scalar), y(scalar) {
	}

	constexpr vec2i::vec2i(int32 x, int32 y) noexcept : x(x), y(y){
	}

	constexpr float vec2i::mag2() const noexcept {
		return static_cast<float>(x * x + y * y);
	}

	constexpr float vec2i::mag() const noexcept {
		return sqrt(mag2());
	}

	constexpr float vec2i::dst2(const vec2i& vector) const noexcept {
		int32 dx = vector.x - x;
		int32 dy = vector.y - y;
		return static_cast<float>(dx * dx + dy * dy);
	}

	constexpr float vec2i::dst(const vec2i& vector) const noexcept {
		return sqrt(dst2(vector));
	}

	constexpr float vec2i::dot(const vec2i& vector) const noexcept {
		return static_cast<float>(vector.x * x + vector.y * y);
	}

	constexpr vec2i& vec2i::add(const vec2i& vector) noexcept {
		x += vector.x;
		y += vector.y;
		return *this;
	}

	constexpr vec2i& vec2i::sub(const vec2i& vector) noexcept {
		x -= vector.x;
		y -= vector.y;
		return *this;
	}

	constexpr vec2i& vec2i::add(int32 value) noexcept {
		x += value;
		y += value;
		return *this;
	}

	constexpr vec2i& vec2i::sub(int32 value) noexcept {
		x -= value;
		y -= value;
		return *this;
	}

	constexpr vec2i& vec2i::scl(int32 value) noexcept {
		x *= value;
		y *= value;
		return *this;
	}

	constexpr vec2i& vec2i::div(int32 value) noexcept {
		x /= value;
		y /= value;
		return *this;
	}

	constexpr vec2i operator+(const vec2i& left, const vec2i& right) noexcept {
		int32 x = left.x + right.x;
		int32 y = left.y + right.y;
		return {x, y};
	}

	constexpr vec2i operator-(const vec2i& left, const vec2i& right) noexcept {
		int32 x = left.x - right.x;
		int32 y = left.y - right.y;
		return {x, y};
	}

	constexpr vec2i operator+(const vec2i& left, int32 value) noexcept {
		int32 x = left.x + value;
		int32 y  = left.y + value;
		return {x, y};
	}

	constexpr vec2i operator-(const vec2i& left, int32 value) noexcept {
		int32 x = left.x - value;
		int32 y = left.y - value;
		return {x, y};
	}

	constexpr vec2i operator%(const vec2i& left, int32 value) noexcept {
		int32 x = left.x % value;
		int32 y = left.y % value;
		return vec2i(x, y);
	}

	constexpr vec2i operator*(const vec2i& left, int32 value) noexcept {
		int32 x = left.x * value;
		int32 y = left.y * value;
		return {x, y};
	}

	constexpr vec2i operator/(const vec2i& left, int32 value) noexcept {
		int32 x = left.x / value;
		int32 y = left.y / value;
		return {x, y};
	}

	constexpr bool vec2i::operator==(const vec2i& vector) const noexcept {
		return (x == vector.x && y == vector.y);
	}

	constexpr bool vec2i::operator!=(const vec2i& vector) const noexcept {
		return (x != vector.x || y != vector.y);
	}

	constexpr vec2i& vec2i::operator+=(const vec2i& vector) noexcept {
		this->x += vector.x;
		this->y += vector.y;
		return *this;
	}

	constexpr vec2i& vec2i::operator-=(const vec2i& vector) noexcept {
		this->x -= vector.x;
		this->y -= vector.y;
		return *this;
	}

	constexpr vec2i& vec2i::operator+=(int32 value) noexcept {
		this->x += value;
		this->y += value;
		return *this;
	}

	constexpr vec2i& vec2i::operator-=(int32 value) noexcept {
		this->x -= value;
		this->y -= value;
		return *this;
	}

	constexpr vec2i& vec2i::operator %=(int32 value) noexcept {
		this->x %= value;
		this->y %= value;
		return *this;
	}

	constexpr vec2i& vec2i::operator*=(int32 value) noexcept {
		this->x *= value;
		this->y *= value;
		return *this;
	}

	constexpr vec2i& vec2i::operator/=(int32 value) noexcept {
		this->x /= value;
		this->y /= value;
		return *this;
	}
}
