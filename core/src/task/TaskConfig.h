#pragma once
#include <common.h>
#include <task/TaskPriority.h>
#include <task/Task.h>
#include <backend/task/taskmanager.h>
#include <tuple>

namespace spruce {
	namespace task {
		template <typename T>
		class TaskConfig;

		template <typename OUTPUT, typename ... TYPES>
		class TaskConfig<OUTPUT(TYPES...)> {
			public:
				std::function<OUTPUT(TYPES...)> function;
				task::TaskPriority priority;
				bool concurrent;
				std::tuple<TYPES...> args;

				TaskConfig(std::function<OUTPUT(TYPES...)> function, task::TaskPriority priority, bool concurrent, TYPES ... args);
				TaskConfig(const TaskConfig&) = default;
				TaskConfig(TaskConfig&&) noexcept = default;
				~TaskConfig() = default;

				TaskConfig& operator=(const TaskConfig&) = default;
				TaskConfig& operator=(TaskConfig&&) noexcept = default;
		};
	}

	using task::TaskConfig;

	template <typename RETURN, typename ... TYPES>
	Task<RETURN(TYPES...)> createTask(TaskConfig<RETURN(TYPES...)> config);

	template <typename ... TYPES>
	Task<void(TYPES...)> createTask(TaskConfig<void(TYPES...)> config);
}

#include <task/TaskConfigImpl.h>
