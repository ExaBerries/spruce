#pragma once
#include <types.h>
#include <math/seed.h>

namespace spruce {
	namespace rand {
		[[nodiscard]] int32 rint(seed& seed, int32 min, int32 max) noexcept;
		[[nodiscard]] int32 randSign(seed& seed) noexcept;
		[[nodiscard]] bool rbool(seed& seed) noexcept;
		[[nodiscard]] float rrealf(seed& seed, float min, float max) noexcept;
		[[nodiscard]] double rreald(seed& seed, double min, double max) noexcept;
		[[nodiscard]] float rnorf(seed& seed, float mean, float stddev) noexcept;
		[[nodiscard]] double rnord(seed& seed, double mean, double stddev) noexcept;
	}
}
