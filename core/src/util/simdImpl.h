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

		inline reg4d load4d(const double& data) {
			return _mm256_load_pd(&data);
		}

		inline reg4d load1d(const double& value) {
			double val[4];
			val[0] = value;
			val[1] = value;
			val[2] = value;
			val[3] = value;
			return _mm256_loadu_pd(val);
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
