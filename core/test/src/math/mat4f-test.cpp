#include <catch2/catch.hpp>
#include <math/mat/mat4f.h>

namespace spruce {
	namespace test {
		TEST_CASE("mat4f add") {
			mat4f a = {
				1, 0, 9, 0,
				2, 0, 0, 6,
				0, 0, 5, 0,
				4, 0, 0, 1,
			};
			mat4f b = {
				8, 0, 9, 2,
				2, 3, 0, 4,
				0, 4, 9, 2,
				4, 6, 0, 1,
			};
			mat4f result = a + b;
			mat4f expected = {
				9, 0, 18, 2,
				4, 3, 0, 10,
				0, 4, 14, 2,
				8, 6, 0, 2
			};
			REQUIRE(result == expected);
		}

		TEST_CASE("mat4f mul") {
			mat4f a = {
				1, 0, 9, 0,
				2, 0, 0, 6,
				0, 0, 5, 0,
				4, 0, 0, 1,
			};
			mat4f b = {
				8, 0, 9, 2,
				2, 3, 0, 4,
				0, 4, 9, 2,
				4, 6, 0, 1,
			};
			mat4f result = a * b;
			mat4f expected = {
				8, 36, 90, 20,
				40, 36, 18, 10,
				0, 20, 45, 10,
				36, 6, 36, 9
			};
			REQUIRE(result == expected);
		}

		TEST_CASE("mat4f determinant") {
			mat4f a = {
				9, 1, 3, 7,
				5, 9, 6, 1,
				3, 7, 3, 0,
				6, 2, 8, 3
			};
			REQUIRE(a.determinant() == 152);
		}

		TEST_CASE("mat4f invert") {
			mat4f a = {
				2, 0, 2, 0,
				2, 0, 0, 2,
				0, 0, 2, 0,
				2, 2, 0, 2,
			};
			REQUIRE(a.determinant() == -16);
			mat4f b = mat4f(a).invert();
			mat4f result = a * b;
			mat4f expected = {
				1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1
			};
			REQUIRE(result == expected);
		}

		TEST_CASE("mat4f transpose") {
			mat4f a = {
				1, 0, 9, 0,
				2, 0, 0, 6,
				0, 0, 5, 0,
				4, 0, 0, 1,
			};
			mat4f b = a.transpose();
			mat4f expected = {
				1, 2, 0, 4,
				0, 0, 0, 0,
				9, 0, 5, 0,
				0, 6, 0, 1
			};
			REQUIRE(b == expected);
		}


		TEST_CASE("mat4f transform vec3f") {
			mat4f m = {{0, 4, 0}, {}, {2, 1, 2}};
			vec3f v = {8, 2.2, 7};
			REQUIRE(m * v == vec3f(16, 6.2, 14));
		}

		TEST_CASE("mat4f transform vec4f") {
			mat4f m = {{0, 4, 0}, {}, {2, 1, 2}};
			vec4f v = {8, 2.2, 7, 1};
			REQUIRE(m * v == vec4f(16, 6.2, 14, 1));
		}
	}
}
