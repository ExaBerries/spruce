#pragma once
#include <common.h>

namespace spruce {
	class Window {
		public:
			uint16 width;
			uint16 height;
			bool visible;

			Window();
			virtual ~Window();

			virtual void setTitle(string title) = 0;
			virtual void setVisible(bool visible) = 0;
			virtual void setFullscreen(bool fullscreen) = 0;
			virtual void close() = 0;
	};
}
