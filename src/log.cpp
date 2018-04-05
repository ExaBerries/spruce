#include <log.h>
#include <app.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	namespace log {
		std::mutex logMutex;

		void logAPIError() {
			if (app::debug) {
				std::lock_guard<std::mutex> guard(logMutex);
				std::cout << "apiError=" << app::api->getError() << std::endl;
			}
		}

		void logAPIError(std::string name) {
			if (app::debug) {
				std::lock_guard<std::mutex> guard(logMutex);
				std::cout << name << "=" << app::api->getError() << std::endl;
			}
		}
	}
}
