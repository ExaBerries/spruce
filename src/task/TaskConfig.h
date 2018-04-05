#pragma once
#include <common.h>
#include <tuple>

namespace spruce {
	template <typename T>
	class TaskConfig;

	template <typename OUTPUT, typename ... TYPES>
	class TaskConfig {
		public:
			std::function<OUTPUT(TYPES...)> function;
			task::TaskPriority priority;
			bool concurrent;
			std::tuple<TYPES...> args;

			TaskConfig(std::function<OUTPUT(TYPES...)> function, task::TaskPriority priority, bool concurrent, TYPES ... args) : args(args...) {
				this->function = function;
				this->priority = priority;
				this->concurrent = concurrent;
			}

			~TaskConfig() {
			}
	};
}
