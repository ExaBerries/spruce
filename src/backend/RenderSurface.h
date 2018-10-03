#pragma once
#include <common.h>
#include <graphics/RenderTarget.h>

namespace spruce {
	class RenderSurface {
		public:
			RenderTarget* target;

			RenderSurface();
			virtual ~RenderSurface();

			virtual void renderStart() = 0;
			virtual void renderEnd() = 0;
	};
}
