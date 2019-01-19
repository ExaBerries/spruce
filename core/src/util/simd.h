#pragma once
#include <types.h>
#include <xmmintrin.h>
#include <immintrin.h>

namespace spruce {
	namespace simd {
		using reg4f = __m128;
		using reg4d = __m256d;

		inline reg4f load4f(const float& data);
		inline reg4f load1f(const float& value);

		inline void store4f(float& out, const reg4f& reg);

		inline reg4f add4f(const reg4f& a, const reg4f& b);
		inline reg4f sub4f(const reg4f& a, const reg4f& b);
		inline reg4f mul4f(const reg4f& a, const reg4f& b);
		inline reg4f div4f(const reg4f& a, const reg4f& b);

		inline reg4d load4d(const double& data);
		inline reg4d load1d(const double& value);

		inline void store4d(double& out, const reg4d& reg);

		inline reg4d add4d(const reg4d& a, const reg4d& b);
		inline reg4d sub4d(const reg4d& a, const reg4d& b);
		inline reg4d mul4d(const reg4d& a, const reg4d& b);
		inline reg4d div4d(const reg4d& a, const reg4d& b);
	}
}

#include <util/simdImpl.h>
