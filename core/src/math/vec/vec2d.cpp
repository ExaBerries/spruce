#include <math/vec/vec2d.h>

namespace spruce {
	std::ostream& operator<<(std::ostream& stream, const vec2d& vector) {
		stream << "vec2d(" << vector.x << ", " << vector.y << ")";
		return stream;
	}
}
