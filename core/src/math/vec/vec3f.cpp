#include <math/vec/vec3f.h>

namespace spruce {
	std::ostream& operator<<(std::ostream& stream, const vec3f& vector) {
		stream << "vec3f(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}
}
