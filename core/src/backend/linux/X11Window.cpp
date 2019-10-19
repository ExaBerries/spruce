#ifdef __linux__
#include <backend/linux/X11Window.h>
#include <backend/linux/opengl/X11OpenGLContext.h>

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

	void X11Window::createXWindow(Visual* visual, uint32 depth) {
		colormap = XCreateColormap(display, root, visual, AllocNone);
		setAttributes.colormap = colormap;
		setAttributes.background_pixmap = None;
		setAttributes.event_mask = KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | ButtonMotionMask | PointerMotionMask | FocusChangeMask | StructureNotifyMask | ExposureMask;
		this->width = 0;
		if (width == 0) {
			width = 1280;
		}
		this->height = 0;
		if (height == 0) {
			height = 720;
		}
		window = XCreateWindow(display, root, 0, 0, width, height, 0, depth, InputOutput, visual, CWColormap | CWEventMask, &setAttributes);
		XStoreName(display, window, "spruce");
		XMapWindow(display, window);
		Atom wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
		XSetWMProtocols(display, window, &wmDeleteMessage, 1);
	}

	[[nodiscard]] owner<APIContext> X11Window::initAPI(app::API api) {
		if (window != 0) {
			XFreeColormap(display, colormap);
			XDestroyWindow(display, window);
		}
		APIContext* context;
		switch (api) {
			case app::OPENGL:
				{
					X11OpenGLContext* glContext = new X11OpenGLContext(display);
					createXWindow(glContext->getVisual(), glContext->getDepth());
					glContext->windowCreated(window);
					context = glContext;
				}
				break;
			case app::VULKAN:
				{
					context = nullptr;
					serr("unsupported api");
				}
				break;
			default:
				{
					context = nullptr;
					serr("unsupported api");
				}
				break;
		}
		return context;
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
