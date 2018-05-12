#pragma once
#include <iostream>

namespace spruce {
	namespace app {
		enum API {
			OPENGL, VULKAN, METAL, METAL2, DX11, DX12
		};

		std::ostream& operator<<(std::ostream& stream, const API& api);
	}
}
