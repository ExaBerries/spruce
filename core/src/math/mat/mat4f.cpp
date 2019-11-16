#include <math/mat/mat4f.h>
#include <cstring>

namespace spruce {
	std::ostream& operator<<(std::ostream& stream, const mat4f& matrix) {
		stream << "mat4f(";
		for (int i = 0; i < 16; i++) {
			stream << matrix.values[i] << ", ";
		}
		stream << matrix.values[15] << ")";
		return stream;
	}
}
