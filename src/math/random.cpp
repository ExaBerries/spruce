#include <math/random.h>
#include <cstdlib>
#include <ctime>

namespace spruce {
	namespace rand {
		void init(uint64 seed) {
			srand(seed);
		}

		int32 rand(int32 min, int32 max) {
			return std::rand() % max + min;
		}

		bool rand() {
			return std::rand() % 2;
		}

		int32 randSign() {
			return rand() ? 1 : -1;
		}

		float rguassian() {
			return rfloat(); // TODO actual guassian distribution
		}

		float rfloat() {
			return ((float)rand()) / (float) RAND_MAX;
		}

		double rdouble() {
			return ((double)rand()) / (double) RAND_MAX;
		}
	}
}
