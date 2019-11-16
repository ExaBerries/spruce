#include <math/quaternion.h>

namespace spruce {
	std::ostream& operator<<(std::ostream& stream, const quaternion& quaternion) {
		stream << "quaternion(" << quaternion.x << ", " << quaternion.y << ", " << quaternion.z << ", " << quaternion.w << ")";
		return stream;
	}
}
