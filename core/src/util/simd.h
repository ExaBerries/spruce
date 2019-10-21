#pragma once
#include <types.h>
#include <xmmintrin.h>
#include <immintrin.h>

namespace spruce {
	namespace simd {
		using reg4f = __m128;
		using reg2d = __m128d;
		using reg8f = __m256;
		using reg4d = __m256d;

		[[gnu::always_inline, nodiscard]] inline reg4f load4f4f(const float& data) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg4f load1f4f(const float& value) noexcept;

		[[gnu::always_inline]] inline void store4f(float& out, const reg4f& reg) noexcept;

		[[gnu::always_inline, nodiscard]] inline reg4f add4f(const reg4f& a, const reg4f& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg4f sub4f(const reg4f& a, const reg4f& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg4f mul4f(const reg4f& a, const reg4f& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg4f div4f(const reg4f& a, const reg4f& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg4f fmadd4f(const reg4f& a, const reg4f& b, const reg4f& c) noexcept;
		template <int32 m0, int32 m1, int32 m2, int32 m3>
		[[gnu::always_inline, nodiscard]] inline reg4f shuffle4f(const reg4f& a, const reg4f& b) noexcept;

		[[gnu::always_inline, nodiscard]] inline reg2d load2d2d(const double& data) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg2d load1d2d(const double& value) noexcept;

		[[gnu::always_inline]] inline void store2d(double& out, const reg2d& reg) noexcept;

		[[gnu::always_inline, nodiscard]] inline reg2d add2d(const reg2d& a, const reg2d& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg2d sub2d(const reg2d& a, const reg2d& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg2d mul2d(const reg2d& a, const reg2d& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg2d div2d(const reg2d& a, const reg2d& b) noexcept;

		[[gnu::always_inline, nodiscard]] inline reg8f load8f8f(const float& data) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg8f load1f8f(const float& value) noexcept;

		[[gnu::always_inline]] inline void store8f(float& out, const reg8f& reg) noexcept;

		[[gnu::always_inline, nodiscard]] inline reg8f add8f(const reg8f& a, const reg8f& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg8f sub8f(const reg8f& a, const reg8f& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg8f mul8f(const reg8f& a, const reg8f& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg8f div8f(const reg8f& a, const reg8f& b) noexcept;

		[[gnu::always_inline, nodiscard]] inline reg4d load4d4d(const double& data) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg4d load1d4d(const double& value) noexcept;

		[[gnu::always_inline]] inline void store4d(double& out, const reg4d& reg) noexcept;

		[[gnu::always_inline, nodiscard]] inline reg4d add4d(const reg4d& a, const reg4d& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg4d sub4d(const reg4d& a, const reg4d& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg4d mul4d(const reg4d& a, const reg4d& b) noexcept;
		[[gnu::always_inline, nodiscard]] inline reg4d div4d(const reg4d& a, const reg4d& b) noexcept;
	}
}

#include <util/simdImpl.h>
