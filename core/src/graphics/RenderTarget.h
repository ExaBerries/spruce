#pragma once
#include <common.h>

namespace spruce {
	class RenderTarget {
		public:
			uint16 width;
			uint16 height;

			RenderTarget(uint16 width, uint16 height);
			RenderTarget(const RenderTarget& renderTarget) = delete;
			virtual ~RenderTarget();
	};
}
