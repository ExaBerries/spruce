#include <math/math.h>

namespace spruce {
	const float PI = 3.1415926536f;

	float clamp(const float& value, float min, float max) {
		if (value < min) {
			return min;
		} else if (value > max) {
			return max;
		}
		return value;
	}

	float lerp(float a, float b, float alpha) {
		return (1 - alpha) * a + alpha * b;
	}
}
