#pragma once
#include <common.h>
#include <input/input.h>
#include <app/API.h>
#include <graphics/renderer/api/APIContext.h>

namespace spruce {
	class Window {
		public:
			bool open = true;
			uint32 width = 0;
			uint32 height = 0;
			bool visible = false;
			input::CursorMode cursorMode = input::CursorMode::NORMAL;

			Window() = default;
			Window(const Window&) = delete;
			Window(const Window&&) noexcept = delete;
			virtual ~Window() = default;

			[[nodiscard]] virtual owner<APIContext> initAPI(app::API api) noexcept = 0;
			virtual void setTitle(string title) noexcept = 0;
			virtual void setVisible(bool visible) noexcept = 0;
			virtual void setFullscreen(bool fullscreen) noexcept = 0;
			virtual void close() noexcept = 0;
			virtual void setCursorMode(input::CursorMode mode) noexcept = 0;

			Window& operator=(const Window&) = delete;
			Window& operator=(const Window&&) noexcept = delete;
	};
}
