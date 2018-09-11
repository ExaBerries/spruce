#include <backend/api/vulkan/VulkanContext.h>

namespace spruce {
	void vulkanAlloc(VkDeviceMemory& mem, VkMemoryRequirements memReq) {
		VkMemoryAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		allocInfo.allocationSize = memReq.size;
		VkMemoryPropertyFlags properties = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
		uint32 typeFilter = memReq.memoryTypeBits;
		VkPhysicalDeviceMemoryProperties memProperties;
		vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);
		uint32 index = 0;
		for (uint32 i = 0; i < memProperties.memoryTypeCount; i++) {
			if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
				index = i;
			}
		}
		allocInfo.memoryTypeIndex = index;
		if (vkAllocateMemory(device, &allocInfo, nullptr, &mem) != VK_SUCCESS) {
			serr("failed to allocate memory");
		}
	}
}
