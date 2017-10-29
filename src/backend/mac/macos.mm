#include <backend/os.h>
#include <system/system.h>
#include <input/input.h>
#include <sys/sysctl.h>
#include <backend/mac/CocoaWindow.h>

@interface CocoaApp : NSApplication {
}
- (void) doNothing:(id) object;
@end

@implementation CocoaApp
- (void) doNothing:(id) object {
}
@end

@interface AppDelegate : NSObject <NSApplicationDelegate>
@end

@implementation AppDelegate
- (void) applicationDidFinishLaunching:(NSNotification*)notification {
	[NSApp stop:nil];
	NSEvent* event = [NSEvent otherEventWithType:NSEventTypeApplicationDefined location:NSMakePoint(0, 0) modifierFlags:0 timestamp:0  windowNumber:0 context:nil subtype:0 data1:0 data2:0];
	[NSApp postEvent:event atStart:YES];
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)_app {
	return YES;
}
@end

namespace spruce {
	namespace os {
		AppDelegate* delegate;

		void init() {
			[CocoaApp sharedApplication];
			[NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
			[NSThread detachNewThreadSelector:@selector(doNothing:) toTarget:NSApp withObject:nil];
			delegate = [[AppDelegate alloc] init];
			[NSApp setDelegate:delegate];
		}

		void free() {
			[delegate dealloc];
			delegate = nullptr;
		}

		Window* createWindow(app::API api) {
			return new CocoaWindow(api, 1920, 1080);
		}

		bool supportsAPI(app::API api) {
			if (api == app::OPENGL) {
				return true;
			} else if (api == app::METAL) {
				return true;
			} else if (api == app::METAL2) {
				return true;
			}
			return false;
		}

		void updateStart() {
		}

		void updateEnd() {
			NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate distantPast] inMode:NSDefaultRunLoopMode dequeue:YES];
			if (event != nullptr) {
				[NSApp sendEvent:event];
			}
		}
	}

	namespace system {
		string getCPUName() {
			size_t length = 128;
			char buffer[length];
			sysctlbyname("machdep.cpu.brand_string", &buffer, &length, NULL, 0);
			return string(buffer);
		}

		uint16 getCPUCoreCount() {
			size_t size = sizeof(uint16);
			uint16 coreCount = 0;
			sysctlbyname("machdep.cpu.core_count", &coreCount, &size, NULL, 0);
			return coreCount;
		}
	}
}
