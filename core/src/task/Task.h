#pragma once
#include <common.h>
#include <task/TaskPriority.h>
#include <backend/task/TaskData.h>
#include <backend/task/FunctionDataTemplate.h>
#include <backend/task/taskmanager.h>
#include <tuple>

namespace spruce {
	namespace task {
		template <typename T>
		class Task;

		template <typename OUTPUT, typename ... TYPES>
		class Task<OUTPUT(TYPES...)> {
			public:
				task::TaskPriority priority;
				bool& complete;
				OUTPUT& output;
				uint64 id;

				Task(uint64 id, bool& complete, OUTPUT& output);
				Task(const Task& task);
				Task(Task&&) noexcept = default;
				~Task();

				Task& operator=(const Task& task);
				Task& operator=(Task&&) noexcept = default;
		};

		template <typename ... TYPES>
		class Task<void(TYPES...)> {
			public:
				task::TaskPriority priority;
				bool& complete;
				uint64 id;

				Task(uint64 id, bool& complete);
				Task(const Task& task);
				Task(Task&&) noexcept = default;
				~Task();

				Task& operator=(const Task& task);
				Task& operator=(Task&&) noexcept = default;
		};
	}

	using task::Task;

	template <typename RETURN, typename ... TYPES>
	[[nodiscard]] Task<RETURN(TYPES...)> createTask(std::function<RETURN(TYPES...)> function, task::TaskPriority priority, bool concurrent, TYPES ... args) noexcept;

	template <typename ... TYPES>
	[[nodiscard]] Task<void(TYPES...)> createTask(std::function<void(TYPES...)> function, task::TaskPriority priority, bool concurrent, TYPES ... args) noexcept;
}

#include <task/TaskImpl.h>
