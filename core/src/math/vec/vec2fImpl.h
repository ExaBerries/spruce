#pragma once

namespace spruce {
	inline vec2f operator+(const vec2f& left, const vec2f& right) noexcept {
		float x = left.x + right.x;
		float y = left.y + right.y;
		return {x, y};
	}

	inline vec2f operator-(const vec2f& left, const vec2f& right) noexcept {
		float x = left.x - right.x;
		float y = left.y - right.y;
		return {x, y};
	}

	inline vec2f operator+(const vec2f& left, float value) noexcept {
		float x = left.x + value;
		float y = left.y + value;
		return {x, y};
	}

	inline vec2f operator-(const vec2f& left, float value) noexcept {
		float x = left.x - value;
		float y = left.y - value;
		return {x, y};
	}

	inline vec2f operator*(const vec2f& left, float value) noexcept {
		float x = left.x * value;
		float y = left.y * value;
		return {x, y};
	}

	inline vec2f operator/(const vec2f& left, float value) noexcept {
		float x = left.x / value;
		float y = left.y / value;
		return {x, y};
	}

	inline vec2f& vec2f::operator+=(const vec2f& vector) noexcept {
		this->x += vector.x;
		this->y += vector.y;
		return *this;
	}

	inline vec2f& vec2f::operator-=(const vec2f& vector) noexcept {
		this->x -= vector.x;
		this->y -= vector.y;
		return *this;
	}

	inline vec2f& vec2f::operator+=(float value) noexcept {
		this->x += value;
		this->y += value;
		return *this;
	}

	inline vec2f& vec2f::operator-=(float value) noexcept {
		this->x -= value;
		this->y -= value;
		return *this;
	}

	inline vec2f& vec2f::operator*=(float value) noexcept {
		this->x *= value;
		this->y *= value;
		return *this;
	}

	inline vec2f& vec2f::operator/=(float value) noexcept {
		this->x /= value;
		this->y /= value;
		return *this;
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
