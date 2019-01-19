#pragma once

namespace spruce {
	namespace simd {
		inline reg4f load4f(const float& data) {
			return _mm_load_ps(&data);
		};

		inline reg4f load1f(const float& value) {
			return _mm_load1_ps(&value);
		}

		inline void store4f(float& out, const reg4f& reg) {
			_mm_store_ps(&out, reg);
		}

		inline reg4f add4f(const reg4f& a, const reg4f& b) {
			return _mm_add_ps(a, b);
		}

		inline reg4f sub4f(const reg4f& a, const reg4f& b) {
			return _mm_sub_ps(a, b);
		}

		inline reg4f mul4f(const reg4f& a, const reg4f& b) {
			return _mm_mul_ps(a, b);
		}

		inline reg4f div4f(const reg4f& a, const reg4f& b) {
			return _mm_div_ps(a, b);
		}
	}
}
