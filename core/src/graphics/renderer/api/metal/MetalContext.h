#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/APIContext.h>
#include <graphics/renderer/api/metal/wrapper/MetalDevice.h>
#include <graphics/renderer/api/metal/wrapper/MetalDrawable.h>

namespace spruce {
	class MetalContext : public APIContext {
		public:
			void* mtlView;
			MetalDevice device;

			MetalContext(void* mtlView);
			MetalContext(const MetalContext&) = delete;
			MetalContext(MetalContext&&) noexcept = delete;
			~MetalContext() override = default;

			[[nodiscard]] owner<MetalDrawable> getDrawable();
			void setDrawableSize(vec2i size);
			void setVSync(bool vsync);

			MetalContext& operator=(const MetalContext&) = delete;
			MetalContext& operator=(MetalContext&&) noexcept = delete;
	};
}
#endif
