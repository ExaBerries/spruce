#include <math/random.h>
#include <random>

namespace spruce {
	namespace rand {
		std::seed_seq seedSeq;
		std::uniform_real_distribution<float> realDisf;
		std::uniform_real_distribution<double> realDisd;
		std::normal_distribution<float> norDisf;
		std::normal_distribution<double> norDisd;

		void init(uint64 seed) {
			seedSeq = std::seed_seq(seed);
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

		float rreal(float min, float max) {
			realDisf = std::uniform_real_distribution<float>(min, max);
			return realDisf(seedSeq);
		}

		double rreal(double min, double max) {
			realDisd = std::uniform_real_distribution<double>(min, max);
			return realDisd(seedSeq);
		}

		float rnor(float mean, float stddev) {
			norDisf = std::normal_distribution(mean, stddev);
			return norDisf(seedSeq);
		}

		double rnor(double mean, double stddev) {
			norDisd = std::normal_distribution(mean, stddev);
			return norDisd(seedSeq);
		}
	}
}
