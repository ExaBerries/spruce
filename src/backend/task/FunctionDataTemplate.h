#pragma once
#include <backend/task/FunctionData.h>
#include <common.h>
#include <util/function.h>
#include <tuple>

namespace spruce {
	namespace task {
		template <typename OUTPUT, typename ... ARGS>
		class FunctionDataTemplate : public FunctionData {
			public:
				OUTPUT* output;
				std::function<OUTPUT(ARGS...)> function;
				std::tuple<ARGS...> args;

				FunctionDataTemplate(OUTPUT* output, std::function<OUTPUT(ARGS...)> function, std::tuple<ARGS...> args) : args(args) {
					this->output = output;
					this->function = function;
				}

				~FunctionDataTemplate() {
				}

				void execute() {
					(*output) = util::execute(function, args);
				}
		};

		template <typename ... ARGS>
		class FunctionDataTemplate<void, ARGS...> : public FunctionData {
			public:
				bool* output;
				std::function<void(ARGS...)> function;
				std::tuple<ARGS...> args;

				FunctionDataTemplate(bool* output, std::function<void(ARGS...)> function, std::tuple<ARGS...> args) : args(args) {
					this->output = output;
					this->function = function;
				}

				~FunctionDataTemplate() {
				}

				void execute() {
					util::execute(function, args);
				}
		};
	}
}
