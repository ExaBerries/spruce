#pragma once
#include <common.h>

namespace spruce {
	namespace rand {
		void init(uint64 seed);
		int32 rand(int32 min, int32 max);
		int32 randSign();
		bool rand();
		float rguassian();
		float rfloat();
		double rdouble();
	}
}
