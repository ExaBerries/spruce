#include <math/vec/vec2f.h>

namespace spruce {
	vec2f::vec2f(float scalar) : x(scalar), y(scalar) {
	}

	vec2f::vec2f(float x, float y) : x(x), y(y) {
	}

	vec2f& vec2f::set(float scalar) noexcept {
		x = scalar;
		y = scalar;
		return *this;
	}

	vec2f& vec2f::set(float x, float y) noexcept {
		this->x = x;
		this->y = y;
		return *this;
	}

	float vec2f::mag2() const noexcept {
		return x * x + y * y;
	}

	float vec2f::mag() const noexcept {
		return std::sqrt(mag2());
	}

	vec2f& vec2f::nor() noexcept {
		float mag2 = vec2f::mag2();
		if (mag2 != 0 && mag2 != 1) {
			float mag = std::sqrt(mag2);
			x /= mag;
			y /= mag;
		}
		return *this;
	}

	float vec2f::dst2(const vec2f& vector) const noexcept {
		float dx = vector.x - x;
		float dy = vector.y - y;
		return dx * dx + dy * dy;
	}

	float vec2f::dst(const vec2f& vector) const noexcept {
		return std::sqrt(dst2(vector));
	}

	float vec2f::dot(const vec2f& vector) const noexcept {
		return x * vector.x + y * vector.y;
	}

	vec2f& vec2f::add(const vec2f& vector) noexcept {
		x += vector.x;
		y += vector.y;
		return *this;
	}

	vec2f& vec2f::sub(const vec2f& vector) noexcept {
		x -= vector.x;
		y -= vector.y;
		return *this;
	}

	vec2f& vec2f::add(float value) noexcept {
		x += value;
		y += value;
		return *this;
	}

	vec2f& vec2f::sub(float value) noexcept {
		x -= value;
		y -= value;
		return *this;
	}

	vec2f& vec2f::scl(float value) noexcept {
		x *= value;
		y *= value;
		return *this;
	}

	vec2f& vec2f::div(float value) noexcept {
		x /= value;
		y /= value;
		return *this;
	}

	bool vec2f::operator==(const vec2f& vector) const noexcept {
		return (x == vector.x && y == vector.y);
	}

	bool vec2f::operator!=(const vec2f& vector) const noexcept {
		return (x != vector.x || y != vector.x);
	}

	std::ostream& operator<<(std::ostream& stream, const vec2f& vector) {
		stream << "vec2f(" << vector.x << ", " << vector.y << ")";
		return stream;
	}

	vec2f vec2f::lerp(const vec2f& a, const vec2f& b, float alpha) noexcept {
		return vec2f((1 - alpha) * a.x + alpha * b.x, (1 - alpha) * a.y + alpha * b.y);
	}
}
