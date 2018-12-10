#pragma once
#include <common.h>
#include <task/Task.h>
#include <task/TaskConfig.h>
#include <task/TaskGroup.h>
#include <backend/task/taskmanager.h>
#include <task/semaphore.h>
#include <mutex>
#include <atomic>
#include <thread>

namespace spruce {
	template <typename OUTPUT, typename ... ARGS>
	void waitFor(Task<OUTPUT(ARGS...)>& task) {
		while (!task.complete) {
			task::executeMainTask();
		}
	}

	template <typename OUTPUT, typename ... ARGS>
	void waitFor(TaskGroup<OUTPUT(ARGS...)>& taskGroup) {
		while (!taskGroup.complete()) {
			task::executeMainTask();
		}
	}

	void waitForMainTasks();
	void waitForGraphicsTasks(bool concurrent);
}
