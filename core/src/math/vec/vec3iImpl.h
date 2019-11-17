#pragma once

namespace spruce {
	constexpr vec3i::vec3i(int32 scalar) noexcept : x(scalar), y(scalar), z(scalar) {
	}

	constexpr vec3i::vec3i(int32 x, int32 y, int32 z) noexcept : x(x), y(y), z(z) {
	}

	constexpr vec3i::vec3i(const vec2i& vector, int32 z) noexcept : x(vector.x), y(vector.y), z(z) {
	}

	constexpr float vec3i::mag2() const noexcept {
		return static_cast<float>(x * x + y * y + z * z);
	}

	constexpr float vec3i::mag() const noexcept {
		return sqrt(mag2());
	}

	constexpr float vec3i::dst2(const vec3i& vector) const noexcept {
		int32 dx = vector.x - x;
		int32 dy = vector.y - y;
		int32 dz = vector.z - z;
		return static_cast<float>(dx * dx + dy * dy + dz * dz);
	}

	constexpr float vec3i::dst(const vec3i& vector) const noexcept {
		return sqrt(dst2(vector));
	}

	constexpr float vec3i::dot(const vec3i& vector) const noexcept {
		return static_cast<float>(vector.x * x + vector.y * y + vector.z * z);
	}

	constexpr vec3i& vec3i::add(const vec3i& vector) noexcept {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	constexpr vec3i& vec3i::sub(const vec3i& vector) noexcept {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	constexpr vec3i& vec3i::add(int32 value) noexcept {
		x += value;
		y += value;
		z += value;
		return *this;
	}

	constexpr vec3i& vec3i::sub(int32 value) noexcept {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	constexpr vec3i& vec3i::scl(int32 value) noexcept {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	constexpr vec3i& vec3i::div(int32 value) noexcept {
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	constexpr vec3i operator+(const vec3i& left, const vec3i& right) noexcept {
		int32 x = left.x + right.x;
		int32 y = left.y + right.y;
		int32 z = left.z + right.z;
		return {x, y, z};
	}

	constexpr vec3i operator-(const vec3i& left, const vec3i& right) noexcept {
		int32 x = left.x - right.x;
		int32 y = left.y - right.y;
		int32 z = left.z - right.z;
		return {x, y, z};
	}

	constexpr vec3i operator+(const vec3i& left, int32 value) noexcept {
		int32 x = left.x + value;
		int32 y = left.y + value;
		int32 z = left.z + value;
		return {x, y, z};
	}

	constexpr vec3i operator-(const vec3i& left, int32 value) noexcept {
		int32 x = left.x - value;
		int32 y = left.y - value;
		int32 z = left.z - value;
		return {x, y, z};
	}

	constexpr vec3i operator%(const vec3i& left, int32 value) noexcept {
		int32 x = left.x % value;
		int32 y = left.y % value;
		int32 z = left.y % value;
		return {x, y, z};
	}

	constexpr vec3i operator*(const vec3i& left, int32 value) noexcept {
		int32 x = left.x * value;
		int32 y = left.y * value;
		int32 z = left.z * value;
		return {x, y, z};
	}

	constexpr vec3i operator/(const vec3i& left, int32 value) noexcept {
		int32 x = left.x / value;
		int32 y = left.y / value;
		int32 z = left.z / value;
		return {x, y, z};
	}

	constexpr bool vec3i::operator==(const vec3i& vector) const noexcept {
		return (x == vector.x && y == vector.y && z == vector.z);
	}

	constexpr bool vec3i::operator!=(const vec3i& vector) const noexcept {
		return (x != vector.x || y != vector.y || z != vector.z);
	}

	constexpr vec3i& vec3i::operator+=(const vec3i& vector) noexcept {
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	constexpr vec3i& vec3i::operator-=(const vec3i& vector) noexcept {
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	constexpr vec3i& vec3i::operator+=(int32 value) noexcept {
		x += value;
		y += value;
		z += value;
		return *this;
	}

	constexpr vec3i& vec3i::operator-=(int32 value) noexcept {
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	constexpr vec3i& vec3i::operator %=(int32 value) noexcept {
		x %= value;
		y %= value;
		z %= value;
		return *this;
	}

	constexpr vec3i& vec3i::operator*=(int32 value) noexcept {
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	constexpr vec3i& vec3i::operator/=(int32 value) noexcept {
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}
}

namespace std {
	template <>
	struct hash<spruce::vec3i> {
		size_t operator()(const spruce::vec3i& v) const {
			return std::hash<int32>()(v.x) ^ (std::hash<int32>()(v.y) << 1) ^ (std::hash<int32>()(v.z) << 2);
		}
	};
}

