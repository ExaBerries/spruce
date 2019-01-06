#include <math/seed.h>

namespace spruce {
	namespace rand {
		seed::seed() : seed(0) {
		}

		seed::seed(uint64 seed) : value(seed), mt(seed) {
		}

		seed::seed(const seed& seed) {
			this->value = seed.value;
			this->mt = seed.mt;
		}

		seed::~seed() {
		}

		std::ostream& operator<<(std::ostream& stream, const seed& seed) {
			stream << seed.value;
			return stream;
		}
	}
}
