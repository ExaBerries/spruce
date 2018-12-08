#pragma once
#include <common.h>
#include <app/Application.h>
#include <graphics/CommandBuffer.h>

namespace spruce {
	class FramePipeline {
		public:
			FramePipeline();
			virtual ~FramePipeline();

			virtual void execute(Application& app) = 0;
			virtual void clearCommands() = 0;
			virtual CommandBuffer& getCommandBuffer() = 0;
	};
}
