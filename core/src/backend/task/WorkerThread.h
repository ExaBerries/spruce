#pragma once
#include <backend/task/TaskBackend.h>
#include <graphics/CommandBuffer.h>
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
				~WorkerThread();

				void join();

				static void run(WorkerThread* thread);
			};
	}
}