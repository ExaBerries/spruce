#include <catch2/catch.hpp>
#include <memory/memory.h>

namespace spruce {
	namespace test {
		TEST_CASE("default construct") {
			buffer<int32> buffer;
			REQUIRE(buffer == nullptr);
			REQUIRE(buffer.data == nullptr);
			REQUIRE(buffer.size == 0);
		}

		TEST_CASE("size construct") {
			constexpr uint64 NUM = 4;
			buffer<int32> buffer(NUM);
			REQUIRE(buffer != nullptr);
			REQUIRE(buffer.size == NUM);
			buffer.free();
			REQUIRE(buffer == nullptr);
		}
	}
}
