#pragma once
#ifdef __APPLE__
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
			CocoaAppBackend(const CocoaAppBackend&) = default;
			CocoaAppBackend(CocoaAppBackend&&) noexcept = default;
			~CocoaAppBackend() override;

			owner<Window> createWindow() override;
			void update() override;

			CocoaAppBackend& operator=(const CocoaAppBackend&) = default;
			CocoaAppBackend& operator=(CocoaAppBackend&&) noexcept = default;
	};
}
#endif
