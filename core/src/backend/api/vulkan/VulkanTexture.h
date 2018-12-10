#pragma once
#include <graphics/Texture.h>
#include <backend/api/vulkan/VulkanContext.h>

namespace spruce {
	class VulkanTexture : public Texture {
		public:
			VulkanTexture(PixelFormat format, buffer<uint8> data, uint16& width, uint16& height);
			VulkanTexture(const VulkanTexture& texture) = delete;
			virtual ~VulkanTexture();

			void toVRAM();
			void freeVRAM();
	};
}
