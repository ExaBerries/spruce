#include <backend/api/vulkan/Vulkan.h>
#include <backend/api/vulkan/VulkanContext.h>
#include <backend/api/vulkan/VulkanShader.h>
#include <backend/api/vulkan/VulkanMesh.h>
#include <backend/api/vulkan/VulkanTexture.h>
#include <backend/api/vulkan/VulkanRenderTarget.h>
#include <graphics/graphics.h>
#include <io/image.h>

namespace spruce {
	Vulkan::Vulkan(Window* window) : RenderAPI(window, vec3f(2, 2, 2)) {
	}

	Vulkan::~Vulkan() {
		auto destroyCallbackFunc = (PFN_vkDestroyDebugReportCallbackEXT) vkGetInstanceProcAddr(context.instance, "vkDestroyDebugReportCallbackEXT");
		if (destroyCallbackFunc != nullptr) {
			destroyCallbackFunc(context.instance, context.callback, nullptr);
		}
		vkDestroyInstance(context.instance, nullptr);
	}

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType, uint64_t obj, size_t location, int32_t code, const char* layerPrefix, const char* msg, void* userData) {
		serr("validation layer: ", msg);
		return VK_FALSE;
	};

	void Vulkan::addDefaultExtensions() {
		context.vulkanInstanceExtensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
		context.vulkanInstanceExtensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
		context.vulkanDeviceExtensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
		context.vulkanValidationLayers.push_back("VK_LAYER_LUNARG_standard_validation");
	}

	void Vulkan::createInstance() {
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "spruce";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "spruce";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;
		VkInstanceCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;
		const char* vulkanInstanceExtensionsArray[context.vulkanInstanceExtensions.size()];
		for (uint16 i = 0; i < context.vulkanInstanceExtensions.size(); i++) {
			vulkanInstanceExtensionsArray[i] = context.vulkanInstanceExtensions[i].c_str();
			slog(context.vulkanInstanceExtensions[i]);
		}
		createInfo.enabledExtensionCount = context.vulkanInstanceExtensions.size();
		createInfo.ppEnabledExtensionNames = vulkanInstanceExtensionsArray;
		const char* vulkanValidationLayersArray[context.vulkanValidationLayers.size()];
		for (uint16 i = 0; i < context.vulkanValidationLayers.size(); i++) {
			vulkanValidationLayersArray[i] = context.vulkanValidationLayers[i];
			slog(context.vulkanValidationLayers[i]);
		}
		createInfo.enabledLayerCount = context.vulkanValidationLayers.size();
		createInfo.ppEnabledLayerNames = vulkanValidationLayersArray;
		VkResult result = vkCreateInstance(&createInfo, nullptr, &context.instance);
		if (result != VK_SUCCESS) {
			if (result == VK_ERROR_LAYER_NOT_PRESENT) {
				serr("layer not present");
			}
			if (result == VK_ERROR_EXTENSION_NOT_PRESENT) {
				serr("extension not present");
			}
			serr("could not create vulkan instance");
			exit(EXIT_FAILURE);
		}
		VkDebugReportCallbackCreateInfoEXT callbackCreateInfo = {};
		callbackCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
		callbackCreateInfo.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
		callbackCreateInfo.pfnCallback = debugCallback;
		auto callbackCreateFunc = (PFN_vkCreateDebugReportCallbackEXT) vkGetInstanceProcAddr(context.instance, "vkCreateDebugReportCallbackEXT");
		if (callbackCreateFunc != nullptr) {
			callbackCreateFunc(context.instance, &callbackCreateInfo, nullptr, &context.callback);
		} else {
			serr("could not make debug callback");
		}
	}

	void Vulkan::createPhysicalDevice() {
		uint32 deviceCount = 0;
		vkEnumeratePhysicalDevices(context.instance, &deviceCount, nullptr);
		if (deviceCount == 0) {
			serr("no devices found");
		}
		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(context.instance, &deviceCount, devices.data());
		slog(deviceCount, " physical device(s)");
		for (const auto& device : devices) {
			VkPhysicalDeviceProperties deviceProperties;
			vkGetPhysicalDeviceProperties(device, &deviceProperties);
			VkPhysicalDeviceFeatures deviceFeatures;
			vkGetPhysicalDeviceFeatures(device, &deviceFeatures);
			slog(deviceProperties.deviceName);
			slog(deviceProperties.deviceType);
			bool discrete = true;
			if (deviceProperties.deviceType == VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU) {
				discrete = false;
			} else if (deviceProperties.deviceType == VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
				discrete = true;
			}
			slog(discrete);
			slog(deviceProperties.driverVersion);
			slog(deviceProperties.limits.maxFramebufferWidth, " ", deviceProperties.limits.maxFramebufferHeight);
			slog(deviceProperties.limits.framebufferColorSampleCounts, " ", deviceProperties.limits.framebufferColorSampleCounts);
			slog(deviceProperties.limits.maxClipDistances);
			slog(deviceProperties.limits.maxComputeWorkGroupSize[0]);
			slog(deviceProperties.limits.maxImageDimension2D);
			slog(deviceFeatures.geometryShader);
			uint32_t queueFamilyCount = 0;
			vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);
			std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
			vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

			//if (isDeviceSuitable(device)) {
				context.physicalDevice = device;//spruce::physicalDevice = device;
				break;
			//}
		}
		if (context.physicalDevice == VK_NULL_HANDLE) {
			serr("failed to find a suitable GPU!");
		}
	}

	void Vulkan::createVirtualDevice() {
		int32 graphicsFamily = -1;
		int32 presentFamily = -1;
		uint32 queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(context.physicalDevice, &queueFamilyCount, nullptr);
		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(context.physicalDevice, &queueFamilyCount, queueFamilies.data());
		int i = 0;
		for (const auto& queueFamily : queueFamilies) {
			if (queueFamily.queueCount > 0 && (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)) {
				graphicsFamily = i;
			}
			VkBool32 presentSupport = false;
			vkGetPhysicalDeviceSurfaceSupportKHR(context.physicalDevice, i, context.surface, &presentSupport);
			if (queueFamily.queueCount > 0 && presentSupport) {
				presentFamily = i;
			}
			if (graphicsFamily >= 0 && presentFamily >= 0) {
				break;
			}
			i++;
		}

		slog(graphicsFamily, " ", presentFamily);

		std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;

		VkDeviceQueueCreateInfo graphicsQueueCreateInfo = {};
		graphicsQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		graphicsQueueCreateInfo.queueFamilyIndex = graphicsFamily;
		graphicsQueueCreateInfo.queueCount = 1;
		float graphicsQueuePriority = 1.0f;
		graphicsQueueCreateInfo.pQueuePriorities = &graphicsQueuePriority;
		queueCreateInfos.push_back(graphicsQueueCreateInfo);

		if (presentFamily != -1 && presentFamily != graphicsFamily) {
			VkDeviceQueueCreateInfo presentQueueCreateInfo = {};
			presentQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			presentQueueCreateInfo.queueFamilyIndex = presentFamily;
			presentQueueCreateInfo.queueCount = 1;
			float presentQueuePriority = 1.0f;
			presentQueueCreateInfo.pQueuePriorities = &presentQueuePriority;
			queueCreateInfos.push_back(presentQueueCreateInfo);
		}

		VkPhysicalDeviceFeatures deviceFeatures = {};
		VkDeviceCreateInfo deviceCreateInfo = {};
		deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		deviceCreateInfo.pQueueCreateInfos = queueCreateInfos.data();
		deviceCreateInfo.queueCreateInfoCount = queueCreateInfos.size();
		deviceCreateInfo.pEnabledFeatures = &deviceFeatures;
		const char* vulkanDeviceExtensionsArray[context.vulkanDeviceExtensions.size()];
		for (uint16 i = 0; i < context.vulkanDeviceExtensions.size(); i++) {
			vulkanDeviceExtensionsArray[i] = context.vulkanDeviceExtensions[i].c_str();
		}
		deviceCreateInfo.enabledExtensionCount = context.vulkanDeviceExtensions.size();
		deviceCreateInfo.ppEnabledExtensionNames = vulkanDeviceExtensionsArray;
		deviceCreateInfo.enabledLayerCount = context.vulkanValidationLayers.size();
		const char* vulkanValidationLayersArray[context.vulkanValidationLayers.size()];
		for (uint16 i = 0; i < context.vulkanValidationLayers.size(); i++) {
			vulkanValidationLayersArray[i] = context.vulkanValidationLayers[i];
		}
		deviceCreateInfo.ppEnabledLayerNames = vulkanValidationLayersArray;
		if (vkCreateDevice(context.physicalDevice, &deviceCreateInfo, nullptr, &context.device) != VK_SUCCESS) {
			serr("failed to create logical device!");
		}
		vkGetDeviceQueue(context.device, graphicsFamily, 0, &context.graphicsQueue);
		vkGetDeviceQueue(context.device, presentFamily, 0, &context.presentQueue);
	}

	void Vulkan::createSwapChain() {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
		vkGetPhysicalDeviceSurfaceCapabilitiesKHR(context.physicalDevice, context.surface, &capabilities);
		uint32_t formatCount;
		vkGetPhysicalDeviceSurfaceFormatsKHR(context.physicalDevice, context.surface, &formatCount, nullptr);
		if (formatCount != 0) {
			formats.resize(formatCount);
			vkGetPhysicalDeviceSurfaceFormatsKHR(context.physicalDevice, context.surface, &formatCount, formats.data());
		}
		uint32 presentModeCount;
		vkGetPhysicalDeviceSurfacePresentModesKHR(context.physicalDevice, context.surface, &presentModeCount, nullptr);
		if (presentModeCount != 0) {
			presentModes.resize(presentModeCount);
			vkGetPhysicalDeviceSurfacePresentModesKHR(context.physicalDevice, context.surface, &presentModeCount, presentModes.data());
		}
		VkSurfaceFormatKHR surfaceFormat = formats[0];
		if (formats.size() == 1 && formats[0].format == VK_FORMAT_UNDEFINED) {
			surfaceFormat = {VK_FORMAT_B8G8R8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR};
		}
		slog(formats.size(), " formats");
		for (const auto& availableFormat : formats) {
			if (availableFormat.format == VK_FORMAT_B8G8R8A8_UNORM && availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
				surfaceFormat = availableFormat;
				break;
			}
		}
		slog("format");
		VkPresentModeKHR presentMode = VK_PRESENT_MODE_FIFO_KHR;
		for (const auto& availablePresentMode : presentModes) {
			if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR) {
				break;
			} else if (availablePresentMode == VK_PRESENT_MODE_IMMEDIATE_KHR) {
				presentMode = availablePresentMode;
			}
		}
		slog("present mode");
		VkExtent2D extent;
		if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max() && false) {
			extent = capabilities.currentExtent;
		} else {
			VkExtent2D actualExtent = {graphics::width, graphics::height};
			actualExtent.width = std::max(capabilities.minImageExtent.width, std::min(capabilities.maxImageExtent.width, actualExtent.width));
			actualExtent.height = std::max(capabilities.minImageExtent.height, std::min(capabilities.maxImageExtent.height, actualExtent.height));
			extent = actualExtent;
		}
		uint32 imageCount = capabilities.minImageCount + 1;
		if (capabilities.maxImageCount > 0 && imageCount > capabilities.maxImageCount) {
			imageCount = capabilities.maxImageCount;
		}
		VkSwapchainCreateInfoKHR swapChainCreateInfo = {};
		swapChainCreateInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		swapChainCreateInfo.surface = context.surface;
		swapChainCreateInfo.minImageCount = imageCount;
		swapChainCreateInfo.imageFormat = surfaceFormat.format;
		swapChainCreateInfo.imageColorSpace = surfaceFormat.colorSpace;
		swapChainCreateInfo.imageExtent = extent;
		swapChainCreateInfo.imageArrayLayers = 1;
		swapChainCreateInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
		int32 graphicsFamily = -1;
		int32 presentFamily = -1;
		uint32 queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(context.physicalDevice, &queueFamilyCount, nullptr);
		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(context.physicalDevice, &queueFamilyCount, queueFamilies.data());
		int i = 0;
		for (const auto& queueFamily : queueFamilies) {
			if (queueFamily.queueCount > 0 && (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)) {
				graphicsFamily = i;
			}
			VkBool32 presentSupport = false;
			vkGetPhysicalDeviceSurfaceSupportKHR(context.physicalDevice, i, context.surface, &presentSupport);
			if (queueFamily.queueCount > 0 && presentSupport) {
				presentFamily = i;
			}
			if (graphicsFamily >= 0 && presentFamily >= 0) {
				break;
			}
			i++;
		}
		uint32 queueFamilyIndices[] = {(uint32) graphicsFamily, (uint32) presentFamily};
		if (graphicsFamily != presentFamily) {
			swapChainCreateInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
			swapChainCreateInfo.queueFamilyIndexCount = 2;
			swapChainCreateInfo.pQueueFamilyIndices = queueFamilyIndices;
		} else {
			swapChainCreateInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
		}
		swapChainCreateInfo.preTransform = capabilities.currentTransform;
		swapChainCreateInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
		swapChainCreateInfo.presentMode = presentMode;
		swapChainCreateInfo.clipped = VK_TRUE;
		swapChainCreateInfo.oldSwapchain = VK_NULL_HANDLE;
		if (vkCreateSwapchainKHR(context.device, &swapChainCreateInfo, nullptr, &context.swapChain) != VK_SUCCESS) {
			serr("failed to create swap chain!");
		}
		vkGetSwapchainImagesKHR(context.device, context.swapChain, &imageCount, nullptr);
		context.swapChainImages.resize(imageCount);
		vkGetSwapchainImagesKHR(context.device, context.swapChain, &imageCount, context.swapChainImages.data());
		context.swapChainImageFormat = surfaceFormat.format;
		context.swapChainExtent = extent;
	}

	void Vulkan::createImageViews() {
		context.swapChainImageViews.resize(context.swapChainImages.size());
		for (uint32 i = 0; i < context.swapChainImages.size(); i++) {
			VkImageViewCreateInfo imageViewCreateInfo = {};
			imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
			imageViewCreateInfo.image = context.swapChainImages[i];
			imageViewCreateInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
			imageViewCreateInfo.format = context.swapChainImageFormat;
			imageViewCreateInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
			imageViewCreateInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
			imageViewCreateInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
			imageViewCreateInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
			imageViewCreateInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
			imageViewCreateInfo.subresourceRange.baseMipLevel = 0;
			imageViewCreateInfo.subresourceRange.levelCount = 1;
			imageViewCreateInfo.subresourceRange.baseArrayLayer = 0;
			imageViewCreateInfo.subresourceRange.layerCount = 1;
			if (vkCreateImageView(context.device, &imageViewCreateInfo, nullptr, &context.swapChainImageViews[i]) != VK_SUCCESS) {
				serr("failed to create image views!");
			}
		}
	}

	void Vulkan::createPipeline() {
	}

	void Vulkan::createContext() {
		addDefaultExtensions();
		createInstance();
	}

	void Vulkan::surfaceCreated() {
		createPhysicalDevice();
		slog("physical device created");
		createVirtualDevice();
		slog("virtual device created");
		createSwapChain();
		slog("swap chain created");
		createImageViews();
		slog("image views created");
		createPipeline();
		slog("pipeline created");
	}

	void Vulkan::renderStart() {
	}

	void Vulkan::renderEnd() {
	}

	string Vulkan::getError() {
		return "";
	}

	Mesh* Vulkan::createMesh(buffer<float> vertices, buffer<uint16> indices) {
		return new VulkanMesh(vertices, indices, context);
	}

	Shader* Vulkan::createShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes) {
		return new VulkanShader(vertData, fragData, attributes, context);
	}

	Shader* Vulkan::createShader(string& vertSource, string& fragSource, buffer<VertexAttribute> attributes) {
		return nullptr;
	}

	Texture* Vulkan::createTexture(const FileHandle& path) {
		uint16 width = 0;
		uint16 height = 0;
		uint16 bitsPerPixel = 0;
		buffer<uint8> data = io::loadImage(path, width, height, bitsPerPixel);
		return new VulkanTexture(Texture::RGBA, data, width, height);
	}

	Texture* Vulkan::createTexture(Texture::PixelFormat format, buffer<uint8> data, uint16 width, uint16 height) {
		return new VulkanTexture(format, nullptr, width, height);
	}

	RenderTarget* Vulkan::createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height) {
		return new VulkanRenderTarget(width, height);
	}

	void Vulkan::render(Mesh* mesh, Shader* shader, graphics::Primitive primitive) {
	}

	void Vulkan::render(buffer<float> vertices, buffer<uint16> indices, Shader* shader, graphics::Primitive primitive) {
	}

	void Vulkan::changeTarget(RenderTarget* target) {
	}

	void Vulkan::bind(Mesh* mesh) {
	}

	void Vulkan::bind(Texture* texture) {
	}

	void Vulkan::unbind(Texture* texture) {
	}

	void Vulkan::bind(Shader* shader) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const int32& value) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const vec2i& vector) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const float& value) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const vec2f& vector) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const vec3f& vector) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const mat4f& matrix) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const quaternion& quaternion) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const color& color) {
	}

	void Vulkan::setUniform(Shader* shader, string name, Texture* texture) {
	}

	void Vulkan::setUniform(Shader* shader, string name, graphics::RenderPass* renderPass) {
	}

	string Vulkan::getGPUVendor() {
		return "";
	}

	uint16 Vulkan::getAPIVersionMajor() {
		return 0;
	}

	uint16 Vulkan::getAPIVersionMinor() {
		return 0;
	}

	string Vulkan::getAPIRendererName() {
		return "";
	}

	void Vulkan::setPerspective(mat4f& matrix, float& near, float& far, float& fov, float& aspectRatio) {
	}

	void Vulkan::setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) {
	}
}
