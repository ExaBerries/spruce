#pragma once
#include <pipeline/Pipeline.h>
#include <pipeline/Frame.h>

namespace spruce {
	class EncodeExecutePipeline: public Pipeline {
		public:
			Frame* encodeFrame;
			Frame* executeFrame;

			EncodeExecutePipeline();
			virtual ~EncodeExecutePipeline();

			void execute();
			void clearCommands();
			CommandBuffer& getCommandBuffer();
	};
}
