#pragma once
#include <app/pipeline/Frame.h>
#include <app/pipeline/FramePipeline.h>

namespace spruce {
	class EncodeExecutePipeline: public FramePipeline {
		public:
			Frame* encodeFrame;
			Frame* executeFrame;

			EncodeExecutePipeline();
			virtual ~EncodeExecutePipeline();

			void execute(Application& app);
			void clearCommands();
			CommandBuffer& getCommandBuffer();
	};
}
