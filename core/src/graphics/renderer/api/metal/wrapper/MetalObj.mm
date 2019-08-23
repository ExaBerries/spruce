#include <graphics/renderer/api/metal/wrapper/MetalObj.h>
#ifdef __APPLE__

namespace spruce {
	MetalObj::MetalObj(void* ptr) : ptr(ptr) {
	}
}
#endif
