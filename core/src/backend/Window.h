#pragma once
#include <common.h>
#include <input/input.h>
#include <app/API.h>
#include <graphics/renderer/api/APIContext.h>

namespace spruce {
	class Window {
		public:
			bool open;
			uint32 width;
			uint32 height;
			bool visible;
			input::CursorMode cursorMode;

			Window();
			Window(const Window&) = delete;
			Window(const Window&&) noexcept = delete;
			virtual ~Window() = default;

			virtual owner<APIContext> initAPI(app::API api) = 0;
			virtual void setTitle(string title) = 0;
			virtual void setVisible(bool visible) = 0;
			virtual void setFullscreen(bool fullscreen) = 0;
			virtual void close() = 0;
			virtual void setCursorMode(input::CursorMode mode) = 0;

			Window& operator=(const Window&) = delete;
			Window& operator=(const Window&&) noexcept = delete;
	};
}
