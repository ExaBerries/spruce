#include <graphics/renderer/api/metal/wrapper/MetalTextureUsage.h>
#ifdef __APPLE__

namespace spruce {
	MetalTextureUsage operator|(MetalTextureUsage a, MetalTextureUsage b) {
		return (MetalTextureUsage)((int32)a | (int32)b);
	}
}
#endif
