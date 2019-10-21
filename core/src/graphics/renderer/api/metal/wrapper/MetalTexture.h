#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>

namespace spruce {
	class MetalTexture : public MetalObj {
		public:
			MetalTexture(void* ptr);
			MetalTexture(const MetalTexture&) = delete;
			MetalTexture(MetalTexture&&) noexcept = delete;
			~MetalTexture() override;

			[[nodiscard]] vec2i getSize();

			MetalTexture& operator=(const MetalTexture&) = delete;
			MetalTexture& operator=(MetalTexture&&) noexcept = delete;
	};
}
#endif
