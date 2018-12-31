#include <backend/os.h>

namespace spruce {
	namespace os {
		std::vector<app::API> supportedAPIs;

		bool supportsAPI(app::API api) {
			return (std::find(supportedAPIs.begin(), supportedAPIs.end(), api) != supportedAPIs.end());
		}
	}
}
