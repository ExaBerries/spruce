#pragma once
#include <pipeline/Pipeline.h>
#include <pipeline/Frame.h>

namespace spruce {
	class SimplePipeline : public Pipeline {
		public:
			Frame* frame;

			SimplePipeline();
			virtual ~SimplePipeline();

			void execute();
			void clearCommands();
			CommandBuffer& getCommandBuffer();
	};
}
