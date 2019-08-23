#include <math/vec/vec2d.h>

namespace spruce {
	vec2d::vec2d(double scalar) : x(scalar), y(scalar) {
	}

	vec2d::vec2d(double x, double y) : x(x), y(y) {
	}

	vec2d& vec2d::set(double scalar) {
		x = scalar;
		y = scalar;
		return *this;
	}

	vec2d& vec2d::set(double x, double y) {
		this->x = x;
		this->y = y;
		return *this;
	}

	double vec2d::mag2() const {
		return x * x + y * y;
	}

	double vec2d::mag() const {
		return sqrt(mag2());
	}

	vec2d& vec2d::nor() {
		double mag2 = vec2d::mag2();
		if (mag2 != 0 && mag2 != 1) {
			double mag = sqrt(mag2);
			x /= mag;
			y /= mag;
		}
		return *this;
	}

	double vec2d::dst2(const vec2d& vector) const {
		double dx = vector.x - x;
		double dy = vector.y - y;
		return dx * dx + dy * dy;
	}

	double vec2d::dst(const vec2d& vector) const {
		return sqrt(dst2(vector));
	}

	double vec2d::dot(const vec2d& vector) const {
		return x * vector.x + y * vector.y;
	}

	vec2d& vec2d::add(const vec2d& vector) {
		x += vector.x;
		y += vector.y;
		return *this;
	}

	vec2d& vec2d::sub(const vec2d& vector) {
		x -= vector.x;
		y -= vector.y;
		return *this;
	}

	vec2d& vec2d::add(double value) {
		x += value;
		y += value;
		return *this;
	}

	vec2d& vec2d::sub(double value) {
		x -= value;
		y -= value;
		return *this;
	}

	vec2d& vec2d::scl(double value) {
		x *= value;
		y *= value;
		return *this;
	}

	vec2d& vec2d::div(double value) {
		x /= value;
		y /= value;
		return *this;
	}

	bool vec2d::operator==(const vec2d& vector) const {
		return (x == vector.x && y == vector.y);
	}

	bool vec2d::operator!=(const vec2d& vector) const {
		return (x != vector.x || y != vector.x);
	}

	std::ostream& operator<<(std::ostream& stream, const vec2d& vector) {
		stream << "vec2d(" << vector.x << ", " << vector.y << ")";
		return stream;
	}

	vec2d vec2d::lerp(const vec2d& a, const vec2d& b, double alpha) {
		return vec2d((1 - alpha) * a.x + alpha * b.x, (1 - alpha) * a.y + alpha * b.y);
	}
}
