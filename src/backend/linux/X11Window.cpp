

#ifdef __linux__
#include <backend/linux/opengl/X11OpenGLSurface.h>
#include <backend/linux/vulkan/X11VulkanSurface.h>
#include <backend/linux/X11Window.h>
#include <graphics/graphics.h>

namespace spruce {
	X11Window::X11Window(Display* display) {
		this->display = display;
		root = DefaultRootWindow(display);
		window = 0;
		colormap = 0;
	}

	X11Window::~X11Window() {
		XFreeColormap(display, colormap);
		XDestroyWindow(display, window);
	}

	void X11Window::createXWindow(Visual* visual, float depth) {
		colormap = XCreateColormap(display, root, visual, AllocNone);
		setAttributes.colormap = colormap;
		setAttributes.background_pixmap = None;
		setAttributes.event_mask = KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | ButtonMotionMask | PointerMotionMask | FocusChangeMask | StructureNotifyMask | ExposureMask;
		this->width = graphics::width;
		if (width == 0) {
			width = 1280;
			graphics::width = width;
		}
		this->height = graphics::height;
		if (height == 0) {
			height = 720;
			graphics::height = height;
		}
		window = XCreateWindow(display, root, 0, 0, width, height, 0, depth, InputOutput, visual, CWColormap | CWEventMask, &setAttributes);
		XStoreName(display, window, "spruce");
		XMapWindow(display, window);
	}

	void X11Window::initOpenGL() {
		if (surface != nullptr) {
			delete surface;
			surface = nullptr;
			XFreeColormap(display, colormap);
			XDestroyWindow(display, window);
		}
		surface = new X11OpenGLSurface(display);
		createXWindow(((X11RenderSurface*)surface)->getVisual(), ((X11RenderSurface*)surface)->getDepth());
		((X11RenderSurface*)surface)->windowCreated(window);
	}

	void X11Window::initVulkan() {
		if (surface != nullptr) {
			delete surface;
			surface = nullptr;
			XFreeColormap(display, colormap);
			XDestroyWindow(display, window);
		}
		surface = new X11VulkanSurface(display);
		createXWindow(((X11RenderSurface*)surface)->getVisual(), ((X11RenderSurface*)surface)->getDepth());
		((X11RenderSurface*)surface)->windowCreated(window);
	}

	void X11Window::apiInitalized() {
		((X11RenderSurface*)surface)->apiInitalized(window);
	}

	void X11Window::setTitle(string title) {
		XStoreName(display, window, title.c_str());
	}

	void X11Window::setVisible(bool visible) {
	}

	void X11Window::setFullscreen(bool fullscreen) {
	}

	void X11Window::close() {
		open = false;
	}

	void X11Window::setCursorMode(input::CursorMode mode) {
	}
}
#endif
