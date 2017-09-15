#include <math/math.h>

namespace spruce {
	const float PI = 3.1415926536;

	float clamp(const float& value, float min, float max) {
		if (value < min) {
			return min;
		} else if (value > max) {
			return max;
		}
		return value;
	}
}
