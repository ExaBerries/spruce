#pragma once
#include <common.h>
#include <task/TaskPriority.h>
#include <backend/task/TaskData.h>

namespace spruce {
	namespace task {
		void incrementRef(uint64 id);
		void deincrementRef(uint64 id);
	}

	template <typename T>
	class Task;

	template <typename OUTPUT, typename ... TYPES>
	class Task<OUTPUT(TYPES...)> {
		public:
			task::TaskPriority priority;
			bool& complete;
			OUTPUT& output;
			uint64 id;

			Task(uint64 id, bool& complete, OUTPUT& output) : complete(complete), output(output) {
				this->id = id;
				priority = task::LOW;
				task::incrementRef(id);
			}

			Task(const Task& task) : complete(task.complete), output(task.output) {
				this->id = task.id;
				this->priority = task.priority;
				task::incrementRef(id);
			}

			~Task() {
				task::deincrementRef(id);
			}
	};

	template < typename ... TYPES>
	class Task<void(TYPES...)> {
		public:
			task::TaskPriority priority;
			bool& complete;
			uint64 id;

			Task(uint64 id, bool& complete) : complete(complete) {
				this->id = id;
				priority = task::LOW;
				task::incrementRef(id);
			}

			Task(const Task& task) : complete(task.complete) {
				this->id = task.id;
				this->priority = task.priority;
				task::incrementRef(id);
			}

			~Task() {
				task::deincrementRef(id);
			}
	};
}
