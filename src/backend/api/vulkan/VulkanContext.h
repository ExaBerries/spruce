#pragma once
#if defined(__linux__) && defined(__WIN32__)
#include <common.h>
#ifdef __linux__
#define VK_USE_PLATFORM_XLIB_KHR
#endif
#include <vulkan/vulkan.h>

namespace spruce {
	class VulkanContext {
		public:
			VkInstance instance;
			VkDevice device;
			VkPhysicalDevice physicalDevice;
			VkQueue graphicsQueue;
			VkQueue presentQueue;
			VkSwapchainKHR swapChain;
			std::vector<VkImage> swapChainImages;
			VkFormat swapChainImageFormat;
			VkExtent2D swapChainExtent;
			std::vector<VkImageView> swapChainImageViews;

			VkDebugReportCallbackEXT callback;
			std::vector<string> vulkanInstanceExtensions;
			std::vector<string> vulkanDeviceExtensions;
			std::vector<const char*> vulkanValidationLayers;
			VkSurfaceKHR surface;

			VulkanContext();
			~VulkanContext();
	};

	void vulkanAlloc(VulkanContext& context, VkDeviceMemory& mem, VkMemoryRequirements memReq);
}
#endif
