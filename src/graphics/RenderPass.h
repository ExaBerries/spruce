#pragma once
#include <common.h>
#include <graphics/RenderTarget.h>

namespace spruce {
	namespace graphics {
		class RenderPass;
		void render(RenderPass* renderPass);

		class RenderPass {
			public:
				RenderTarget* target;

				RenderPass();
				virtual ~RenderPass();
			protected:
				virtual void render() = 0;

				friend void render(RenderPass* renderPass);
		};
	}
}
