#pragma once

namespace spruce {
	inline vec3d operator+(const vec3d& left, const vec3d& right) noexcept {
		simd::reg4d l = simd::load4d4d(left.x);
		simd::reg4d r = simd::load4d4d(right.x);
		vec3d out;
		simd::store4d(out.x, simd::add4d(l, r));
		return out;
	}

	inline vec3d operator-(const vec3d& left, const vec3d& right) noexcept {
		simd::reg4d l = simd::load4d4d(left.x);
		simd::reg4d r = simd::load4d4d(right.x);
		vec3d out;
		simd::store4d(out.x, simd::sub4d(l, r));
		return out;
	}

	inline vec3d operator+(const vec3d& left, double value) noexcept {
		simd::reg4d l = simd::load4d4d(left.x);
		simd::reg4d v = simd::load1d4d(value);
		vec3d out;
		simd::store4d(out.x, simd::add4d(l, v));
		return out;
	}

	inline vec3d operator-(const vec3d& left, double value) noexcept {
		simd::reg4d l = simd::load4d4d(left.x);
		simd::reg4d v = simd::load1d4d(value);
		vec3d out;
		simd::store4d(out.x, simd::sub4d(l, v));
		return out;
	}

	inline vec3d operator*(const vec3d& left, double value) noexcept {
		simd::reg4d l = simd::load4d4d(left.x);
		simd::reg4d v = simd::load1d4d(value);
		vec3d out;
		simd::store4d(out.x, simd::mul4d(l, v));
		return out;
	}

	inline vec3d operator/(const vec3d& left, double value) noexcept {
		simd::reg4d l = simd::load4d4d(left.x);
		simd::reg4d v = simd::load1d4d(value);
		vec3d out;
		simd::store4d(out.x, simd::div4d(l, v));
		return out;
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
