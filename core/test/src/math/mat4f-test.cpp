#include <catch2/catch.hpp>
#include <math/mat/mat4f.h>

namespace spruce {
	namespace test {
		TEST_CASE("mat4f") {
			REQUIRE(std::is_nothrow_default_constructible_v<mat4f>);
			REQUIRE(std::is_nothrow_copy_constructible_v<mat4f>);
			REQUIRE(std::is_nothrow_move_constructible_v<mat4f>);
			REQUIRE(std::is_nothrow_destructible_v<mat4f>);
			REQUIRE(std::is_nothrow_copy_assignable_v<mat4f>);
			REQUIRE(std::is_nothrow_move_assignable_v<mat4f>);

			SECTION("construct") {
				SECTION("default") {
					SECTION("runtime") {
						const mat4f mat;
						REQUIRE(mat == mat4f{
							1, 0, 0, 0,
							0, 1, 0, 0,
							0, 0, 1, 0,
							0, 0, 0, 1
						});
					}
					SECTION("compile time") {
						constexpr mat4f mat;
						REQUIRE(mat == mat4f{
							1, 0, 0, 0,
							0, 1, 0, 0,
							0, 0, 1, 0,
							0, 0, 0, 1
						});
					}
				}
			}

			SECTION("add") {
				SECTION("runtime") {
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
				SECTION("compile time") {
					constexpr mat4f a = {
						1, 0, 9, 0,
						2, 0, 0, 6,
						0, 0, 5, 0,
						4, 0, 0, 1,
					};
					constexpr mat4f b = {
						8, 0, 9, 2,
						2, 3, 0, 4,
						0, 4, 9, 2,
						4, 6, 0, 1,
					};
					constexpr mat4f result = a + b;
					constexpr mat4f expected = {
						9, 0, 18, 2,
						4, 3, 0, 10,
						0, 4, 14, 2,
						8, 6, 0, 2
					};
					REQUIRE(result == expected);
				}
			}

			SECTION("mul") {
				SECTION("runtime") {
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
				SECTION("compile time") {
					constexpr mat4f a = {
						1, 0, 9, 0,
						2, 0, 0, 6,
						0, 0, 5, 0,
						4, 0, 0, 1,
					};
					constexpr mat4f b = {
						8, 0, 9, 2,
						2, 3, 0, 4,
						0, 4, 9, 2,
						4, 6, 0, 1,
					};
					constexpr mat4f result = a * b;
					constexpr mat4f expected = {
						8, 36, 90, 20,
						40, 36, 18, 10,
						0, 20, 45, 10,
						36, 6, 36, 9
					};
					REQUIRE(result == expected);
				}
			}

			SECTION("determinant") {
				SECTION("runtime") {
					mat4f a = {
						9, 1, 3, 7,
						5, 9, 6, 1,
						3, 7, 3, 0,
						6, 2, 8, 3
					};
					REQUIRE(a.determinant() == 152);
				}
				SECTION("compile time") {
					constexpr mat4f a = {
						9, 1, 3, 7,
						5, 9, 6, 1,
						3, 7, 3, 0,
						6, 2, 8, 3
					};
					constexpr float det = a.determinant();
					REQUIRE(det == 152);
				}
			}

			SECTION("invert") {
				SECTION("runtime") {
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
				SECTION("compile time") {
					constexpr mat4f a = {
						2, 0, 2, 0,
						2, 0, 0, 2,
						0, 0, 2, 0,
						2, 2, 0, 2,
					};
					REQUIRE(a.determinant() == -16);
					constexpr mat4f b = mat4f(a).invert();
					constexpr mat4f result = a * b;
					constexpr mat4f expected = {
						1, 0, 0, 0,
						0, 1, 0, 0,
						0, 0, 1, 0,
						0, 0, 0, 1
					};
					REQUIRE(result == expected);
				}
			}

			SECTION("transpose") {
				SECTION("runtime") {
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
				SECTION("compile time") {
					constexpr mat4f a = mat4f{
						1, 0, 9, 0,
						2, 0, 0, 6,
						0, 0, 5, 0,
						4, 0, 0, 1,
					}.transpose();
					constexpr mat4f expected = {
						1, 2, 0, 4,
						0, 0, 0, 0,
						9, 0, 5, 0,
						0, 6, 0, 1
					};
					REQUIRE(a == expected);
				}
			}


			SECTION("transform vec3f") {
				SECTION("runtime") {
					mat4f m = {{0, 4, 0}, {}, {2, 1, 2}};
					vec3f v = {8, 2.2, 7};
					REQUIRE(m * v == vec3f(16, 6.2, 14));
				}
				SECTION("compile time") {
					constexpr mat4f m = {{0, 4, 0}, {}, {2, 1, 2}};
					constexpr vec3f v = {8, 2.2, 7};
					constexpr vec3f result = m * v;
					REQUIRE(result == vec3f(16, 6.2, 14));
				}
			}

			SECTION("transform vec4f") {
				SECTION("runtime") {
					mat4f m = {{0, 4, 0}, {}, {2, 1, 2}};
					vec4f v = {8, 2.2, 7, 1};
					REQUIRE(m * v == vec4f(16, 6.2, 14, 1));
				}
				SECTION("compile time") {
					constexpr mat4f m = {{0, 4, 0}, {}, {2, 1, 2}};
					constexpr vec4f v = {8, 2.2, 7, 1};
					constexpr vec4f result = m * v;
					REQUIRE(result == vec4f(16, 6.2, 14, 1));
				}
			}
		}
	}
}

