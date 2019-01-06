#pragma once
#include <common.h>
#include <app/API.h>
#include <backend/Window.h>

namespace spruce {
	class ApplicationBackend {
		public:
			buffer<app::API> supportedAPIs;

			ApplicationBackend();
			virtual ~ApplicationBackend();

			bool supportsAPI(app::API api);

			virtual Window* createWindow() = 0;
			virtual void update() = 0;
	};
}
