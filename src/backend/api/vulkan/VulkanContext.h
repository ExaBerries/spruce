#pragma once
#include <common.h>
#ifdef __linux__
#define VK_USE_PLATFORM_XLIB_KHR
#endif
#include <vulkan/vulkan.h>

namespace spruce {
	extern VkInstance instance;
	extern VkDevice device;
	extern VkPhysicalDevice physicalDevice;
	extern VkQueue graphicsQueue;
	extern VkQueue presentQueue;
	extern VkSwapchainKHR swapChain;
	extern std::vector<VkImage> swapChainImages;
	extern VkFormat swapChainImageFormat;
	extern VkExtent2D swapChainExtent;
	extern std::vector<VkImageView> swapChainImageViews;

	extern VkDebugReportCallbackEXT callback;
	extern std::vector<string> vulkanInstanceExtensions;
	extern std::vector<string> vulkanDeviceExtensions;
	extern std::vector<const char*> vulkanValidationLayers;
	extern VkSurfaceKHR surface;

	void vulkanAlloc(VkDeviceMemory& mem, VkMemoryRequirements memReq);
}
