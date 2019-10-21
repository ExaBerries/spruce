#pragma once

namespace spruce {
	namespace task {
		template <typename OUTPUT, typename ... ARGS>
		FunctionDataTemplate<OUTPUT, ARGS...>::FunctionDataTemplate(OUTPUT* output, const std::function<OUTPUT(ARGS...)>& function, const std::tuple<ARGS...>& args, uint64 taskId) : function(function), args(args), taskId(taskId) {
			this->output = output;
		}

		template <typename OUTPUT, typename ... ARGS>
		void FunctionDataTemplate<OUTPUT, ARGS...>::execute() noexcept {
			(*output) = util::execute(function, args);
		}

		template <typename ... ARGS>
		FunctionDataTemplate<void, ARGS...>::FunctionDataTemplate([[maybe_unused]] bool* output, const std::function<void(ARGS...)>& function, const std::tuple<ARGS...>& args, uint64 taskId) : function(function), args(args), taskId(taskId) {
		}

		template <typename ... ARGS>
		void FunctionDataTemplate<void, ARGS...>::execute() noexcept {
			util::execute(function, args);
		}
	}
}
