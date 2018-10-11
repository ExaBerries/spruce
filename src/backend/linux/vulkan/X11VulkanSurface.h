#pragma once
#ifdef __linux__
#include <backend/linux/X11RenderSurface.h>

namespace spruce {
	class X11VulkanSurface : public X11RenderSurface {
		public:
			Display* display;
			Visual* visual;
			uint32 depth;

			X11VulkanSurface(Display* display);
			virtual ~X11VulkanSurface();

			Visual* getVisual();
			uint32 getDepth();
			void windowCreated(XWindow window);
			void apiInitalized(XWindow window);
			void renderStart();
			void renderEnd();
	};
}
#endif
