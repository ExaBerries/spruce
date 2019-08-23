#pragma once

namespace spruce {
	inline quaternion& quaternion::nor() {
		float mag2 = quaternion::mag2();
		if (mag2 != 0 && mag2 != 1) {
			float mag = sqrt(mag2);
			simd::reg4f thisreg = simd::load4f4f(x);
			simd::reg4f magreg = simd::load1f4f(mag);
			simd::store4f(x, simd::div4f(thisreg, magreg));
		}
		return *this;
	}

	inline quaternion operator+(const quaternion& left, const quaternion& right) {
		simd::reg4f l = simd::load4f4f(left.x);
		simd::reg4f r = simd::load4f4f(right.x);
		quaternion out;
		simd::store4f(out.x, simd::add4f(l, r));
		return out;
	}

	inline quaternion operator-(const quaternion& left, const quaternion& right) {
		simd::reg4f l = simd::load4f4f(left.x);
		simd::reg4f r = simd::load4f4f(right.x);
		quaternion out;
		simd::store4f(out.x, simd::sub4f(l, r));
		return out;
	}

	inline quaternion operator*(const quaternion& left, const quaternion& right) {
		float x = left.w * right.x + left.x * right.w + left.y * right.z - left.z * right.y;
		float y = left.w * right.y + left.y * right.w + left.z * right.x - left.x * right.z;
		float z = left.w * right.z + left.z * right.w + left.x * right.y - left.y * right.x;
		float w = left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z;
		return {x, y, z, w};
	}

	inline vec3f operator*(const quaternion& quaternion, const vec3f& vector) {
		spruce::quaternion conjugate = spruce::quaternion(quaternion).conjugate();
		spruce::quaternion result = quaternion * spruce::quaternion(vector.x, vector.y, vector.z, 0) * conjugate;
		return {result.x, result.y, result.z};
	}

	inline vec3f operator*(const vec3f& vector, const quaternion& quaternion) {
		spruce::quaternion conjugate = spruce::quaternion(quaternion).conjugate();
		spruce::quaternion result = quaternion * spruce::quaternion(vector.x, vector.y, vector.z, 0) * conjugate;
		return {result.x, result.y, result.z};
	}

	inline quaternion& quaternion::operator+=(const quaternion& quaternion) {
		simd::reg4f t = simd::load4f4f(x);
		simd::reg4f q = simd::load4f4f(quaternion.x);
		simd::store4f(x, simd::add4f(t, q));
		return *this;
	}

	inline quaternion& quaternion::operator-=(const quaternion& quaternion) {
		simd::reg4f t = simd::load4f4f(x);
		simd::reg4f q = simd::load4f4f(quaternion.x);
		simd::store4f(x, simd::sub4f(t, q));
		return *this;
	}

	inline quaternion& quaternion::operator*=(const quaternion& quaternion) {
		float tx = this->w * quaternion.x + this->x * quaternion.w + this->y * quaternion.z - this->z * quaternion.y;
		float ty = this->w * quaternion.y + this->y * quaternion.w + this->z * quaternion.x - this->x * quaternion.z;
		float tz = this->w * quaternion.z + this->z * quaternion.w + this->x * quaternion.y - this->y * quaternion.x;
		float tw = this->w * quaternion.w - this->x * quaternion.x - this->y * quaternion.y - this->z * quaternion.z;
		this->x = tx;
		this->y = ty;
		this->z = tz;
		this->w = tw;
		return *this;
	}
}

namespace std {
	template <>
	struct hash<spruce::quaternion> {
		size_t operator()(const spruce::quaternion& q) const {
			return std::hash<float>()(q.x) ^ (std::hash<float>()(q.y) << 1) ^ (std::hash<float>()(q.z) << 2) ^ (std::hash<float>()(q.w) << 3);
		}
	};
}
