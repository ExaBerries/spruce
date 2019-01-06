#pragma once
#ifdef __linux__
#include <backend/linux/X11RenderSurface.h>
#include <backend/api/vulkan/VulkanContext.h>

namespace spruce {
	class X11VulkanSurface : public X11RenderSurface {
		public:
			Display* display;
			Visual* visual;
			uint32 depth;
			VulkanContext* context;

			X11VulkanSurface(Display* display, VulkanContext* context);
			virtual ~X11VulkanSurface();

			Visual* getVisual();
			uint32 getDepth();
			void windowCreated(XWindow window);
			void addExtensions();
			void contextCreated(XWindow window);
			void renderStart();
			void renderEnd();
	};
}
#endif
