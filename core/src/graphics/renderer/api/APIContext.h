#pragma once
#include <common.h>

namespace spruce {
	class APIContext {
		public:
			APIContext() = default;
			APIContext(const APIContext&) = default;
			APIContext(APIContext&&) = default;
			virtual ~APIContext() = default;

			APIContext& operator=(const APIContext&) = default;
			APIContext& operator=(APIContext&&) = default;
	};
}
