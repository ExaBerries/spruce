#pragma once
#ifdef __linux__
#include <common.h>
#include <backend/ApplicationBackend.h>
#include <backend/linux/X11Window.h>
#include <X11/X.h>
#include <X11/Xlib.h>

namespace spruce {
	class X11AppBackend : public ApplicationBackend {
		public:
			Display* display;
			std::vector<X11Window*> x11Windows;

			X11AppBackend();
			X11AppBackend(const X11AppBackend&) = delete;
			X11AppBackend(X11AppBackend&&) noexcept = delete;
			~X11AppBackend() final;

			[[nodiscard]] owner<Window> createWindow() noexcept final;
			void update() noexcept final;

			X11AppBackend& operator=(const X11AppBackend&) = delete;
			X11AppBackend& operator=(X11AppBackend&&) noexcept = delete;
	};
}
#endif
