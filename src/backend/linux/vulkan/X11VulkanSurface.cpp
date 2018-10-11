#include <backend/api/vulkan/VulkanContext.h>
#include <backend/linux/vulkan/X11VulkanSurface.h>

namespace spruce {
	X11VulkanSurface::X11VulkanSurface(Display* display) {
		this->display = display;
		visual = DefaultVisual(display, DefaultScreen(display));
		depth = DefaultDepth(display, DefaultScreen(display));
	}

	X11VulkanSurface::~X11VulkanSurface() {
		if (surface != VK_NULL_HANDLE) {
			vkDestroySurfaceKHR(instance, surface, nullptr);
		}
	}

	Visual* X11VulkanSurface::getVisual() {
		return visual;
	}

	uint32 X11VulkanSurface::getDepth() {
		return depth;
	}

	void X11VulkanSurface::windowCreated(XWindow window) {
		vulkanInstanceExtensions.clear();
		vulkanInstanceExtensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
		vulkanInstanceExtensions.push_back(VK_KHR_XLIB_SURFACE_EXTENSION_NAME);
		vulkanInstanceExtensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
		vulkanDeviceExtensions.clear();
		vulkanDeviceExtensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
		vulkanValidationLayers.clear();
		vulkanValidationLayers.push_back("VK_LAYER_LUNARG_standard_validation");
	}

	void X11VulkanSurface::apiInitalized(XWindow window) {
		VkXlibSurfaceCreateInfoKHR surfaceCreateInfo = {};
		surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
		surfaceCreateInfo.window = window;
		surfaceCreateInfo.dpy = display;
		surfaceCreateInfo.pNext = nullptr;
		if (vkCreateXlibSurfaceKHR(instance, &surfaceCreateInfo, nullptr, &surface) != VK_SUCCESS) {
			serr("could not create xlib surface");
		}
	}

	void X11VulkanSurface::renderStart() {
	}

	void X11VulkanSurface::renderEnd() {
	}
}
