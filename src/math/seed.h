#pragma once
#include <common.h>
#include <random>

namespace spruce {
	namespace rand {
		struct seed {
			uint64 value;
			std::mt19937_64 mt;

			seed();
			seed(uint64 seed);
			seed(const seed& seed);
			virtual ~seed();

			friend std::ostream& operator<<(std::ostream& stream, const seed& seed);
		};
	}
}
