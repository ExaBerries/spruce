#pragma once

namespace spruce {
	namespace simd {
		inline reg4f load4f4f(const float& data) {
			return _mm_load_ps(&data);
		};

		inline reg4f load1f4f(const float& value) {
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

		inline reg2d load2d2d(const double& data) {
			return _mm_load_pd(&data);
		}

		inline reg2d load1d2d(const double& value) {
			return _mm_load1_pd(&value);
		}

		inline void store2d(double& out, const reg2d& reg) {
			_mm_store_pd(&out, reg);
		}

		inline reg2d add2d(const reg2d& a, const reg2d& b) {
			return _mm_add_pd(a, b);
		}

		inline reg2d sub2d(const reg2d& a, const reg2d& b) {
			return _mm_sub_pd(a, b);
		}

		inline reg2d mul2d(const reg2d& a, const reg2d& b) {
			return _mm_mul_pd(a, b);
		}

		inline reg2d div2d(const reg2d& a, const reg2d& b) {
			return _mm_div_pd(a, b);
		}

		inline reg4d load4d4d(const double& data) {
			return _mm256_load_pd(&data);
		}

		inline reg4d load1d4d(const double& value) {
			return _mm256_set1_pd(value);
		}

		inline void store4d(double& out, const reg4d& reg) {
			_mm256_store_pd(&out, reg);
		}

		inline reg4d add4d(const reg4d& a, const reg4d& b) {
			return _mm256_add_pd(a, b);
		}

		inline reg4d sub4d(const reg4d& a, const reg4d& b) {
			return _mm256_sub_pd(a, b);
		}

		inline reg4d mul4d(const reg4d& a, const reg4d& b) {
			return _mm256_mul_pd(a, b);
		}

		inline reg4d div4d(const reg4d& a, const reg4d& b) {
			return _mm256_div_pd(a, b);
		}
	}
}
