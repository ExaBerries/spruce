#pragma once
#include <common.h>

#ifdef __OBJC__
	#include <Foundation/NSString.h>
	#ifdef __cplusplus
		#include <string>
		namespace spruce {
			std::string convertStr(NSString* str);
			NSString* convertStr(std::string str);
		}
	#endif
#endif
