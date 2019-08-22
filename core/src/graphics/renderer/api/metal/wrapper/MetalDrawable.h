#pragma once
#ifdef __APPLE__
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>
#include <graphics/renderer/api/metal/wrapper/MetalTexture.h>

namespace spruce {
	class MetalDrawable : public MetalObj {
		public:
			owner<MetalTexture> texture;

			MetalDrawable(void* ptr);
			MetalDrawable(const MetalDrawable&) = delete;
			MetalDrawable(MetalDrawable&&) noexcept = delete;
			~MetalDrawable();

			MetalDrawable& operator=(const MetalDrawable&) = delete;
			MetalDrawable& operator=(MetalDrawable&&) noexcept = delete;
	};
}
#endif
