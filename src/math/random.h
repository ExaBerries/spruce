#pragma once
#include <common.h>

namespace spruce {
	namespace rand {
		void init(uint64 seed);
		int32 rint(int32 min, int32 max);
		int32 randSign();
		bool rbool();
		float rrealf(float min, float max);
		double rreald(double min, double max);
		float rnorf(float mean, float stddev);
		double rnord(double mean, double stddev);
	}
}
