#pragma once
#include <common.h>
#include <app/pipeline/Frame.h>
#include <app/pipeline/FramePipeline.h>

namespace spruce {
	class SimplePipeline : public FramePipeline {
		public:
			Frame* frame;

			SimplePipeline();
			~SimplePipeline() override;

			void execute(float delta, Application& app, graphics::RendererAbstractor* renderer, ApplicationBackend& appBackend) override;
	};
}
