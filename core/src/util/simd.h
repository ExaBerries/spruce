#pragma once
#include <types.h>
#include <xmmintrin.h>

namespace spruce {
	namespace simd {
		using reg4f = __m128;

		inline reg4f load4f(const float& data);
		inline reg4f load1f(const float& value);

		inline void store4f(float& out, const reg4f& reg);

		inline reg4f add4f(const reg4f& a, const reg4f& b);
		inline reg4f sub4f(const reg4f& a, const reg4f& b);
		inline reg4f mul4f(const reg4f& a, const reg4f& b);
		inline reg4f div4f(const reg4f& a, const reg4f& b);
	}
}

#include <util/simdImpl.h>
