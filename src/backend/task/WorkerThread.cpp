#include <backend/task/WorkerThread.h>
#include <backend/task/taskmanager.h>

namespace spruce {
	namespace task {
		WorkerThread::WorkerThread() {
			taskBackend = nullptr;
			running = true;
			thread = std::thread(run, this);
		}

		WorkerThread::~WorkerThread() {
			if (thread.joinable()) {
				join();
			}
		}

		void WorkerThread::join() {
			running = false;
			thread.join();
		}

		void WorkerThread::run(WorkerThread* thread) {
			thread->running = true;
			while (thread->running) {
				if (thread->taskBackend == nullptr) {
					thread->taskBackend = getNextTask(false);
				}
				if (thread->taskBackend != nullptr) {
					if (thread->taskBackend->functionData != nullptr) {
						thread->taskBackend->functionData->execute();
						thread->taskBackend->complete = true;
						delete thread->taskBackend;
						thread->taskBackend = nullptr;
					} else {
						serr("invalid task, functionData == nullptr");
						thread->taskBackend = nullptr;
					}
				}
			}
		}
	}
}
