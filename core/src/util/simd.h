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

		inline reg4f load4f4f(const float& data);
		inline reg4f load1f4f(const float& value);

		inline void store4f(float& out, const reg4f& reg);

		inline reg4f add4f(const reg4f& a, const reg4f& b);
		inline reg4f sub4f(const reg4f& a, const reg4f& b);
		inline reg4f mul4f(const reg4f& a, const reg4f& b);
		inline reg4f div4f(const reg4f& a, const reg4f& b);
		inline reg4f fmadd4f(const reg4f& a, const reg4f& b, const reg4f& c);

		inline reg2d load2d2d(const double& data);
		inline reg2d load1d2d(const double& value);

		inline void store2d(double& out, const reg2d& reg);

		inline reg2d add2d(const reg2d& a, const reg2d& b);
		inline reg2d sub2d(const reg2d& a, const reg2d& b);
		inline reg2d mul2d(const reg2d& a, const reg2d& b);
		inline reg2d div2d(const reg2d& a, const reg2d& b);

		inline reg8f load8f8f(const float& data);
		inline reg8f load1f8f(const float& value);

		inline void store8f(float& out, const reg8f& reg);

		inline reg8f add8f(const reg8f& a, const reg8f& b);
		inline reg8f sub8f(const reg8f& a, const reg8f& b);
		inline reg8f mul8f(const reg8f& a, const reg8f& b);
		inline reg8f div8f(const reg8f& a, const reg8f& b);

		inline reg4d load4d4d(const double& data);
		inline reg4d load1d4d(const double& value);

		inline void store4d(double& out, const reg4d& reg);

		inline reg4d add4d(const reg4d& a, const reg4d& b);
		inline reg4d sub4d(const reg4d& a, const reg4d& b);
		inline reg4d mul4d(const reg4d& a, const reg4d& b);
		inline reg4d div4d(const reg4d& a, const reg4d& b);
	}
}

#include <util/simdImpl.h>
