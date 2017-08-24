#include <math/random.h>
#include <random>

namespace spruce {
	namespace rand {
		std::mt19937 seed;
		std::uniform_real_distribution<float> realDisf;
		std::uniform_real_distribution<double> realDisd;
		std::normal_distribution<float> norDisf;
		std::normal_distribution<double> norDisd;

		void init(uint64 seed) {
			rand::seed = std::mt19937(seed);
			srand(seed);
		}

		int32 rint(int32 min, int32 max) {
			return std::rand() % max + min;
		}

		bool rbool() {
			return std::rand() % 2;
		}

		int32 randSign() {
			return rbool() ? 1 : -1;
		}

		float rrealf(float min, float max) {
			realDisf = std::uniform_real_distribution<float>(min, max);
			return realDisf(seed);
		}

		double rreald(double min, double max) {
			realDisd = std::uniform_real_distribution<double>(min, max);
			return realDisd(seed);
		}

		float rnorf(float mean, float stddev) {
			norDisf = std::normal_distribution<float>(mean, stddev);
			return norDisf(seed);
		}

		double rnord(double mean, double stddev) {
			norDisd = std::normal_distribution<double>(mean, stddev);
			return norDisd(seed);
		}
	}
}
