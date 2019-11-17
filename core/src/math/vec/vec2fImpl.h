#pragma once

namespace spruce {
	constexpr vec2f::vec2f(float scalar) noexcept : x(scalar), y(scalar) {
	}

	constexpr vec2f::vec2f(float x, float y) noexcept : x(x), y(y) {
	}

	constexpr vec2f& vec2f::set(float scalar) noexcept {
		x = scalar;
		y = scalar;
		return *this;
	}

	constexpr vec2f& vec2f::set(float x, float y) noexcept {
		this->x = x;
		this->y = y;
		return *this;
	}

	constexpr float vec2f::mag2() const noexcept {
		return x * x + y * y;
	}

	constexpr float vec2f::mag() const noexcept {
		return sqrt(mag2());
	}

	constexpr vec2f& vec2f::nor() noexcept {
		float mag2 = vec2f::mag2();
		if (mag2 != 0 && mag2 != 1) {
			float mag = sqrt(mag2);
			x /= mag;
			y /= mag;
		}
		return *this;
	}

	constexpr float vec2f::dst2(const vec2f& vector) const noexcept {
		float dx = vector.x - x;
		float dy = vector.y - y;
		return dx * dx + dy * dy;
	}

	constexpr float vec2f::dst(const vec2f& vector) const noexcept {
		return sqrt(dst2(vector));
	}

	constexpr float vec2f::dot(const vec2f& vector) const noexcept {
		return x * vector.x + y * vector.y;
	}

	constexpr vec2f& vec2f::add(const vec2f& vector) noexcept {
		x += vector.x;
		y += vector.y;
		return *this;
	}

	constexpr vec2f& vec2f::sub(const vec2f& vector) noexcept {
		x -= vector.x;
		y -= vector.y;
		return *this;
	}

	constexpr vec2f& vec2f::add(float value) noexcept {
		x += value;
		y += value;
		return *this;
	}

	constexpr vec2f& vec2f::sub(float value) noexcept {
		x -= value;
		y -= value;
		return *this;
	}

	constexpr vec2f& vec2f::scl(float value) noexcept {
		x *= value;
		y *= value;
		return *this;
	}

	constexpr vec2f& vec2f::div(float value) noexcept {
		x /= value;
		y /= value;
		return *this;
	}

	constexpr bool vec2f::operator==(const vec2f& vector) const noexcept {
		return (x == vector.x && y == vector.y);
	}

	constexpr bool vec2f::operator!=(const vec2f& vector) const noexcept {
		return (x != vector.x || y != vector.x);
	}

	constexpr vec2f operator+(const vec2f& left, const vec2f& right) noexcept {
		float x = left.x + right.x;
		float y = left.y + right.y;
		return {x, y};
	}

	constexpr vec2f operator-(const vec2f& left, const vec2f& right) noexcept {
		float x = left.x - right.x;
		float y = left.y - right.y;
		return {x, y};
	}

	constexpr vec2f operator+(const vec2f& left, float value) noexcept {
		float x = left.x + value;
		float y = left.y + value;
		return {x, y};
	}

	constexpr vec2f operator-(const vec2f& left, float value) noexcept {
		float x = left.x - value;
		float y = left.y - value;
		return {x, y};
	}

	constexpr vec2f operator*(const vec2f& left, float value) noexcept {
		float x = left.x * value;
		float y = left.y * value;
		return {x, y};
	}

	constexpr vec2f operator/(const vec2f& left, float value) noexcept {
		float x = left.x / value;
		float y = left.y / value;
		return {x, y};
	}

	constexpr vec2f& vec2f::operator+=(const vec2f& vector) noexcept {
		this->x += vector.x;
		this->y += vector.y;
		return *this;
	}

	constexpr vec2f& vec2f::operator-=(const vec2f& vector) noexcept {
		this->x -= vector.x;
		this->y -= vector.y;
		return *this;
	}

	constexpr vec2f& vec2f::operator+=(float value) noexcept {
		this->x += value;
		this->y += value;
		return *this;
	}

	constexpr vec2f& vec2f::operator-=(float value) noexcept {
		this->x -= value;
		this->y -= value;
		return *this;
	}

	constexpr vec2f& vec2f::operator*=(float value) noexcept {
		this->x *= value;
		this->y *= value;
		return *this;
	}

	constexpr vec2f& vec2f::operator/=(float value) noexcept {
		this->x /= value;
		this->y /= value;
		return *this;
	}

	constexpr vec2f vec2f::lerp(const vec2f& a, const vec2f& b, float alpha) noexcept {
		return vec2f((1 - alpha) * a.x + alpha * b.x, (1 - alpha) * a.y + alpha * b.y);
	}
}

namespace std {
	template <>
	struct hash<spruce::vec2f> {
		size_t operator()(const spruce::vec2f& v) const {
			return std::hash<float>()(v.x) ^ (std::hash<float>()(v.y) << 1);
		}
	};
}
