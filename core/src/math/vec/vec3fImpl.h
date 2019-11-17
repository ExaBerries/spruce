#pragma once

namespace spruce {
	constexpr vec3f::vec3f(float scalar) noexcept : x(scalar), y(scalar), z(scalar) {}

	constexpr vec3f::vec3f(const vec2f& vector, float z) noexcept : x(vector.x), y(vector.y), z(z) {}

	constexpr vec3f::vec3f(float x, float y, float z) noexcept : x(x), y(y), z(z) {}

	constexpr vec3f& vec3f::set(const vec3f& vector) noexcept {
		x = vector.x;
		y = vector.y;
		z = vector.z;
		return *this;
	}

	constexpr vec3f& vec3f::set(const vec2f& vector, float nz) noexcept {
		x = vector.x;
		y = vector.y;
		z = nz;
		return *this;
	}

	constexpr vec3f& vec3f::set(float nx, float ny, float nz) noexcept {
		x = nx;
		y = ny;
		z = nz;
		return *this;
	}

	constexpr float vec3f::mag2() const noexcept {
		return x * x + y * y + z * z;
	}

	constexpr float vec3f::mag() const noexcept {
		return sqrt(mag2());
	}

	constexpr vec3f& vec3f::nor() noexcept {
		float mag2 = vec3f::mag2();
		if (mag2 != 0 && mag2 != 1) {
			float mag = sqrt(mag2);
			x /= mag;
			y /= mag;
			z /= mag;
		}
		return *this;
	}

	constexpr float vec3f::dst2(const vec3f& vector) const noexcept {
		float dx = vector.x - x;
		float dy = vector.y - y;
		float dz = vector.z - z;
		return dx * dx + dy * dy + dz * dz;
	}

	constexpr float vec3f::dst(const vec3f& vector) const noexcept {
		return sqrt(dst2(vector));
	}

	constexpr float vec3f::dot(const vec3f& vector) const noexcept {
		return vector.x * x + vector.y * y + vector.z * z;
	}

	constexpr vec3f& vec3f::crs(const vec3f& vector) noexcept {
		float cx = y * vector.z - z * vector.y;
		float cy = z * vector.x - x * vector.z;
		float cz = x * vector.y - y * vector.x;
		x = cx;
		y = cy;
		z = cz;
		return *this;
	}

	constexpr vec3f& vec3f::add(const vec3f& vector) noexcept {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	constexpr vec3f& vec3f::sub(const vec3f& vector) noexcept {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	constexpr vec3f& vec3f::add(float value) noexcept {
		x += value;
		y += value;
		z += value;
		return *this;
	}

	constexpr vec3f& vec3f::sub(float value) noexcept {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	constexpr vec3f& vec3f::scl(float value) noexcept {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	constexpr vec3f& vec3f::div(float value) noexcept {
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	constexpr bool vec3f::operator==(const vec3f& vector) const noexcept {
		return (x == vector.x && y == vector.y && z == vector.z);
	}

	constexpr bool vec3f::operator!=(const vec3f& vector) const noexcept {
		return (x != vector.x || y != vector.y || z != vector.z);
	}

	constexpr vec3f operator+(const vec3f& left, const vec3f& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x + right.x, left.y + right.y, left.z + right.z};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f r = simd::load4f4f(right.x);
			vec3f out;
			simd::store4f(out.x, simd::add4f(l, r));
			return out;
		}
	}

	constexpr vec3f operator-(const vec3f& left, const vec3f& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x - right.x, left.y - right.y, left.z - right.z};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f r = simd::load4f4f(right.x);
			vec3f out;
			simd::store4f(out.x, simd::sub4f(l, r));
			return out;
		}
	}

	constexpr vec3f operator+(const vec3f& left, const float& value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x + value, left.y + value, left.z + value};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f v = simd::load1f4f(value);
			vec3f out;
			simd::store4f(out.x, simd::add4f(l, v));
			return out;
		}
	}

	constexpr vec3f operator-(const vec3f& left, const float& value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x - value, left.y - value, left.z - value};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f v = simd::load1f4f(value);
			vec3f out;
			simd::store4f(out.x, simd::add4f(l, v));
			return out;
		}
	}

	constexpr vec3f operator*(const vec3f& left, float value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x * value, left.y * value, left.z * value};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f v = simd::load1f4f(value);
			vec3f out;
			simd::store4f(out.x, simd::mul4f(l, v));
			return out;
		}
	}

	constexpr vec3f operator/(const vec3f& left, float value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x / value, left.y / value, left.z / value};
		} else {
			simd::reg4f l = simd::load4f4f(left.x);
			simd::reg4f v = simd::load1f4f(value);
			vec3f out;
			simd::store4f(out.x, simd::div4f(l, v));
			return out;
		}
	}

	constexpr vec3f& vec3f::operator+=(const vec3f& vector) noexcept {
		if (std::is_constant_evaluated()) {
			x += vector.x;
			y += vector.y;
			z += vector.z;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(x);
			simd::reg4f v = simd::load4f4f(vector.x);
			simd::store4f(x, simd::add4f(t, v));
			return *this;
		}
	}

	constexpr vec3f& vec3f::operator-=(const vec3f& vector) noexcept {
		if (std::is_constant_evaluated()) {
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(x);
			simd::reg4f v = simd::load4f4f(vector.x);
			simd::store4f(x, simd::sub4f(t, v));
			return *this;
		}
	}

	constexpr vec3f& vec3f::operator+=(float value) noexcept {
		if (std::is_constant_evaluated()) {
			x += value;
			y += value;
			z += value;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(x);
			simd::reg4f v = simd::load1f4f(value);
			simd::store4f(x, simd::add4f(t, v));
			return *this;
		}
	}

	constexpr vec3f& vec3f::operator-=(float value) noexcept {
		if (std::is_constant_evaluated()) {
			x -= value;
			y -= value;
			z -= value;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(x);
			simd::reg4f v = simd::load1f4f(value);
			simd::store4f(x, simd::sub4f(t, v));
			return *this;
		}
	}

	constexpr vec3f& vec3f::operator*=(float value) noexcept {
		if (std::is_constant_evaluated()) {
			x *= value;
			y *= value;
			z *= value;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(x);
			simd::reg4f v = simd::load1f4f(value);
			simd::store4f(x, simd::mul4f(t, v));
			return *this;
		}
	}

	constexpr vec3f& vec3f::operator/=(float value) noexcept {
		if (std::is_constant_evaluated()) {
			x /= value;
			y /= value;
			z /= value;
			return *this;
		} else {
			simd::reg4f t = simd::load4f4f(x);
			simd::reg4f v = simd::load1f4f(value);
			simd::store4f(x, simd::div4f(t, v));
			return *this;
		}
	}

	constexpr vec3f vec3f::lerp(const vec3f& a, const vec3f& b, float alpha) noexcept {
		return vec3f((1 - alpha) * a.x + alpha * b.x, (1 - alpha) * a.y + alpha * b.y, (1 - alpha) * a.z + alpha * b.z);
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
