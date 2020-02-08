#include <catch2/catch.hpp>
#include <memory/memory.h>

namespace spruce {
	namespace test {
		TEST_CASE("stackpoly") {
			struct Base {
				uintptr_t a{4};

				virtual ~Base() noexcept = default;

				[[nodiscard]] constexpr virtual bool f() const noexcept {
					return false;
				}
			};
			struct Derived : public Base {
				ssize_t b{};

				[[nodiscard]] constexpr bool f() const noexcept final {
					return true;
				}
			};
			stackpoly<Base, sizeof(Derived)> sp;
			REQUIRE((std::is_same_v<decltype(sp)::Type, Base>) == true);
			REQUIRE((std::is_same_v<decltype(*sp), Base&>) == true);
			REQUIRE((sp == nullptr) == true);
			sp.cons<Derived>();
			REQUIRE((sp != nullptr) == true);
			REQUIRE(sp->f() == true);
			sp.desc();
			REQUIRE((sp == nullptr) == true);
		}
	}
}
