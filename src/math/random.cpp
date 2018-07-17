#include <math/random.h>
#include <random>

namespace spruce {
	namespace rand {
		int32 rint(seed& seed, int32 min, int32 max) {
			std::uniform_int_distribution<int32> intDis = std::uniform_int_distribution<int32>(min, max);
			return intDis(seed.mt);
		}

		bool rbool(seed& seed) {
			std::uniform_int_distribution<int8> intDis = std::uniform_int_distribution<int8>(0, 1);
			return (intDis(seed.mt) == 1) ? true : false;
		}

		int32 randSign(seed& seed) {
			return rbool(seed) ? 1 : -1;
		}

		float rrealf(seed& seed, float min, float max) {
			std::uniform_real_distribution<float> realDisf = std::uniform_real_distribution<float>(min, max);
			return realDisf(seed.mt);
		}

		double rreald(seed& seed, double min, double max) {
			std::uniform_real_distribution<double> realDisd = std::uniform_real_distribution<double>(min, max);
			return realDisd(seed.mt);
		}

		float rnorf(seed& seed, float mean, float stddev) {
			std::normal_distribution<float> norDisf = std::normal_distribution<float>(mean, stddev);
			return norDisf(seed.mt);
		}

		double rnord(seed& seed, double mean, double stddev) {
			std::normal_distribution<double> norDisd = std::normal_distribution<double>(mean, stddev);
			return norDisd(seed.mt);
		}
	}
}
