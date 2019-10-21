#include <catch2/catch.hpp>
#include <math/vec/vec3f.h>

namespace spruce {
	namespace test {
		TEST_CASE("assign scalar") {
			vec3f vec = 1;
			REQUIRE(vec == vec3f(1, 1, 1));
		}

		TEST_CASE("equals") {
			vec3f a;
			vec3f b(0, 0, 0);
			REQUIRE(a == b);
		}

		TEST_CASE("normalize") {
			vec3f a(10, 0, 0);
			vec3f b(1, 0, 0);
			a.nor();
			REQUIRE(a == b);
		}

		TEST_CASE("magnitude") {
			const vec3f vec(4, 0, 0);
			REQUIRE(vec.mag() == 4);
		}

		TEST_CASE("vec3f magnitude squared") {
			const vec3f vec(4, 0, 0);
			REQUIRE(vec.mag2() == 16);
		}

		TEST_CASE("vec3f add vector") {
			const vec3f a(2, 0, 2);
			const vec3f b(0, 6, -2);
			REQUIRE(a + b == vec3f(2, 6, 0));
		}

		TEST_CASE("vec3f subtract vector") {
			const vec3f a(2, 0, 2);
			const vec3f b(0, 6, -2);
			REQUIRE(a - b == vec3f(2, -6, 4));
		}

		TEST_CASE("vec3f mul vector") {
			const vec3f a(1, 0, 0);
			const float b = 4;
			REQUIRE(a * b == vec3f(a.x * b, a.y * b, a.z * b));
		}

		TEST_CASE("vec3f div scalar") {
			const vec3f a(8, 0, 0);
			const float b = 4;
			REQUIRE(a / b == vec3f(a.x / b, a.y / b, a.z / b));
		}

		TEST_CASE("vec3f add equals vector") {
			vec3f a(1, 0, 0);
			const vec3f b(0, 1, 0);
			a += b;
			REQUIRE(a == vec3f(1, 1, 0));
		}

		TEST_CASE("vec3f sub equals scalar") {
			vec3f a(1, 0, 0);
			const vec3f b(0, 1, 0);
			a -= b;
			REQUIRE(a == vec3f(1, -1, 0));
		}

		TEST_CASE("vec3f add equals scalar") {
			vec3f a(1, 0, 0);
			const float b = 1;
			a += 1;
			REQUIRE(a == vec3f(2, 1, 1));
		}
	}
}
