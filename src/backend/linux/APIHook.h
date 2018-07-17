#pragma once
#ifdef __LINUX__
#include <common.h>
#include <X11/X.h>
#include <X11/Xlib.h>

typedef Window XWindow;

namespace spruce {
	class APIHook {
		public:
			APIHook();
			virtual ~APIHook();

			virtual Visual* getVisual() = 0;
			virtual uint32 getDepth() = 0;
			virtual void windowCreated(XWindow window) = 0;
	};
}
#endif
