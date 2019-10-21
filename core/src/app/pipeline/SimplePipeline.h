#pragma once
#include <common.h>
#include <app/pipeline/Frame.h>
#include <app/pipeline/FramePipeline.h>

namespace spruce {
	class SimplePipeline : public FramePipeline {
		public:
			stackown<Frame> frame;

			SimplePipeline() = default;
			SimplePipeline(const SimplePipeline&) = default;
			SimplePipeline(SimplePipeline&&) noexcept = default;
			~SimplePipeline() override = default;

			void execute(float delta, Application& app, graphics::RendererAbstractor* renderer, ApplicationBackend& appBackend) noexcept override;

			SimplePipeline& operator=(const SimplePipeline&) = default;
			SimplePipeline& operator=(SimplePipeline&&) noexcept = default;
	};
}
