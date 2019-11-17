#pragma once

namespace spruce {
	constexpr quaternion::quaternion(float x, float y, float z, float w) noexcept : x(x), y(y), z(z), w(w) {
	}

	constexpr quaternion::quaternion(float pitch, float yaw, float roll) noexcept {
		float sy = sin(yaw / 2.0f);
		float sp = sin(pitch / 2.0f);
		float sr = sin(roll / 2.0f);
		float cy = cos(yaw / 2.0f);
		float cp = cos(pitch / 2.0f);
		float cr = cos(roll / 2.0f);
		x = cy * sp * cr + sy * cp * sr;
		y = sy * cp * cr - cy * sp * sr;
		z = cy * cp * sr - sy * sp * cr;
		w = cy * cp * cr + sy * sp * sr;
		nor();
	}

	constexpr quaternion::quaternion(const vec3f& a, const vec3f& b) noexcept {
		vec3f crs = vec3f(a).crs(b);
		this->x = crs.x;
		this->y = crs.y;
		this->z = crs.z;
		this->w = (a.mag() * b.mag()) + a.dot(b);
		nor();
	}

	constexpr quaternion::quaternion(const vec3f& axis, const float& angle) noexcept {
		float sinHalfAngle = sin(angle / 2.0f);
		this->x = axis.x * sinHalfAngle;
		this->y = axis.y * sinHalfAngle;
		this->z = axis.z * sinHalfAngle;
		this->w = cos(angle / 2.0f);
		nor();
	}

	constexpr quaternion& quaternion::set(const quaternion& quaternion) noexcept {
		this->x = quaternion.x;
		this->y = quaternion.y;
		this->z = quaternion.z;
		this->w = quaternion.w;
		return *this;
	}

	constexpr quaternion& quaternion::set(float x, float y, float z, float w) noexcept {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		return *this;
	}

	constexpr quaternion& quaternion::set(const vec3f& axis, float angle) noexcept {
		float sinHalfAngle = sin(angle / 2.0f);
		this->x = axis.x * sinHalfAngle;
		this->y = axis.y * sinHalfAngle;
		this->z = axis.z * sinHalfAngle;
		this->w = cos(angle / 2.0f);
		nor();
		return *this;
	}

	constexpr quaternion& quaternion::set(const vec3f& a, const vec3f& b) noexcept {
		vec3f crs = vec3f(a).crs(b);
		this->x = crs.x;
		this->y = crs.y;
		this->z = crs.z;
		this->w = (a.mag() * b.mag()) + a.dot(b);
		nor();
		return *this;
	}

	constexpr quaternion& quaternion::set(float yaw, float pitch, float roll) noexcept {
		float sy = sin(yaw / 2.0f);
		float sp = sin(pitch / 2.0f);
		float sr = sin(roll / 2.0f);
		float cy = cos(yaw / 2.0f);
		float cp = cos(pitch / 2.0f);
		float cr = cos(roll / 2.0f);
		x = cy * sp * cr + sy * cp * sr;
		y = sy * cp * cr - cy * sp * sr;
		z = cy * cp * sr - sy * sp * cr;
		w = cy * cp * cr + sy * sp * sr;
		nor();
		return *this;
	}

	constexpr vec3f quaternion::toEuler() const noexcept  {
		float t = y * x + z * w;
		float pole = t > 0.499f ? 1.0f : (t < -0.499f ? -1.0f : 0.0f);
		bool locked = !(pole == 0);
		vec3f angles;
		angles.x = !locked ? atan2(2.0f * (y * w + x * z), 1.0f - 2.0f * (y * y + x * x)) : 0.0f;
		angles.y = !locked ? asin(2.0f * (w * x - z * y)) : pole * static_cast<float>(M_PI) * 0.5f;
		angles.z = !locked ? atan2(2.0f * (w * z + y * x), 1.0f - 2.0f * (x * x + z * z)) : pole * 2.0f * atan2(y, w);
		return angles;
	}

