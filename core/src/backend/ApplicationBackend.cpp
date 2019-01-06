#include <backend/ApplicationBackend.h>

namespace spruce {
	ApplicationBackend::ApplicationBackend() {
	}

	ApplicationBackend::~ApplicationBackend() {
	}

	bool ApplicationBackend::supportsAPI(app::API api) {
		return (std::find(supportedAPIs.begin(), supportedAPIs.end(), api) != supportedAPIs.end());
	}
}
