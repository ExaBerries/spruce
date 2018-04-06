#pragma once
#include <common.h>
#include <task/Task.h>
#include <task/TaskConfig.h>

namespace spruce {
	template <typename T>
	class TaskGroup;

	template <typename OUTPUT, typename ... TYPES>
	class TaskGroup<OUTPUT(TYPES...)> {
		public:
			std::vector<Task<OUTPUT(TYPES...)>> tasks;

			TaskGroup() {
			}

			~TaskGroup() {
			}

			void addTask(TaskConfig<OUTPUT(TYPES...)> config) {
				tasks.push_back(createTask(config));
			}

			void createTasks() {

			}

			bool complete() {
				bool complete = true;
				for (Task<OUTPUT(TYPES...)> task : tasks) {
					if (!task.complete) {
						complete = false;
					}
				}
				return complete;
			}

			void waitUntilComple() {
				while (!complete()) {
				}
			}
	};
}
