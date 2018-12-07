#include <backend/api/vulkan/VulkanTexture.h>

namespace spruce {
	VulkanTexture::VulkanTexture(PixelFormat format, buffer<uint8> data, uint16& width, uint16& height) : Texture(format, data, width, height) {
	}

	VulkanTexture::~VulkanTexture() {
	}

	void VulkanTexture::toVRAM() {

	}

	void VulkanTexture::freeVRAM() {

	}
}
