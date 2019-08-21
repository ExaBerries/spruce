#include <graphics/renderer/api/metal/wrapper/MetalFunction.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	constexpr id<MTLFunction> castFunc(void* ptr) {
		return (__bridge id<MTLFunction>) ptr;
	}

	MetalFunction::MetalFunction(void* ptr) : MetalObj(ptr) {
	}

	MetalFunction::~MetalFunction() {
		[castFunc(ptr) release];
	}

}
#endif
