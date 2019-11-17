#include <math/vec/vec2f.h>

namespace spruce {
	std::ostream& operator<<(std::ostream& stream, const vec2f& vector) {
		stream << "vec2f(" << vector.x << ", " << vector.y << ")";
		return stream;
	}
}
