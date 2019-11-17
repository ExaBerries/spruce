#include <catch2/catch.hpp>
#include <math/vec/vec3f.h>
#include <math/vec/vec3d.h>
#include <math/vec/vec3i.h>

namespace spruce {
	namespace test {
		TEMPLATE_TEST_CASE("vec3x", "", vec3f, vec3d, vec3i) {
			using ValType = decltype(TestType().x);

			REQUIRE(std::is_nothrow_default_constructible_v<TestType>);
			REQUIRE(std::is_nothrow_copy_constructible_v<TestType>);
			REQUIRE(std::is_nothrow_move_constructible_v<TestType>);
			REQUIRE(std::is_nothrow_destructible_v<TestType>);
			REQUIRE(std::is_nothrow_copy_assignable_v<TestType>);
			REQUIRE(std::is_nothrow_move_assignable_v<TestType>);

			SECTION("construct") {
				SECTION("scalar") {
					REQUIRE(std::is_nothrow_constructible_v<TestType, ValType>);
					SECTION("runtime") {
						const TestType vec = 1;
						REQUIRE(vec == TestType(1, 1, 1));
					}
					SECTION("compile time") {
						constexpr TestType vec = 1;
						REQUIRE(vec == TestType(1, 1, 1));
					}
				}
				SECTION("xy") {
					REQUIRE(std::is_nothrow_constructible_v<TestType, ValType, ValType, ValType>);
					SECTION("runtime") {
						const TestType vec = {1, 1, 1};
						REQUIRE(vec == TestType(1, 1, 1));
					}
					SECTION("compile time") {
						constexpr TestType vec = {1, 1, 1};
						REQUIRE(vec == TestType(1, 1, 1));
					}
				}
			}

			SECTION("equals") {
				SECTION("runtime") {
					const TestType a;
					const TestType b(0, 0, 0);
					REQUIRE(a == b);
				}
				SECTION("compile time") {
					constexpr TestType a;
					constexpr TestType b(0, 0, 0);
					constexpr bool eq = a == b;
					REQUIRE(eq);
				}
			}

			if constexpr (std::is_floating_point_v<TestType>) {
				SECTION("normalize") {
					SECTION("runtime") {
						TestType a(10, 0, 0);
						const TestType b(1, 0, 0);
						a.nor();
						REQUIRE(a == b);
					}
					SECTION("compile time") {
						constexpr TestType a = TestType(10, 0, 0).nor();
						constexpr TestType b(1, 0, 0);
						REQUIRE(a == b);
					}
				}
			}

			SECTION("magnitude") {
				SECTION("runtime") {
					const TestType vec(4, 0, 0);
					REQUIRE(vec.mag() == 4);
				}
				SECTION("compile time") {
					constexpr TestType vec(4, 0, 0);
					constexpr ValType mag = vec.mag();
					REQUIRE(mag == 4);
				}
			}

			SECTION("magnitude squared") {
				SECTION("runtime") {
					const TestType vec(4, 0, 0);
					REQUIRE(vec.mag2() == 16);
				}
				SECTION("compile time") {
					constexpr TestType vec(4, 0, 0);
					constexpr ValType mag2 = vec.mag2();
					REQUIRE(mag2 == 16);
				}
			}

			SECTION("add vector") {
				SECTION("runtime") {
					const TestType a(2, 0, 2);
					const TestType b(0, 6, -2);
					REQUIRE(a + b == TestType(2, 6, 0));
				}
				SECTION("compile time") {
					constexpr TestType a(2, 0, 2);
					constexpr TestType b(0, 6, -2);
					constexpr TestType c = a + b;
					REQUIRE(c == TestType(2, 6, 0));
				}
			}

			SECTION("sub vector") {
				SECTION("runtime") {
					const TestType a(2, 0, 2);
					const TestType b(0, 6, -2);
					REQUIRE(a - b == TestType(2, -6, 4));
				}
				SECTION("compile time") {
					constexpr TestType a(2, 0, 2);
					constexpr TestType b(0, 6, -2);
					constexpr TestType c = a - b;
					REQUIRE(c == TestType(2, -6, 4));
				}
			}

			SECTION("mul scalar") {
				SECTION("runtime") {
					const TestType a(1, 0, 0);
					const ValType b = 4;
					REQUIRE(a * b == TestType(4, 0, 0));
				}
				SECTION("compile time") {
					constexpr TestType a(1, 0, 0);
					constexpr ValType b = 4;
					constexpr TestType c = a * b;
					REQUIRE(c == TestType(4, 0, 0));
				}
			}

			SECTION("div scalar") {
				SECTION("runtime") {
					const TestType a(8, 0, 0);
					const ValType b = 4;
					REQUIRE(a / b == TestType(2, 0, 0));
				}
				SECTION("compile time") {
					constexpr TestType a(8, 0, 0);
					constexpr ValType b = 4;
					constexpr TestType c = a / b;
					REQUIRE(c == TestType(2, 0, 0));
				}
			}

			SECTION("add equals vector") {
				TestType a(1, 0, 0);
				const TestType b(0, 1, 0);
				a += b;
				REQUIRE(a == TestType(1, 1, 0));
			}

			SECTION("sub equals vector") {
				TestType a(1, 0, 0);
				const TestType b(0, 1, 0);
				a -= b;
				REQUIRE(a == TestType(1, -1, 0));
			}

			SECTION("add equals scalar") {
				TestType a(1, 0, 0);
				const ValType b = 1;
				a += 1;
				REQUIRE(a == TestType(2, 1, 1));
			}

			SECTION("sub equals scalar") {
				TestType a(1, 0, 0);
				const ValType b = 1;
				a -= 1;
				REQUIRE(a == TestType(0, -1, -1));
			}
		}
	}
}
