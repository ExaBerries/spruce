#pragma once
#include <common.h>
#include <app/pipeline/Frame.h>
#include <app/pipeline/FramePipeline.h>

namespace spruce {
	class EncodeExecutePipeline: public FramePipeline {
		public:
			Frame* encodeFrame;
			Frame* executeFrame;

			EncodeExecutePipeline();
			~EncodeExecutePipeline() override;

			void execute(float delta, Application& app, graphics::RendererAbstractor* renderer, ApplicationBackend& appBackend) override;
	};
}
