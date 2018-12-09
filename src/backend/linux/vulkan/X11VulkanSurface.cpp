#if defined(__linux__) && defined(__WIN32__)
#include <backend/linux/vulkan/X11VulkanSurface.h>
#include <backend/api/vulkan/VulkanContext.h>
#include <backend/api/vulkan/VulkanRenderTarget.h>

namespace spruce {
	X11VulkanSurface::X11VulkanSurface(Display* display, VulkanContext* context) {
		this->display = display;
		this->context = context;
		visual = DefaultVisual(display, DefaultScreen(display));
		depth = DefaultDepth(display, DefaultScreen(display));
		target = new VulkanRenderTarget(10, 10);
	}

	X11VulkanSurface::~X11VulkanSurface() {
		if (context->surface != VK_NULL_HANDLE) {
			vkDestroySurfaceKHR(context->instance, context->surface, nullptr);
		}
	}

	Visual* X11VulkanSurface::getVisual() {
		return visual;
	}

	uint32 X11VulkanSurface::getDepth() {
		return depth;
	}

	void X11VulkanSurface::windowCreated(XWindow window) {
	}

	void X11VulkanSurface::contextCreated(XWindow window) {
		VkXlibSurfaceCreateInfoKHR surfaceCreateInfo = {};
		surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
		surfaceCreateInfo.window = window;
		surfaceCreateInfo.dpy = display;
		surfaceCreateInfo.pNext = nullptr;
		if (vkCreateXlibSurfaceKHR(context->instance, &surfaceCreateInfo, nullptr, &context->surface) != VK_SUCCESS) {
			serr("could not create xlib surface");
		}
	}

	void X11VulkanSurface::addExtensions() {
		context->vulkanInstanceExtensions.push_back(VK_KHR_XLIB_SURFACE_EXTENSION_NAME);
	}

	void X11VulkanSurface::renderStart() {
	}

	void X11VulkanSurface::renderEnd() {
	}
}
#endif
