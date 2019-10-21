#include <catch2/catch.hpp>
#include <graphics/color.h>

namespace spruce {
	namespace test {
		TEST_CASE("color default construct") {
			color col;
			REQUIRE(col.r == 0.0f);
			REQUIRE(col.g == 0.0f);
			REQUIRE(col.b == 0.0f);
			REQUIRE(col.a == 0.0f);
		}

		TEST_CASE("color rgba construct") {
			color col(0.2f, 0.4f, 0.2f, 1.0f);
			REQUIRE(col.r == 0.2f);
			REQUIRE(col.g == 0.4f);
			REQUIRE(col.b == 0.2f);
			REQUIRE(col.a == 1.0f);
		}

		TEST_CASE("color hex construct") {
			constexpr color col(0xFFFFFFFF);
			REQUIRE(col.r == 1.0f);
			REQUIRE(col.g == 1.0);
			REQUIRE(col.b == 1.0f);
			REQUIRE(col.a == 1.0f);
		}

		TEST_CASE("color equate") {
			REQUIRE(color{0.0f, 1.0f, 0.3f, 0.7f} == color{0.0f, 1.0f, 0.3f, 0.7f});
		}
	}
}
