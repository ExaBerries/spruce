#include <math/seed.h>

namespace spruce {
	namespace rand {
		seed::seed(uint64 seed) : value(seed), mt(seed) {
		}

		std::ostream& operator<<(std::ostream& stream, const seed& seed) {
			stream << seed.value;
			return stream;
		}
	}
}
