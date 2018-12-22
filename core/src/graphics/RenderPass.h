#pragma once
#include <common.h>
#include <graphics/RenderTarget.h>

namespace spruce {
	namespace graphics {
		class RenderPass {
			public:
				RenderTarget* target;

				RenderPass();
				RenderPass(const RenderPass& renderPass) = delete;
				virtual ~RenderPass();
			protected:
				virtual void render() = 0;

				friend void render(RenderPass* renderPass);
		};
	}
}
