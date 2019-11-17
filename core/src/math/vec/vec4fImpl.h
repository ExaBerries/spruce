#pragma once

namespace spruce {
	constexpr vec4f::vec4f(float scalar) noexcept : x(scalar), y(scalar), z(scalar), w(scalar) {
	}

	constexpr vec4f::vec4f(const vec3f& vector, float w) noexcept : x(vector.x), y(vector.y), z(vector.z), w(w) {
	}

	constexpr vec4f::vec4f(float x, float y, float z, float w) noexcept : x(x), y(y), z(z), w(w) {
	}

	constexpr vec4f& vec4f::set(const vec4f& vector) noexcept {
		x = vector.x;
		y = vector.y;
		z = vector.z;
		w = vector.w;
		return *this;
	}

	constexpr vec4f& vec4f::set(const vec3f& vector, float w) noexcept {
		x = vector.x;
		y = vector.y;
		z = vector.z;
		this->w = w;
		return *this;
	}

	constexpr vec4f& vec4f::set(float x, float y, float z, float w) noexcept {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		return *this;
	}

	constexpr float vec4f::mag2() const noexcept {
		return x * x + y * y + z * z + w * w;
	}

	constexpr float vec4f::mag() const noexcept {
		return sqrt(mag2());
	}

	constexpr vec4f& vec4f::nor() noexcept {
		float mag2 = vec4f::mag2();
		if (mag2 != 0 && mag2 != 1) {
			float mag = sqrt(mag2);
			x /= mag;
			y /= mag;
			z /= mag;
			w /= mag;
		}
		return *this;
	}

	constexpr float vec4f::dst2(const vec4f& vector) const noexcept {
		float dx = vector.x - x;
		float dy = vector.y - y;
		float dz = vector.z - z;
		float dw = vector.w - w;
		return dx * dx + dy * dy + dz * dz + dw * dw;
	}

	constexpr float vec4f::dst(const vec4f& vector) const noexcept {
		return sqrt(dst2(vector));
	}

	constexpr float vec4f::dot(const vec4f& vector) const noexcept {
		return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
	}

	constexpr vec4f& vec4f::add(const vec4f& vector) noexcept {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
		return *this;
	}

	constexpr vec4f& vec4f::sub(const vec4f& vector) noexcept {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
		return *this;
	}

	constexpr vec4f& vec4f::add(float value) noexcept {
		x += value;
		y += value;
		z += value;
		w += value;
		return *this;
	}

	constexpr vec4f& vec4f::sub(float value) noexcept {
		x -= value;
		y -= value;
		z -= value;
		w -= value;
		return *this;
	}

	constexpr vec4f& vec4f::scl(float value) noexcept {
		x *= value;
		y *= value;
		z *= value;
		w *= value;
		return *this;
	}

	constexpr vec4f& vec4f::div(float value) noexcept {
		x /= value;
		y /= value;
		z /= value;
		w /= value;
		return *this;
	}

	constexpr bool vec4f::operator==(const vec4f& vector) const noexcept {
		return (x == vector.x && y == vector.y && z == vector.z && w == vector.w);
	}

	constexpr bool vec4f::operator!=(const vec4f& vector) const noexcept {
		return (x != vector.x || y != vector.y || z != vector.z || w != vector.w);
	}

	constexpr vec4f operator+(const vec4f& left, const vec4f& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f r = simd::load4f4f(right.x);
			vec4f out;
			simd::store4f(out.x, simd::add4f(l, r));
			return out;
		}
	}

	constexpr vec4f operator-(const vec4f& left, const vec4f& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f r = simd::load4f4f(right.x);
			vec4f out;
			simd::store4f(out.x, simd::sub4f(l, r));
			return out;
		}
	}

	constexpr vec4f operator+(const vec4f& left, float value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x + value, left.y + value, left.z + value, left.w + value};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f v = simd::load1f4f(value);
			vec4f out;
			simd::store4f(out.x, simd::add4f(l, v));
			return out;
		}
	}

	constexpr vec4f operator-(const vec4f& left, float value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x - value, left.y - value, left.z - value, left.w - value};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f v = simd::load1f4f(value);
			vec4f out;
			simd::store4f(out.x, simd::sub4f(l, v));
			return out;
		}
	}

	constexpr vec4f operator*(const vec4f& left, float value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x * value, left.y * value, left.z * value, left.w * value};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f v = simd::load1f4f(value);
			vec4f out;
			simd::store4f(out.x, simd::mul4f(l, v));
			return out;
		}
	}

	constexpr vec4f operator/(const vec4f& left, float value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x / value, left.y / value, left.z / value, left.w / value};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f v = simd::load1f4f(value);
			vec4f out;
			simd::store4f(out.x, simd::div4f(l, v));
			return out;
		}
	}

	constexpr vec4f& vec4f::operator+=(const vec4f& vector) noexcept {
		if (std::is_constant_evaluated()) {
			x += vector.x;
			y += vector.y;
			z += vector.z;
			w += vector.w;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(this->x);
			simd::reg4f v = simd::load4f4f(vector.x);
			simd::store4f(this->x, simd::add4f(t, v));
			return *this;
		}
	}

	constexpr vec4f& vec4f::operator-=(const vec4f& vector) noexcept {
		if (std::is_constant_evaluated()) {
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
			w -= vector.w;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(this->x);
			simd::reg4f v = simd::load4f4f(vector.x);
			simd::store4f(this->x, simd::sub4f(t, v));
			return *this;
		}
	}

	constexpr vec4f& vec4f::operator+=(float value) noexcept {
		if (std::is_constant_evaluated()) {
			x += value;
			y += value;
			z += value;
			w += value;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(this->x);
			simd::reg4f v = simd::load1f4f(value);
			simd::store4f(this->x, simd::add4f(t, v));
			return *this;
		}
	}

	constexpr vec4f& vec4f::operator-=(float value) noexcept {
		if (std::is_constant_evaluated()) {
			x -= value;
			y -= value;
			z -= value;
			w -= value;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(this->x);
			simd::reg4f v = simd::load1f4f(value);
			simd::store4f(this->x, simd::sub4f(t, v));
			return *this;
		}
	}

	constexpr vec4f& vec4f::operator*=(float value) noexcept {
		if (std::is_constant_evaluated()) {
			x *= value;
			y *= value;
			z *= value;
			w *= value;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(this->x);
			simd::reg4f v = simd::load1f4f(value);
			simd::store4f(this->x, simd::mul4f(t, v));
			return *this;
		}
	}

	constexpr vec4f& vec4f::operator/=(float value) noexcept {
		if (std::is_constant_evaluated()) {
			x /= value;
			y /= value;
			z /= value;
			w /= value;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(this->x);
			simd::reg4f v = simd::load1f4f(value);
			simd::store4f(this->x, simd::div4f(t, v));
			return *this;
		}
	}


	constexpr vec4f lerp(const vec4f& a, const vec4f& b, float alpha) noexcept {
		float oneMinuaAlpha = 1 - alpha;
		return vec4f(oneMinuaAlpha * a.x + alpha * b.x, oneMinuaAlpha * a.y + alpha * b.y, oneMinuaAlpha * a.z + alpha * b.z, oneMinuaAlpha * a.w + alpha * b.w);
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
