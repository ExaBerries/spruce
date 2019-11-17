#include <math/vec/vec4f.h>

namespace spruce {
	std::ostream& operator<<(std::ostream& stream, const vec4f& vector) {
		std::cout << "vec4f(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return stream;
	}
}
