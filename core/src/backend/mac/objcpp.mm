#ifdef __APPLE__
#include <backend/mac/objcpp.h>
#include <string>

namespace spruce {
	std::string convertStr(NSString* str) {
		return std::string([str cStringUsingEncoding:NSASCIIStringEncoding]);
	}

	NSString* convertStr(std::string str) {
		return [NSString stringWithCString:str.c_str() encoding:[NSString defaultCStringEncoding]];
	}
}
#endif