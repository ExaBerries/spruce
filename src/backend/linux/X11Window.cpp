#ifdef __LINUX__
#include <backend/linux/opengl/OpenGLHook.h>
#include <backend/linux/X11Window.h>
#include <graphics/graphics.h>

namespace spruce {
	X11Window::X11Window(Display* display) {
		this->display = display;
		root = DefaultRootWindow(display);
		layer = nullptr;
		window = 0;
		colormap = 0;
	}

	X11Window::~X11Window() {
		if (layer != nullptr) {
			delete layer;
		}
		XFreeColormap(display, colormap);
		XDestroyWindow(display, window);
	}

	void X11Window::createXWindow(Visual* visual, float depth) {
		colormap = XCreateColormap(display, root, visual, AllocNone);
		setAttributes.colormap = colormap;
		setAttributes.background_pixmap = None;
		setAttributes.event_mask = ExposureMask | KeyPressMask;
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

	void X11Window::initForAPI(app::API api) {
		if (api == app::OPENGL) {
			layer = new OpenGLHook(display);
		} else if (api == app::VULKAN) {

		}
		createXWindow(layer->getVisual(), layer->getDepth());
		layer->windowCreated(window);
	}

	void X11Window::setTitle(string title) {
		XStoreName(display, window, title.c_str());
	}

	void X11Window::setVisible(bool visible) {
	}

	void X11Window::setFullscreen(bool fullscreen) {
	}

	void X11Window::close() {
	}

	void X11Window::setCursorMode(input::CursorMode mode) {
	}
}
#endif
