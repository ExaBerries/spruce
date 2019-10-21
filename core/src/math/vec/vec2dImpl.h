#pragma once

namespace spruce {
	inline vec2d operator+(const vec2d& left, const vec2d& right) noexcept {
		simd::reg2d l = simd::load2d2d(left.x);
		simd::reg2d r = simd::load2d2d(right.x);
		vec2d out;
		simd::store2d(out.x, simd::add2d(l, r));
		return out;
	}

	inline vec2d operator-(const vec2d& left, const vec2d& right) noexcept {
		simd::reg2d l = simd::load2d2d(left.x);
		simd::reg2d r = simd::load2d2d(right.x);
		vec2d out;
		simd::store2d(out.x, simd::sub2d(l, r));
		return out;
	}

	inline vec2d operator+(const vec2d& left, double value) noexcept {
		simd::reg2d l = simd::load2d2d(left.x);
		simd::reg2d r = simd::load1d2d(value);
		vec2d out;
		simd::store2d(out.x, simd::add2d(l, r));
		return out;
	}

	inline vec2d operator-(const vec2d& left, double value) noexcept {
		simd::reg2d l = simd::load2d2d(left.x);
		simd::reg2d r = simd::load1d2d(value);
		vec2d out;
		simd::store2d(out.x, simd::sub2d(l, r));
		return out;
	}

	inline vec2d operator*(const vec2d& left, double value) noexcept {
		simd::reg2d l = simd::load2d2d(left.x);
		simd::reg2d r = simd::load1d2d(value);
		vec2d out;
		simd::store2d(out.x, simd::mul2d(l, r));
		return out;
	}

	inline vec2d operator/(const vec2d& left, double value) noexcept {
		simd::reg2d l = simd::load2d2d(left.x);
		simd::reg2d r = simd::load1d2d(value);
		vec2d out;
		simd::store2d(out.x, simd::div2d(l, r));
		return out;
	}

	inline vec2d& vec2d::operator+=(const vec2d& vector) noexcept {
		simd::reg2d t = simd::load2d2d(this->x);
		simd::reg2d v = simd::load2d2d(vector.x);
		simd::store2d(this->x, simd::add2d(t, v));
		return *this;
	}

	inline vec2d& vec2d::operator-=(const vec2d& vector) noexcept {
		simd::reg2d t = simd::load2d2d(this->x);
		simd::reg2d v = simd::load2d2d(vector.x);
		simd::store2d(this->x, simd::sub2d(t, v));
		return *this;
	}

	inline vec2d& vec2d::operator+=(double value) noexcept {
		simd::reg2d t = simd::load2d2d(this->x);
		simd::reg2d v = simd::load1d2d(value);
		simd::store2d(this->x, simd::add2d(t, v));
		return *this;
	}

	inline vec2d& vec2d::operator-=(double value) noexcept {
		simd::reg2d t = simd::load2d2d(this->x);
		simd::reg2d v = simd::load1d2d(value);
		simd::store2d(this->x, simd::sub2d(t, v));
		return *this;
	}

	inline vec2d& vec2d::operator*=(double value) noexcept {
		simd::reg2d t = simd::load2d2d(this->x);
		simd::reg2d v = simd::load1d2d(value);
		simd::store2d(this->x, simd::mul2d(t, v));
		return *this;
	}

	inline vec2d& vec2d::operator/=(double value) noexcept {
		simd::reg2d t = simd::load2d2d(this->x);
		simd::reg2d v = simd::load1d2d(value);
		simd::store2d(this->x, simd::div2d(t, v));
		return *this;
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
