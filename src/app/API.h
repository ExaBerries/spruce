#pragma once
#include <iostream>

namespace spruce {
	namespace app {
		enum API {
			NONE, OPENGL, VULKAN, METAL, DX11, DX12
		};

		std::ostream& operator<<(std::ostream& stream, const API& api);
	}
}
