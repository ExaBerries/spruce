#pragma once

namespace spruce {
	namespace simd {
		[[gnu::always_inline, nodiscard]] inline reg4f load4f4f(const float& data) noexcept {
			return _mm_load_ps(&data);
		}

		[[gnu::always_inline, nodiscard]] inline reg4f load1f4f(const float& value) noexcept {
			return _mm_load1_ps(&value);
		}

		[[gnu::always_inline]] inline void store4f(float& out, const reg4f& reg) noexcept {
			_mm_store_ps(&out, reg);
		}

		[[gnu::always_inline, nodiscard]] inline reg4f add4f(const reg4f& a, const reg4f& b) noexcept {
			return _mm_add_ps(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg4f sub4f(const reg4f& a, const reg4f& b) noexcept {
			return _mm_sub_ps(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg4f mul4f(const reg4f& a, const reg4f& b) noexcept {
			return _mm_mul_ps(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg4f div4f(const reg4f& a, const reg4f& b) noexcept {
			return _mm_div_ps(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg4f fmadd4f(const reg4f& a, const reg4f& b, const reg4f& c) noexcept {
			return _mm_fmadd_ps(a, b, c);
		}

		template <int32 m0, int32 m1, int32 m2, int32 m3>
		[[gnu::always_inline, nodiscard]] inline reg4f shuffle4f(const reg4f& a, const reg4f& b) noexcept {
			return _mm_shuffle_ps(a, b, _MM_SHUFFLE(m0, m1, m2, m3));
		}

		[[gnu::always_inline, nodiscard]] inline reg2d load2d2d(const double& data) noexcept {
			return _mm_load_pd(&data);
		}

		[[gnu::always_inline, nodiscard]] inline reg2d load1d2d(const double& value) noexcept {
			return _mm_load1_pd(&value);
		}

		[[gnu::always_inline]] inline void store2d(double& out, const reg2d& reg) noexcept {
			_mm_store_pd(&out, reg);
		}

		[[gnu::always_inline, nodiscard]] inline reg2d add2d(const reg2d& a, const reg2d& b) noexcept {
			return _mm_add_pd(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg2d sub2d(const reg2d& a, const reg2d& b) noexcept {
			return _mm_sub_pd(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg2d mul2d(const reg2d& a, const reg2d& b) noexcept {
			return _mm_mul_pd(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg2d div2d(const reg2d& a, const reg2d& b) noexcept {
			return _mm_div_pd(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg8f load8f8f(const float& data) noexcept {
			return _mm256_load_ps(&data);
		}

		[[gnu::always_inline, nodiscard]] inline reg8f load1f8f(const float& value) noexcept {
			return _mm256_set1_ps(value);
		}

		[[gnu::always_inline]] inline void store8f(float& out, const reg8f& reg) noexcept {
			_mm256_store_ps(&out, reg);
		}

		[[gnu::always_inline, nodiscard]] inline reg8f add8f(const reg8f& a, const reg8f& b) noexcept {
			return _mm256_add_ps(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg8f sub8f(const reg8f& a, const reg8f& b) noexcept {
			return _mm256_sub_ps(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg8f mul8f(const reg8f& a, const reg8f& b) noexcept {
			return _mm256_mul_ps(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg8f div8f(const reg8f& a, const reg8f& b) noexcept {
			return _mm256_div_ps(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg4d load4d4d(const double& data) noexcept {
			return _mm256_load_pd(&data);
		}

		[[gnu::always_inline, nodiscard]] inline reg4d load1d4d(const double& value) noexcept {
			return _mm256_set1_pd(value);
		}

		[[gnu::always_inline]] inline void store4d(double& out, const reg4d& reg) noexcept {
			_mm256_store_pd(&out, reg);
		}

		[[gnu::always_inline, nodiscard]] inline reg4d add4d(const reg4d& a, const reg4d& b) noexcept {
			return _mm256_add_pd(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg4d sub4d(const reg4d& a, const reg4d& b) noexcept {
			return _mm256_sub_pd(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg4d mul4d(const reg4d& a, const reg4d& b) noexcept {
			return _mm256_mul_pd(a, b);
		}

		[[gnu::always_inline, nodiscard]] inline reg4d div4d(const reg4d& a, const reg4d& b) noexcept {
			return _mm256_div_pd(a, b);
		}
	}
}
