#include <backend/api/vulkan/VulkanRenderTarget.h>

namespace spruce {
	VulkanRenderTarget::VulkanRenderTarget(uint16 width, uint16 height) : RenderTarget(width, height) {
	}

	VulkanRenderTarget::~VulkanRenderTarget() {
	}
}
