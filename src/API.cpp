#include <API.h>

namespace spruce {
	namespace app {
		std::ostream& operator<<(std::ostream& stream, const API& api) {
			#define CASE(X) case X:stream << #X;break;
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
				case METAL2:
					stream << "Metal2";
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
