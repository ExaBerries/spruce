#pragma once
#include <common.h>
#include <graphics/RenderPass.h>

namespace spruce {
	namespace graphics {
		class GraphicsPipeline {
			public:
				std::vector<RenderPass*> renderPasses;

				GraphicsPipeline();
				virtual ~GraphicsPipeline();
		};
	}
}
