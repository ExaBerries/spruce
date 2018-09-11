#pragma once
#include <backend/linux/APIHook.h>

namespace spruce {
class VulkanHook : public APIHook {
	public:
		Display* display;
		Visual* visual;
		uint32 depth;

		VulkanHook(Display* display);
		virtual ~VulkanHook();

		Visual* getVisual();
		uint32 getDepth();
		void windowCreated(XWindow window);
		void apiInitalized(XWindow window);
};
}
