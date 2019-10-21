#pragma once
#include <types.h>
#include <math/seed.h>

namespace spruce {
	namespace rand {
		[[nodiscard]] int32 rint(seed& seed, int32 min, int32 max);
		[[nodiscard]] int32 randSign(seed& seed);
		[[nodiscard]] bool rbool(seed& seed);
		[[nodiscard]] float rrealf(seed& seed, float min, float max);
		[[nodiscard]] double rreald(seed& seed, double min, double max);
		[[nodiscard]] float rnorf(seed& seed, float mean, float stddev);
		[[nodiscard]] double rnord(seed& seed, double mean, double stddev);
	}
}
