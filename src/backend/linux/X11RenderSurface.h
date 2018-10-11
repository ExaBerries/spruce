#pragma once
#ifdef __linux__
#include <common.h>
#include <backend/RenderSurface.h>
#include <X11/X.h>
#include <X11/Xlib.h>

typedef Window XWindow;

namespace spruce {
	class X11RenderSurface : public RenderSurface {
		public:
			X11RenderSurface();
			virtual ~X11RenderSurface();

			virtual Visual* getVisual() = 0;
			virtual uint32 getDepth() = 0;
			virtual void windowCreated(XWindow window) = 0;
			virtual void apiInitalized(XWindow window) = 0;
	};
}
#endif
