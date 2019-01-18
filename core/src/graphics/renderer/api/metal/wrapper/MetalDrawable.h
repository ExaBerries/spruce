#pragma once
#ifdef __APPLE__
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>

namespace spruce {
	class MetalDrawable : public MetalObj {
		public:
			MetalDrawable(void* ptr);
			~MetalDrawable();
	};
}
#endif
