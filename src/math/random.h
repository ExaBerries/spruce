#pragma once
#include <common.h>

namespace spruce {
	namespace rand {
		void init(uint64 seed);
		int32 rint(int32 min, int32 max);
		int32 randSign();
		bool rbool();
		float rreal();
		double rreal();
		float rnor();
		double rnor();
	}
}
