#pragma once
#include <common.h>
#include <graphics/CommandBuffer.h>

namespace spruce {
	class Pipeline {
		public:
			Pipeline();
			virtual ~Pipeline();

			virtual void execute() = 0;
			virtual void clearCommands() = 0;
			virtual CommandBuffer& getCommandBuffer() = 0;
	};
}
