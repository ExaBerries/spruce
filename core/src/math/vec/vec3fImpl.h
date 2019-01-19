#pragma once

namespace spruce {
	inline vec3f operator+(const vec3f& left, const vec3f& right) {
		simd::reg4f l = simd::load4f(left.x);
		simd::reg4f r = simd::load4f(right.x);
		vec3f out;
		simd::store4f(out.x, simd::add4f(l, r));
		return out;
	}

	inline vec3f operator-(const vec3f& left, const vec3f& right) {
		simd::reg4f l = simd::load4f(left.x);
		simd::reg4f r = simd::load4f(right.x);
		vec3f out;
		simd::store4f(out.x, simd::sub4f(l, r));
		return out;
	}

	inline vec3f operator+(const vec3f& left, const float& value) {
		simd::reg4f l = simd::load4f(left.x);
		simd::reg4f v = simd::load1f(value);
		vec3f out;
		simd::store4f(out.x, simd::add4f(l, v));
		return out;
	}

	inline vec3f operator-(const vec3f& left, const float& value) {
		simd::reg4f l = simd::load4f(left.x);
		simd::reg4f v = simd::load1f(value);
		vec3f out;
		simd::store4f(out.x, simd::add4f(l, v));
		return out;
	}

	inline vec3f operator*(const vec3f& left, float value) {
		simd::reg4f l = simd::load4f(left.x);
		simd::reg4f v = simd::load1f(value);
		vec3f out;
		simd::store4f(out.x, simd::mul4f(l, v));
		return out;
	}

	inline vec3f operator/(const vec3f& left, float value) {
		simd::reg4f l = simd::load4f(left.x);
		simd::reg4f v = simd::load1f(value);
		vec3f out;
		simd::store4f(out.x, simd::div4f(l, v));
		return out;
	}

	inline vec3f& vec3f::operator+=(const vec3f& vector) {
		simd::reg4f t = simd::load4f(this->x);
		simd::reg4f v = simd::load4f(vector.x);
		simd::store4f(this->x, simd::add4f(t, v));
		return *this;
	}

	inline vec3f& vec3f::operator-=(const vec3f& vector) {
		simd::reg4f t = simd::load4f(this->x);
		simd::reg4f v = simd::load4f(vector.x);
		simd::store4f(this->x, simd::sub4f(t, v));
		return *this;
	}

	inline vec3f& vec3f::operator+=(float value) {
		simd::reg4f t = simd::load4f(this->x);
		simd::reg4f v = simd::load1f(value);
		simd::store4f(this->x, simd::add4f(t, v));
		return *this;
	}

	inline vec3f& vec3f::operator-=(float value) {
		simd::reg4f t = simd::load4f(this->x);
		simd::reg4f v = simd::load1f(value);
		simd::store4f(this->x, simd::sub4f(t, v));
		return *this;
	}

	inline vec3f& vec3f::operator*=(float value) {
		simd::reg4f t = simd::load4f(this->x);
		simd::reg4f v = simd::load1f(value);
		simd::store4f(this->x, simd::mul4f(t, v));
		return *this;
	}

	inline vec3f& vec3f::operator/=(float value) {
		simd::reg4f t = simd::load4f(this->x);
		simd::reg4f v = simd::load1f(value);
		simd::store4f(this->x, simd::div4f(t, v));
		return *this;
	}
}

namespace std {
	template <>
	struct hash<spruce::vec3f> {
		size_t operator()(const spruce::vec3f& v) const {
			return std::hash<float>()(v.x) ^ (std::hash<float>()(v.y) << 1) ^ (std::hash<float>()(v.z) << 2);
		}
	};
}
