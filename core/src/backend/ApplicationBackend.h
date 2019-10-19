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

			bool supportsAPI(app::API api);

			[[nodiscard]] virtual owner<Window> createWindow() = 0;
			virtual void update() = 0;

			ApplicationBackend& operator=(const ApplicationBackend&) = default;
			ApplicationBackend& operator=(ApplicationBackend&&) noexcept = default;
	};
}
