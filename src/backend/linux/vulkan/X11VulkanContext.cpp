#include <backend/api/vulkan/VulkanContext.h>

namespace spruce {
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
}
