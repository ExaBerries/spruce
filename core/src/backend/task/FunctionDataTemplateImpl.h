#pragma once

namespace spruce {
	namespace task {
		template <typename OUTPUT, typename ... ARGS>
		FunctionDataTemplate<OUTPUT, ARGS...>::FunctionDataTemplate(OUTPUT* output, std::function<OUTPUT(ARGS...)> function, std::tuple<ARGS...> args, uint64 taskId) : args(args) {
			this->output = output;
			this->function = function;
			this->taskId = taskId;
		}

		template <typename OUTPUT, typename ... ARGS>
		void FunctionDataTemplate<OUTPUT, ARGS...>::execute() {
			(*output) = util::execute(function, args);
		}

		template <typename ... ARGS>
		FunctionDataTemplate<void, ARGS...>::FunctionDataTemplate([[maybe_unused]] bool* output, std::function<void(ARGS...)> function, std::tuple<ARGS...> args, uint64 taskId) : args(args) {
			this->function = function;
			this->taskId = taskId;
		}

		template <typename ... ARGS>
		void FunctionDataTemplate<void, ARGS...>::execute() {
			util::execute(function, args);
		}
	}
}
