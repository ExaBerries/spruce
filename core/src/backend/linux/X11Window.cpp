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

	void X11Window::createXWindow(Visual* visual, uint32 depth) noexcept {
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
		window = XCreateWindow(display, root, 0, 0, width, height, 0, static_cast<int>(depth), InputOutput, visual, CWColormap | CWEventMask, &setAttributes);
		XStoreName(display, window, "spruce");
		XMapWindow(display, window);
		Atom wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
		XSetWMProtocols(display, window, &wmDeleteMessage, 1);
	}

	[[nodiscard]] owner<APIContext> X11Window::initAPI(app::API api) noexcept {
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

	void X11Window::setTitle(string title) noexcept {
		XStoreName(display, window, title.c_str());
	}

	void X11Window::setVisible(bool visible) noexcept {
	}

	void X11Window::setFullscreen(bool fullscreen) noexcept {
		struct {
			unsigned long flags;
			unsigned long functions;
			unsigned long decorations;
			long inputMode;
			unsigned long status;
		} hints;
		Atom property;
		hints.flags = 2;
		if (fullscreen) {
			hints.decorations = 0;
		} else {
			hints.decorations = 1;
		}
		property = XInternAtom(display,"_MOTIF_WM_HINTS",True);
		XChangeProperty(display, window, property, property, 32, PropModeReplace, reinterpret_cast<unsigned char *>(&hints),5);
		if (fullscreen) {
			Screen* screen = XDefaultScreenOfDisplay(display);
			XMoveResizeWindow(display, window, 0, 0, XWidthOfScreen(screen), XHeightOfScreen(screen));
			XMapRaised(display, window);
			XGrabPointer(display, window, True, 0, GrabModeAsync, GrabModeAsync, window, 0L, CurrentTime);
			XGrabKeyboard(display, window, False, GrabModeAsync, GrabModeAsync, CurrentTime);
		} else {
			XMoveResizeWindow(display, window, 0, 0, this->width, this->height);
			XUngrabPointer(display, CurrentTime);
			XUngrabKeyboard(display, CurrentTime);
		}
	}

	void X11Window::close() noexcept {
		open = false;
	}

	void X11Window::setCursorMode(input::CursorMode mode) noexcept {
	}
}
#endif
