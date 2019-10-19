#include <catch2/catch.hpp>
#include <math/vec/vec3d.h>

namespace spruce {
	namespace test {
		TEST_CASE("vec3d assign scalar") {
			vec3d vec = 1;
			REQUIRE(vec == vec3d(1, 1, 1));
		}

		TEST_CASE("vec3d equals") {
			vec3d a;
			vec3d b(0, 0, 0);
			REQUIRE(a == b);
		}

		TEST_CASE("vec3d normalize") {
			vec3d a(10, 0, 0);
			vec3d b(1, 0, 0);
			a.nor();
			REQUIRE(a == b);
		}

		TEST_CASE("vec3d magnitude") {
			const vec3d vec(4, 0, 0);
			REQUIRE(vec.mag() == 4);
		}

		TEST_CASE("vec3d magnitude squared") {
			const vec3d vec(4, 0, 0);
			REQUIRE(vec.mag2() == 16);
		}

		TEST_CASE("vec3d add") {
			const vec3d a(2, 0, 2);
			const vec3d b(0, 6, -2);
			REQUIRE(a + b == vec3d(2, 6, 0));
		}

		TEST_CASE("vec3d sub") {
			const vec3d a(2, 0, 2);
			const vec3d b(0, 6, -2);
			REQUIRE(a - b == vec3d(2, -6, 4));
		}

		TEST_CASE("vec3d mul scalar") {
			const vec3d a(1, 0, 0);
			const float b = 4;
			REQUIRE(a * b == vec3d(a.x * b, a.y * b, a.z * b));
		}

		TEST_CASE("vec3d div scalar") {
			const vec3d a(8, 0, 0);
			const float b = 4;
			REQUIRE(a / b == vec3d(a.x / b, a.y / b, a.z / b));
		}

		TEST_CASE("vec3d add equals vector") {
			vec3d a(1, 0, 0);
			const vec3d b(0, 1, 0);
			a += b;
			REQUIRE(a == vec3d(1, 1, 0));
		}

		TEST_CASE("vec3d sub equals vector") {
			vec3d a(1, 0, 0);
			const vec3d b(0, 1, 0);
			a -= b;
			REQUIRE(a == vec3d(1, -1, 0));
		}

		TEST_CASE("vec3d add equals scalar") {
			vec3d a(1, 0, 0);
			const float b = 1;
			a += 1;
			REQUIRE(a == vec3d(2, 1, 1));
		}
	}
}
