#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>

namespace spruce {
	class MetalTexture : public MetalObj {
		public:
			MetalTexture(void* ptr);
			~MetalTexture();
	};
}
#endif
