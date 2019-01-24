#pragma once

namespace spruce {
	namespace task {
		template <typename OUTPUT, typename ... TYPES>
		TaskGroup<OUTPUT(TYPES...)>::TaskGroup(const TaskGroup& group) : tasks(group.tasks) {
		}

		template <typename OUTPUT, typename ... TYPES>
		void TaskGroup<OUTPUT(TYPES...)>::addTask(TaskConfig<OUTPUT(TYPES...)> config) {
			tasks.push_back(createTask(config));
		}

		template <typename OUTPUT, typename ... TYPES>
		bool TaskGroup<OUTPUT(TYPES...)>::complete() const {
			bool complete = true;
			for (Task<OUTPUT(TYPES...)> task : tasks) {
				if (!task.complete) {
					complete = false;
				}
			}
			return complete;
		}
	}
}
