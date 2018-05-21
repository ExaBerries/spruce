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
				CommandBuffer commandBuffer;

				WorkerThread();
				WorkerThread(const WorkerThread& thread) = delete;
				virtual ~WorkerThread();

				void join();

				static void run(WorkerThread* thread);
			};
	}
}
