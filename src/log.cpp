#include <log.h>
#include <app.h>
#include <backend/api/RenderAPI.h>
#include <iostream>
#include <stdarg.h>
#include <stdlib.h>

namespace spruce {
	void logAPIError() {
		std::cout << "apiError=" << app::api->getError() << std::endl;
	}

	void logAPIError(std::string name) {
		std:: cout << name << "=" << app::api->getError() << std::endl;
	}
}
