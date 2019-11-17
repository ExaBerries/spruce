#include <math/vec/vec3d.h>

namespace spruce {
	std::ostream& operator<<(std::ostream& stream, const vec3d& vector) {
		stream << "vec3d(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}
}
