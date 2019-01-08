#pragma once
#ifdef __linux__
#include <common.h>
#include <backend/ApplicationBackend.h>
#include <X11/X.h>
#include <X11/Xlib.h>

namespace spruce {
	class X11AppBackend : public ApplicationBackend {
		public:
			Display* display;
			
			X11AppBackend();
			~X11AppBackend();

			Window* createWindow();
			void update();
	};
}
#endif