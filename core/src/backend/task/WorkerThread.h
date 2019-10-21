#pragma once
#include <backend/task/TaskBackend.h>
#include <thread>

namespace spruce {
	namespace task {
		class WorkerThread {
			public:
				std::thread thread;
				TaskBackend* taskBackend;
				bool running;

				WorkerThread();
				WorkerThread(const WorkerThread& thread) = delete;
				WorkerThread(WorkerThread&&) noexcept = delete;
				~WorkerThread();

				void join() noexcept;

				static void run(WorkerThread* thread) noexcept;

				WorkerThread& operator=(const WorkerThread&) = delete;
				WorkerThread& operator=(WorkerThread&&) noexcept = delete;
			};
	}
}
