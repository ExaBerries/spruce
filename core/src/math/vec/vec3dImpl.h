#pragma once

namespace spruce {
	constexpr vec3d::vec3d(double scalar) noexcept : x(scalar), y(scalar), z(scalar) {
	}

	constexpr vec3d::vec3d(const vec2d& vector, double z) noexcept : x(vector.x), y(vector.y), z(z) {
	}

	constexpr vec3d::vec3d(double x, double y, double z) noexcept : x(x), y(y), z(z) {
	}

	constexpr vec3d& vec3d::set(const vec3d& vector) noexcept {
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
		return *this;
	}

	constexpr vec3d& vec3d::set(double x, double y, double z) noexcept {
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}

	constexpr double vec3d::mag2() const noexcept {
		return x * x + y * y + z * z;
	}

	constexpr double vec3d::mag() const noexcept {
		return sqrt(mag2());
	}

	constexpr vec3d& vec3d::nor() noexcept {
		double mag2 = vec3d::mag2();
		if (mag2 != 0 && mag2 != 1) {
			double mag = sqrt(mag2);
			x /= mag;
			y /= mag;
			z /= mag;
		}
		return *this;
	}

	constexpr double vec3d::dst2(const vec3d& vector) const noexcept {
		double dx = vector.x - x;
		double dy = vector.y - y;
		double dz = vector.z - z;
		return dx * dx + dy * dy + dz * dz;
	}

	constexpr double vec3d::dst(const vec3d& vector) const noexcept {
		return sqrt(dst2(vector));
	}

	constexpr double vec3d::dot(const vec3d& vector) const noexcept {
		return vector.x * x + vector.y * y + vector.z * z;
	}

	constexpr vec3d& vec3d::crs(const vec3d& vector) noexcept {
		double x = this->y * vector.z - this->z * vector.y;
		double y = this->z * vector.x - this->x * vector.z;
		double z = this->x * vector.y - this->y * vector.x;
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}

	constexpr vec3d& vec3d::add(const vec3d& vector) noexcept {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	constexpr vec3d& vec3d::sub(const vec3d& vector) noexcept {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	constexpr vec3d& vec3d::add(double value) noexcept {
		x += value;
		y += value;
		z += value;
		return *this;
	}

	constexpr vec3d& vec3d::sub(double value) noexcept {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	constexpr vec3d& vec3d::scl(double value) noexcept {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	constexpr vec3d& vec3d::div(double value) noexcept {
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	constexpr bool vec3d::operator==(const vec3d& vector) const noexcept {
		return (x == vector.x && y == vector.y && z == vector.z);
	}

	constexpr bool vec3d::operator!=(const vec3d& vector) const noexcept {
		return (x != vector.x || y != vector.y || z != vector.z);
	}

	constexpr vec3d operator+(const vec3d& left, const vec3d& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x + right.x, left.y + right.y, left.z + right.z};
		} else {
			simd::reg4d l = simd::load4d4d(left.x);
			simd::reg4d r = simd::load4d4d(right.x);
			vec3d out;
			simd::store4d(out.x, simd::add4d(l, r));
			return out;
		}
	}

	constexpr vec3d operator-(const vec3d& left, const vec3d& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x - right.x, left.y - right.y, left.z - right.z};
		} else {
			simd::reg4d l = simd::load4d4d(left.x);
			simd::reg4d r = simd::load4d4d(right.x);
			vec3d out;
			simd::store4d(out.x, simd::sub4d(l, r));
			return out;
		}
	}

	constexpr vec3d operator+(const vec3d& left, double value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x + value, left.y + value, left.z + value};
		} else {
			simd::reg4d l = simd::load4d4d(left.x);
			simd::reg4d v = simd::load1d4d(value);
			vec3d out;
			simd::store4d(out.x, simd::add4d(l, v));
			return out;
		}
	}

	constexpr vec3d operator-(const vec3d& left, double value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x - value, left.y - value, left.z - value};
		} else {
			simd::reg4d l = simd::load4d4d(left.x);
			simd::reg4d v = simd::load1d4d(value);
			vec3d out;
			simd::store4d(out.x, simd::sub4d(l, v));
			return out;
		}
	}

	constexpr vec3d operator*(const vec3d& left, double value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x * value, left.y * value, left.z * value};
		} else {
			simd::reg4d l = simd::load4d4d(left.x);
			simd::reg4d v = simd::load1d4d(value);
			vec3d out;
			simd::store4d(out.x, simd::mul4d(l, v));
			return out;
		}
	}

	constexpr vec3d operator/(const vec3d& left, double value) noexcept {
		if (std::is_constant_evaluated()) {
			return {left.x / value, left.y / value, left.z / value};
		} else {
			simd::reg4d l = simd::load4d4d(left.x);
			simd::reg4d v = simd::load1d4d(value);
			vec3d out;
			simd::store4d(out.x, simd::div4d(l, v));
			return out;
		}
	}

	constexpr vec3d& vec3d::operator+=(const vec3d& vector) noexcept {
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
		return *this;
	}

	constexpr vec3d& vec3d::operator-=(const vec3d& vector) noexcept {
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;
		return *this;
	}

	constexpr vec3d& vec3d::operator+=(double value) noexcept {
		this->x += value;
		this->y += value;
		this->z += value;
		return *this;
	}

	constexpr vec3d& vec3d::operator-=(double value) noexcept {
		this->x -= value;
		this->y -= value;
		this->z -= value;
		return *this;
	}

	constexpr vec3d& vec3d::operator*=(double value) noexcept {
		this->x *= value;
		this->y *= value;
		this->z *= value;
		return *this;
	}

	constexpr vec3d& vec3d::operator/=(double value) noexcept {
		this->x /= value;
		this->y /= value;
		this->z /= value;
		return *this;
	}

	constexpr vec3d vec3d::lerp(const vec3d& a, const vec3d& b, double alpha) noexcept {
		return vec3d((1 - alpha) * a.x + alpha * b.x, (1 - alpha) * a.y + alpha * b.y, (1 - alpha) * a.z + alpha * b.z);
	}
}

namespace std {
	template <>
	struct hash<spruce::vec3d> {
		size_t operator()(const spruce::vec3d& v) const {
			return std::hash<double>()(v.x) ^ (std::hash<double>()(v.y) << 1) ^ (std::hash<double>()(v.z) << 2);
		}
	};
}
