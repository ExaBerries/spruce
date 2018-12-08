#include <app/API.h>

namespace spruce {
	namespace app {
		std::ostream& operator<<(std::ostream& stream, const API& api) {
			switch (api) {
				case OPENGL:
					stream << "OpenGL";
					break;
				case VULKAN:
					stream << "Vulkan";
					break;
				case METAL:
					stream << "Metal";
					break;
				case DX11:
					stream << "DirectX 11";
					break;
				case DX12:
					stream << "DirectX 12";
					break;
				default:
					stream << "unknown api " << api;
					break;
			}
			return stream;
		}
	}
}
