#pragma once
#include <xmmintrin.h>

namespace spruce {
	inline vec3f operator+(const vec3f& left, const vec3f& right) {
		__m128 l = _mm_load_ps(&left.x);
		__m128 r = _mm_load_ps(&right.x);
		vec3f out;
		_mm_store_ps(&out.x, _mm_add_ps(l, r));
		return out;
	}

	inline vec3f operator*(const vec3f& left, float value) {
		__m128 l = _mm_load_ps(&left.x);
		__m128 r = _mm_load_ps1(&value);
		vec3f out;
		_mm_store_ps(&out.x, _mm_mul_ps(l, r));
		return out;
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
