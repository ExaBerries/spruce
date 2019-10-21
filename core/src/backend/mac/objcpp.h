#pragma once
#ifdef __APPLE__
#include <common.h>

#ifdef __OBJC__
	#include <Foundation/NSString.h>
	#ifdef __cplusplus
		#include <string>
		namespace spruce {
			std::string convertStr(NSString* str) noexcept;
			NSString* convertStr(const std::string& str) noexcept;
		}
	#endif
#endif
#endif
