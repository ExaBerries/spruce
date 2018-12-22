#pragma once
#include <common.h>
#include <app/pipeline/Frame.h>
#include <app/pipeline/FramePipeline.h>

namespace spruce {
	class SimplePipeline : public FramePipeline {
		public:
			Frame* frame;

			SimplePipeline();
			virtual ~SimplePipeline();

			void execute(Application& app);
			void clearCommands();
			CommandBuffer& getCommandBuffer();
	};
}
