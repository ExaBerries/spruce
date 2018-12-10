#if defined(__linux__) && defined(__WIN32__)
#include <backend/api/vulkan/VulkanContext.h>

namespace spruce {
	VulkanContext::VulkanContext() {
		instance = 0;
		surface = 0;
		device = 0;
		physicalDevice = 0;
		graphicsQueue = 0;
		presentQueue = 0;
		swapChain = 0;
		swapChainImageFormat = VK_FORMAT_UNDEFINED;
		callback = 0;
	}

	VulkanContext::~VulkanContext() {
	}

	void vulkanAlloc(VulkanContext& context, VkDeviceMemory& mem, VkMemoryRequirements memReq) {
		VkMemoryAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		allocInfo.allocationSize = memReq.size;
		VkMemoryPropertyFlags properties = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
		uint32 typeFilter = memReq.memoryTypeBits;
		VkPhysicalDeviceMemoryProperties memProperties;
		vkGetPhysicalDeviceMemoryProperties(context.physicalDevice, &memProperties);
		uint32 index = 0;
		for (uint32 i = 0; i < memProperties.memoryTypeCount; i++) {
			if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
				index = i;
			}
		}
		allocInfo.memoryTypeIndex = index;
		if (vkAllocateMemory(context.device, &allocInfo, nullptr, &mem) != VK_SUCCESS) {
			serr("failed to allocate memory");
		}
	}
}
#endif
