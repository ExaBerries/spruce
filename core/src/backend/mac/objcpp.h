#pragma once
#ifdef __APPLE__
#include <common.h>

#ifdef __OBJC__
	#include <Foundation/NSString.h>
	#ifdef __cplusplus
		#include <string>
		namespace spruce {
			std::string convertStr(NSString* str);
			NSString* convertStr(const std::string& str);
		}
	#endif
#endif
#endif
