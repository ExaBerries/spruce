#pragma once

namespace spruce {
	inline vec4f operator+(const vec4f& left, const vec4f& right) {
		simd::reg4f l = simd::load4f4f(left.x);
		simd::reg4f r = simd::load4f4f(right.x);
		vec4f out;
		simd::store4f(out.x, simd::add4f(l, r));
		return out;
	}

	inline vec4f operator-(const vec4f& left, const vec4f& right) {
		simd::reg4f l = simd::load4f4f(left.x);
		simd::reg4f r = simd::load4f4f(right.x);
		vec4f out;
		simd::store4f(out.x, simd::sub4f(l, r));
		return out;
	}

	inline vec4f operator+(const vec4f& left, float value) {
		simd::reg4f l = simd::load4f4f(left.x);
		simd::reg4f v = simd::load1f4f(value);
		vec4f out;
		simd::store4f(out.x, simd::add4f(l, v));
		return out;
	}

	inline vec4f operator-(const vec4f& left, float value) {
		simd::reg4f l = simd::load4f4f(left.x);
		simd::reg4f v = simd::load1f4f(value);
		vec4f out;
		simd::store4f(out.x, simd::sub4f(l, v));
		return out;
	}

	inline vec4f operator*(const vec4f& left, float value) {
		simd::reg4f l = simd::load4f4f(left.x);
		simd::reg4f v = simd::load1f4f(value);
		vec4f out;
		simd::store4f(out.x, simd::mul4f(l, v));
		return out;
	}

	inline vec4f operator/(const vec4f& left, float value) {
		simd::reg4f l = simd::load4f4f(left.x);
		simd::reg4f v = simd::load1f4f(value);
		vec4f out;
		simd::store4f(out.x, simd::div4f(l, v));
		return out;
	}

	inline vec4f& vec4f::operator+=(const vec4f& vector) {
		simd::reg4f t = simd::load4f4f(this->x);
		simd::reg4f v = simd::load4f4f(vector.x);
		simd::store4f(this->x, simd::add4f(t, v));
		return *this;
	}

	inline vec4f& vec4f::operator-=(const vec4f& vector) {
		simd::reg4f t = simd::load4f4f(this->x);
		simd::reg4f v = simd::load4f4f(vector.x);
		simd::store4f(this->x, simd::sub4f(t, v));
		return *this;
	}

	inline vec4f& vec4f::operator+=(float value) {
		simd::reg4f t = simd::load4f4f(this->x);
		simd::reg4f v = simd::load1f4f(value);
		simd::store4f(this->x, simd::add4f(t, v));
		return *this;
	}

	inline vec4f& vec4f::operator-=(float value) {
		simd::reg4f t = simd::load4f4f(this->x);
		simd::reg4f v = simd::load1f4f(value);
		simd::store4f(this->x, simd::sub4f(t, v));
		return *this;
	}

	inline vec4f& vec4f::operator*=(float value) {
		simd::reg4f t = simd::load4f4f(this->x);
		simd::reg4f v = simd::load1f4f(value);
		simd::store4f(this->x, simd::mul4f(t, v));
		return *this;
	}

	inline vec4f& vec4f::operator/=(float value) {
		simd::reg4f t = simd::load4f4f(this->x);
		simd::reg4f v = simd::load1f4f(value);
		simd::store4f(this->x, simd::div4f(t, v));
		return *this;
	}
}

namespace std {
	template <>
	struct hash<spruce::vec4f> {
		size_t operator()(const spruce::vec4f& v) const {
			return std::hash<float>()(v.x) ^ (std::hash<float>()(v.y) << 1) ^ (std::hash<float>()(v.z) << 2) ^ (std::hash<float>()(v.w) << 3);
		}
	};
}
