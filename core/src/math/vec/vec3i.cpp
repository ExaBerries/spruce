#include <math/vec/vec3i.h>

namespace spruce {
	std::ostream& operator<<(std::ostream& stream, const vec3i& vector) {
		stream << "vec3i(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}
}
