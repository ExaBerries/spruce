#pragma once
#include <common.h>
#include <script/Script.h>
#define SOL_NO_EXCEPTIONS 1
#define SOL_CHECK_ARGUMENTS 1
#include <sol.hpp>

using LuaTable = sol::table;

namespace spruce {
	class LuaVM {
		public:
			sol::state vm;
			Script& script;

			LuaVM(Script& script);
			virtual ~LuaVM();

			void execute() {
				vm.script(script.code);
			}

			template <typename T>
			T execute(string fnname) {
				vm.script(script.code);
				return vm[fnname]();
			}

			void execute(string fnname) {
				vm.script(script.code);
				vm[fnname]();
			}

			template <typename T>
			void registerFunction(string name, std::function<T> function) {
				vm.set_function(name, function);
			}

			template <typename T>
			T get(string name) {
				return vm.get<T>(name);
			}

			template <typename T>
			T get(string name, T defaultVal) {
				return vm.get_or<T>(name, defaultVal);
			}

			template <typename T>
			void set(string name, T value) {
				vm.set(name, value);
			}

			LuaTable createTable(string name);
	};
}
