#include <backend/ApplicationBackend.h>

namespace spruce {
	bool ApplicationBackend::supportsAPI(app::API api) {
		return (std::find(supportedAPIs.begin(), supportedAPIs.end(), api) != supportedAPIs.end());
	}
}
