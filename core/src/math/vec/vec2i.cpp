#include <math/vec/vec2i.h>

namespace spruce {
	std::ostream& operator<<(std::ostream& stream, const vec2i& vector) {
		stream << "vec2i(" << vector.x << ", " << vector.y << ")";
		return stream;
	}
}
