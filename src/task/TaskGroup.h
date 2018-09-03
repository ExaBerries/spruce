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

			TaskGroup(const TaskGroup& group) : tasks(group.tasks) {
			}

			~TaskGroup() {
			}

			void addTask(TaskConfig<OUTPUT(TYPES...)> config) {
				tasks.push_back(createTask(config));
			}

			bool complete() const {
				bool complete = true;
				for (Task<OUTPUT(TYPES...)> task : tasks) {
					if (!task.complete) {
						complete = false;
					}
				}
				return complete;
			}
	};
}
