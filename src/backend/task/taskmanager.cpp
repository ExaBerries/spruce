#include <backend/task/taskmanager.h>
#include <backend/task/WorkerThread.h>
#include <system/system.h>
#include <app.h>

namespace spruce {
	namespace task {
		std::stack<TaskBackend*> mainTasks;
		std::stack<TaskBackend*> concurrentTasks;
		std::map<uint64, TaskData*> data;
		std::map<uint64, uint16> references;
		std::vector<WorkerThread> threads;
		uint64 taskId;
		std::mutex taskMutex;
		std::mutex dataMutex;
		std::mutex refMutex;

		void init() {
			threads = std::vector<WorkerThread>(sys::getCPUThreadCount() - 1);
			if (app::debug) {
				slog(sys::getCPUThreadCount() - 1, " threads");
			}
		}

		void free() {
			for (uint16 i = 0; i < threads.size(); i++) {
				threads[i].join();
			}
			while (mainTasks.size() > 0) {
				delete mainTasks.top();
				mainTasks.pop();
			}
			while (concurrentTasks.size() > 0) {
				delete concurrentTasks.top();
				concurrentTasks.pop();
			}
			for (auto taskData : data) {
				delete taskData.second;
			}
		}

		void addTask(uint64 id, TaskData* taskData, TaskBackend* taskBackend) {
			std::lock_guard<std::mutex> taskGuard(task::taskMutex);
			std::lock_guard<std::mutex> dataGuard(task::dataMutex);
			data[id] = taskData;
			if (taskBackend->concurrent) {
				concurrentTasks.push(taskBackend);
			} else {
				mainTasks.push(taskBackend);
			}
		}

		TaskBackend* getConcurrentTask() {
			if (concurrentTasks.size() > 0) {
				TaskBackend* task = concurrentTasks.top();
				concurrentTasks.pop();
				return task;
			}
			return nullptr;
		}

		TaskBackend* getMainTask() {
			if (mainTasks.size() > 0) {
				TaskBackend* task = mainTasks.top();
				mainTasks.pop();
				return task;
			}
			return nullptr;
		}

		TaskBackend* getNextTask(bool main) {
			std::lock_guard<std::mutex> taskGuard(taskMutex);
			TaskBackend* nextTask = nullptr;
			if (main) {
				nextTask = getMainTask();
				if (nextTask == nullptr) {
					nextTask = getConcurrentTask();
				}
			} else {
				nextTask = getConcurrentTask();
			}
			return nextTask;
		}

		void incrementRef(uint64 taskId) {
			std::lock_guard<std::mutex> dataGuard(task::refMutex);
			references[taskId]++;
		}

		void deincrementRef(uint64 taskId) {
			std::lock_guard<std::mutex> dataGuard(task::refMutex);
			references[taskId]--;
			if (references[taskId] <= 0) {
				std::lock_guard<std::mutex> dataGuard(task::dataMutex);
				delete data[taskId];
				data.erase(taskId);
				references.erase(taskId);
			}
		}
	}
}
