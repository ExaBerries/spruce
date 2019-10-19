#include <graphics/renderer/api/metal/wrapper/MetalLibrary.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>
#include <backend/mac/objcpp.h>

namespace spruce {
	constexpr id<MTLLibrary> castLibrary(void* ptr) {
		return (__bridge id<MTLLibrary>) ptr;
	}

	MetalLibrary::MetalLibrary(void* ptr) : MetalObj(ptr) {
	}

	MetalLibrary::~MetalLibrary() {
		[castLibrary(ptr) release];
	}

	[[nodiscard]] owner<MetalFunction> MetalLibrary::newFunctionWithName(const string& name) {
		return new MetalFunction([castLibrary(ptr) newFunctionWithName:convertStr(name)]);
	}
}
#endif
