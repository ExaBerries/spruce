#pragma once
#include <common.h>
#include <app/API.h>
#include <backend/Window.h>

namespace spruce {
	class ApplicationBackend {
		public:
			buffer<app::API> supportedAPIs;

			ApplicationBackend() = default;
			ApplicationBackend(const ApplicationBackend&) = default;
			ApplicationBackend(ApplicationBackend&&) noexcept = default;
			virtual ~ApplicationBackend() = default;

			[[nodiscard]] bool supportsAPI(app::API api) noexcept;

			[[nodiscard]] virtual owner<Window> createWindow() noexcept = 0;
			virtual void update() noexcept = 0;

			ApplicationBackend& operator=(const ApplicationBackend&) = default;
			ApplicationBackend& operator=(ApplicationBackend&&) noexcept = default;
	};
}
