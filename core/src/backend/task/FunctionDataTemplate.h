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
				uint64 taskId;

				FunctionDataTemplate(OUTPUT* output, const std::function<OUTPUT(ARGS...)>& function, const std::tuple<ARGS...>& args, uint64 taskId);
				FunctionDataTemplate(const FunctionDataTemplate&) = delete;
				FunctionDataTemplate(FunctionDataTemplate&&) noexcept = delete;
				~FunctionDataTemplate() override = default;

				void execute() override;

				FunctionDataTemplate& operator=(const FunctionDataTemplate&) = delete;
				FunctionDataTemplate& operator=(FunctionDataTemplate&&) noexcept = delete;
		};

		template <typename ... ARGS>
		class FunctionDataTemplate<void, ARGS...> : public FunctionData {
			public:
				std::function<void(ARGS...)> function;
				std::tuple<ARGS...> args;
				uint64 taskId;

				FunctionDataTemplate([[maybe_unused]] bool* output, const std::function<void(ARGS...)>& function, const std::tuple<ARGS...>& args, uint64 taskId);
				FunctionDataTemplate(const FunctionDataTemplate&) = delete;
				FunctionDataTemplate(FunctionDataTemplate&&) noexcept = delete;
				~FunctionDataTemplate() override = default;

				void execute() override;

				FunctionDataTemplate& operator=(const FunctionDataTemplate&) = delete;
				FunctionDataTemplate& operator=(FunctionDataTemplate&&) noexcept = delete;
		};
	}
}

#include <backend/task/FunctionDataTemplateImpl.h>
