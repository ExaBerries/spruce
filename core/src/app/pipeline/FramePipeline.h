#pragma once
#include <common.h>
#include <app/ApplicationFwd.h>
#include <graphics/renderer/RendererAbstractor.h>
#include <backend/ApplicationBackend.h>

namespace spruce {
	class FramePipeline {
		public:
			FramePipeline() = default;
			virtual ~FramePipeline() = default;

			virtual void execute(float delta, Application& app, graphics::RendererAbstractor* renderer, ApplicationBackend& appBackend) = 0;
	};
}
