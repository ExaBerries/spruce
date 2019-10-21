#ifdef __APPLE__
#include <backend/mac/objcpp.h>
#include <string>

namespace spruce {
	std::string convertStr(NSString* str) noexcept {
		return std::string([str cStringUsingEncoding:NSASCIIStringEncoding]);
	}

	NSString* convertStr(const std::string& str) noexcept {
		return [NSString stringWithCString:str.c_str() encoding:[NSString defaultCStringEncoding]];
	}
}
#endif
