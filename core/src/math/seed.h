#pragma once
#include <types.h>
#include <random>
#include <iostream>

namespace spruce {
	namespace rand {
		struct seed {
			uint64 value = 0;
			std::mt19937_64 mt = std::mt19937_64(0);

			seed() = default;
			seed(uint64 seed);
			seed(const seed& seed) = default;
			seed(seed&&) noexcept = default;
			~seed() = default;

			seed& operator=(const seed&) = default;
			seed& operator=(seed&&) noexcept = default;
		};

		std::ostream& operator<<(std::ostream& stream, const seed& seed);
	}
}
