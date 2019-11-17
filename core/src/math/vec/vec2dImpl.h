#pragma once

namespace spruce {
	constexpr vec2d::vec2d(double scalar) noexcept : x(scalar), y(scalar) {
	}

	constexpr vec2d::vec2d(double x, double y) noexcept : x(x), y(y) {
	}

	constexpr vec2d& vec2d::set(double scalar) noexcept {
		x = scalar;
		y = scalar;
		return *this;
	}

	constexpr vec2d& vec2d::set(double x, double y) noexcept {
		this->x = x;
		this->y = y;
		return *this;
	}

	constexpr double vec2d::mag2() const noexcept {
		return x * x + y * y;
	}

	constexpr double vec2d::mag() const noexcept {
		return sqrt(mag2());
	}

	constexpr vec2d& vec2d::nor() noexcept {
		double mag2 = vec2d::mag2();
		if (mag2 != 0 && mag2 != 1) {
			double mag = sqrt(mag2);
			x /= mag;
			y /= mag;
		}
		return *this;
	}

	constexpr double vec2d::dst2(const vec2d& vector) const noexcept {
		double dx = vector.x - x;
		double dy = vector.y - y;
		return dx * dx + dy * dy;
	}

	constexpr double vec2d::dst(const vec2d& vector) const noexcept {
		return sqrt(dst2(vector));
	}

	constexpr double vec2d::dot(const vec2d& vector) const noexcept {
		return x * vector.x + y * vector.y;
	}

	constexpr vec2d& vec2d::add(const vec2d& vector) noexcept {
		x += vector.x;
		y += vector.y;
		return *this;
	}

	constexpr vec2d& vec2d::sub(const vec2d& vector) noexcept {
		x -= vector.x;
		y -= vector.y;
		return *this;
	}

	constexpr vec2d& vec2d::add(double value) noexcept {
		x += value;
		y += value;
		return *this;
	}

	constexpr vec2d& vec2d::sub(double value) noexcept {
		x -= value;
		y -= value;
		return *this;
	}

	constexpr vec2d& vec2d::scl(double value) noexcept {
		x *= value;
		y *= value;
		return *this;
	}

	constexpr vec2d& vec2d::div(double value) noexcept {
		x /= value;
		y /= value;
		return *this;
	}

	constexpr bool vec2d::operator==(const vec2d& vector) const noexcept {
		return (x == vector.x && y == vector.y);
	}

	constexpr bool vec2d::operator!=(const vec2d& vector) const noexcept {
		return (x != vector.x || y != vector.x);
	}

	constexpr vec2d operator+(const vec2d& left, const vec2d& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x + right.x, left.y + right.y};
		} else {
			simd::reg2d l = simd::load2d2d(left.x);
			simd::reg2d r = simd::load2d2d(right.x);
			vec2d out;
			simd::store2d(out.x, simd::add2d(l, r));
			return out;
		}
	}

	constexpr vec2d operator-(const vec2d& left, const vec2d& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x - right.x, left.y - right.y};
		} else {
			simd::reg2d l = simd::load2d2d(left.x);
			simd::reg2d r = simd::load2d2d(right.x);
			vec2d out;
			simd::store2d(out.x, simd::sub2d(l, r));
			return out;
		}
	}

	constexpr vec2d operator+(const vec2d& left, double value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x + value, left.y + value};
		} else {
			simd::reg2d l = simd::load2d2d(left.x);
			simd::reg2d r = simd::load1d2d(value);
			vec2d out;
			simd::store2d(out.x, simd::add2d(l, r));
			return out;
		}
	}

	constexpr vec2d operator-(const vec2d& left, double value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x - value, left.y - value};
		} else {
			simd::reg2d l = simd::load2d2d(left.x);
			simd::reg2d r = simd::load1d2d(value);
			vec2d out;
			simd::store2d(out.x, simd::sub2d(l, r));
			return out;
		}
	}

	constexpr vec2d operator*(const vec2d& left, double value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x * value, left.y * value};
		} else {
			simd::reg2d l = simd::load2d2d(left.x);
			simd::reg2d r = simd::load1d2d(value);
			vec2d out;
			simd::store2d(out.x, simd::mul2d(l, r));
			return out;
		}
	}

	constexpr vec2d operator/(const vec2d& left, double value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x / value, left.y / value};
		} else {
			simd::reg2d l = simd::load2d2d(left.x);
			simd::reg2d r = simd::load1d2d(value);
			vec2d out;
			simd::store2d(out.x, simd::div2d(l, r));
			return out;
		}
	}

	constexpr vec2d& vec2d::operator+=(const vec2d& vector) noexcept {
		if (std::is_constant_evaluated()) {
			x += vector.x;
			y += vector.y;
			return *this;
		} else {
			simd::reg2d t = simd::load2d2d(this->x);
			simd::reg2d v = simd::load2d2d(vector.x);
			simd::store2d(this->x, simd::add2d(t, v));
			return *this;
		}
	}

	constexpr vec2d& vec2d::operator-=(const vec2d& vector) noexcept {
		if (std::is_constant_evaluated()) {
			x -= vector.x;
			y -= vector.y;
			return *this;
		} else {
			simd::reg2d t = simd::load2d2d(this->x);
			simd::reg2d v = simd::load2d2d(vector.x);
			simd::store2d(this->x, simd::sub2d(t, v));
			return *this;
		}
	}

	constexpr vec2d& vec2d::operator+=(double value) noexcept {
		if (std::is_constant_evaluated()) {
			x += value;
			y += value;
			return *this;
		} else {
			simd::reg2d t = simd::load2d2d(this->x);
			simd::reg2d v = simd::load1d2d(value);
			simd::store2d(this->x, simd::add2d(t, v));
			return *this;
		}
	}

	constexpr vec2d& vec2d::operator-=(double value) noexcept {
		if (std::is_constant_evaluated()) {
			x -= value;
			y -= value;
			return *this;
		} else {
			simd::reg2d t = simd::load2d2d(this->x);
			simd::reg2d v = simd::load1d2d(value);
			simd::store2d(this->x, simd::sub2d(t, v));
			return *this;
		}
	}

	constexpr vec2d& vec2d::operator*=(double value) noexcept {
		if (std::is_constant_evaluated()) {
			x *= value;
			y *= value;
			return *this;
		} else {
			simd::reg2d t = simd::load2d2d(this->x);
			simd::reg2d v = simd::load1d2d(value);
			simd::store2d(this->x, simd::mul2d(t, v));
			return *this;
		}
	}

	constexpr vec2d& vec2d::operator/=(double value) noexcept {
		if (std::is_constant_evaluated()) {
			x /= value;
			y /= value;
			return *this;
		} else {
			simd::reg2d t = simd::load2d2d(this->x);
			simd::reg2d v = simd::load1d2d(value);
			simd::store2d(this->x, simd::div2d(t, v));
			return *this;
		}
	}


	constexpr vec2d vec2d::lerp(const vec2d& a, const vec2d& b, double alpha) noexcept {
		return vec2d((1 - alpha) * a.x + alpha * b.x, (1 - alpha) * a.y + alpha * b.y);
	}
}

namespace std {
	template <>
	struct hash<spruce::vec2d> {
		size_t operator()(const spruce::vec2d& v) const {
			return std::hash<double>()(v.x) ^ (std::hash<double>()(v.y) << 1);
		}
	};
}
