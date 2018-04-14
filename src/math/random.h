#pragma once
#include <common.h>
#include <math/seed.h>

namespace spruce {
	namespace rand {
		int32 rint(seed& seed, int32 min, int32 max);
		int32 randSign(seed& seed);
		bool rbool(seed& seed);
		float rrealf(seed& seed, float min, float max);
		double rreald(seed& seed, double min, double max);
		float rnorf(seed& seed, float mean, float stddev);
		double rnord(seed& seed, double mean, double stddev);
	}
}
