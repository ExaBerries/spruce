#pragma once
#include <common.h>
#include <backend/ApplicationBackend.h>
#include <backend/mac/objcpp.h>
#include <Cocoa/Cocoa.h>

@interface CocoaApp : NSApplication {
}
- (void) doNothing:(id) object;
- (void) quit;
@end

@interface AppDelegate : NSObject <NSApplicationDelegate>
@end

namespace spruce {
	class CocoaAppBackend : public ApplicationBackend {
		public:
			AppDelegate* delegate;

			CocoaAppBackend();
			~CocoaAppBackend();

			Window* createWindow();
			void update();
	};
}
