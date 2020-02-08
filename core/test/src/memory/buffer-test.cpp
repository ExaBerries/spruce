#include <catch2/catch.hpp>
#include <memory/memory.h>

namespace spruce {
	namespace test {
		TEST_CASE("buffer") {
			SECTION("default construct") {
				buffer<int32> buffer;
				REQUIRE((std::is_same_v<decltype(buffer)::ElementType, int32>) == true);
				REQUIRE((std::is_same_v<decltype(buffer)::AllocatorType, std::allocator<int32>>) == true);
				REQUIRE(buffer == nullptr);
				REQUIRE(buffer.data == nullptr);
				REQUIRE(buffer.size == 0);
			}
			SECTION("size construct") {
				constexpr uint64 NUM = 4;
				buffer<int32> buffer(NUM);
				REQUIRE((std::is_same_v<decltype(buffer)::ElementType, int32>) == true);
				REQUIRE((std::is_same_v<decltype(buffer)::AllocatorType, std::allocator<int32>>) == true);
				REQUIRE(buffer != nullptr);
				REQUIRE(buffer.size == NUM);
				buffer.free();
				REQUIRE(buffer == nullptr);
			}
			SECTION("range loop") {
				buffer<int32> buffer{4};
				for ([[maybe_unused]] auto element : buffer) {
				}
			}
		}
	}
}
