#pragma once
#include <common.h>
#include <graphics/CommandBuffer.h>
#include <thread>

namespace spruce {
	class Frame {
		public:
			CommandBuffer mainCommandBuffer;
			std::map<std::thread::id, CommandBuffer> commandBuffers;

			Frame();
			Frame(const Frame& frame);
			virtual ~Frame();

			CommandBuffer& getCommandBuffer();
			buffer<CommandBuffer*> getCommandBuffers();

			Frame& operator=(Frame frame);
	};
}
