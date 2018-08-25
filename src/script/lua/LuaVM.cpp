#include <script/lua/LuaVM.h>

namespace spruce {
	namespace lua {
		void luaPanic(sol::optional<std::string> msg) {
			serr("lua panic");
			if (msg) {
				serr(msg.value());
			}
		}

		void luaPrint(sol::variadic_args va) {
			for (uint16 i = 0; i < va.size(); i++) {
				auto arg = va[i];
				sol::type type = arg.get_type();
				switch (type) {
					case sol::type::string:
						spruce::log::print(arg.as<string>());
						break;
					case sol::type::number:
						spruce::log::print(arg.as<double>());
						break;
					case sol::type::lua_nil:
						spruce::log::print("nil");
						break;
					case sol::type::boolean:
						spruce::log::print(arg.as<bool>());
						break;
					default:
						serr("could not print lua data");
						break;
				}
				if (i < va.size() - 1) {
					spruce::log::print("\t");
				}
			}
			std::cout << std::endl;
		}
	}

	LuaVM::LuaVM(Script& script) : vm(sol::c_call<decltype(&lua::luaPanic), &lua::luaPanic>), script(script) {
		vm.open_libraries(sol::lib::base, sol::lib::package);
		vm.set_function("print", &lua::luaPrint);
	}

	LuaVM::~LuaVM() {
	}

	LuaTable LuaVM::createTable(string name) {
		return vm.create_named_table(name);
	}
}