	constexpr float quaternion::mag2() const noexcept {
		return x * x + y * y + z * z + w * w;
	}

	constexpr float quaternion::mag() const noexcept {
		return sqrt(mag2());
	}

	constexpr quaternion& quaternion::conjugate() noexcept {
		x = -x;
		y = -y;
		z = -z;
		return *this;
	}

	constexpr float quaternion::dot(const quaternion& quaternion) const noexcept {
		return x * quaternion.x + y * quaternion.y + z * quaternion.z + w * quaternion.w;
	}

	constexpr quaternion& quaternion::nor() noexcept {
		float mag2 = quaternion::mag2();
		if (mag2 != 0 && mag2 != 1) {
			float mag = sqrt(mag2);
			if (std::is_constant_evaluated()) {
				x /= mag;
				y /= mag;
				z /= mag;
				w /= mag;
			} else {
				simd::reg4f thisreg = simd::load4f4f(x);
				simd::reg4f magreg = simd::load1f4f(mag);
				simd::store4f(x, simd::div4f(thisreg, magreg));
			}
		}
		return *this;
	}

	constexpr quaternion operator+(const quaternion& left, const quaternion& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f r = simd::load4f4f(right.x);
			quaternion out;
			simd::store4f(out.x, simd::add4f(l, r));
			return out;
		}
	}

	constexpr quaternion operator-(const quaternion& left, const quaternion& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f r = simd::load4f4f(right.x);
			quaternion out;
			simd::store4f(out.x, simd::sub4f(l, r));
			return out;
		}
	}

	constexpr quaternion operator*(const quaternion& left, const quaternion& right) noexcept {
		float x = left.w * right.x + left.x * right.w + left.y * right.z - left.z * right.y;
		float y = left.w * right.y + left.y * right.w + left.z * right.x - left.x * right.z;
		float z = left.w * right.z + left.z * right.w + left.x * right.y - left.y * right.x;
		float w = left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z;
		return {x, y, z, w};
	}

	constexpr vec3f operator*(const quaternion& quaternion, const vec3f& vector) noexcept {
		spruce::quaternion conjugate = spruce::quaternion(quaternion).conjugate();
		spruce::quaternion result = quaternion * spruce::quaternion(vector.x, vector.y, vector.z, 0) * conjugate;
		return {result.x, result.y, result.z};
	}

	constexpr vec3f operator*(const vec3f& vector, const quaternion& quaternion) noexcept {
		spruce::quaternion conjugate = spruce::quaternion(quaternion).conjugate();
		spruce::quaternion result = quaternion * spruce::quaternion(vector.x, vector.y, vector.z, 0) * conjugate;
		return {result.x, result.y, result.z};
	}

	constexpr quaternion& quaternion::operator+=(const quaternion& quaternion) noexcept {
		if (std::is_constant_evaluated()) {
			x += quaternion.x;
			y += quaternion.y;
			z += quaternion.z;
			w += quaternion.w;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(x);
			simd::reg4f q = simd::load4f4f(quaternion.x);
			simd::store4f(x, simd::add4f(t, q));
			return *this;
		}
	}

	constexpr quaternion& quaternion::operator-=(const quaternion& quaternion) noexcept {
		if (std::is_constant_evaluated()) {
			x -= quaternion.x;
			y -= quaternion.y;
			z -= quaternion.z;
			w -= quaternion.w;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(x);
			simd::reg4f q = simd::load4f4f(quaternion.x);
			simd::store4f(x, simd::sub4f(t, q));
			return *this;
		}
	}

	constexpr quaternion& quaternion::operator*=(const quaternion& quaternion) noexcept {
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

	constexpr quaternion quaternion::lerp(const quaternion& a, const quaternion& b, float alpha) noexcept {
		return {(1.0f - alpha) * a.x + alpha * b.x, (1.0f - alpha) * a.y + alpha * b.y, (1.0f - alpha) * a.z + alpha * b.z, (1.0f - alpha) * a.w + alpha * b.w};
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
