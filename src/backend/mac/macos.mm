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
}

- (BOOL) applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)_app {
	return YES;
}
@end

namespace spruce {
	namespace os {
		uint16* keyCodes;
		AppDelegate* delegate;

		void init() {
			keyCodes = new uint16[79];
			keyCodes[input::A] = 0x00;
			keyCodes[input::B] = 0x0B;
			keyCodes[input::C] = 0x08;
			keyCodes[input::D] = 0x02;
			keyCodes[input::E] = 0x0E;
			keyCodes[input::F] = 0x03;
			keyCodes[input::G] = 0x05;
			keyCodes[input::H] = 0x04;
			keyCodes[input::I] = 0x22;
			keyCodes[input::J] = 0x26;
			keyCodes[input::K] = 0x28;
			keyCodes[input::L] = 0x25;
			keyCodes[input::M] = 0x2E;
			keyCodes[input::N] = 0x2D;
			keyCodes[input::O] = 0x1F;
			keyCodes[input::P] = 0x23;
			keyCodes[input::Q] = 0x0C;
			keyCodes[input::R] = 0x0F;
			keyCodes[input::S] = 0x01;
			keyCodes[input::T] = 0x11;
			keyCodes[input::U] = 0x20;
			keyCodes[input::V] = 0x09;
			keyCodes[input::W] = 0x0D;
			keyCodes[input::X] = 0x07;
			keyCodes[input::Y] = 0x10;
			keyCodes[input::Z] = 0x06;
			keyCodes[input::ZERO] = 0x1D;
			keyCodes[input::ONE] = 0x12;
			keyCodes[input::TWO] = 0x13;
			keyCodes[input::THREE] = 0x14;
			keyCodes[input::FOUR] = 0x15;
			keyCodes[input::FIVE] = 0x17;
			keyCodes[input::SIX] = 0x18;
			keyCodes[input::SEVEN] = 0x1A;
			keyCodes[input::EIGHT] = 0x1C;
			keyCodes[input::NINE] = 0x19;
			keyCodes[input::ENTER] = 0x24;
			keyCodes[input::ESCAPE] = 0x35;
			keyCodes[input::DELETE] = 0x75;
			keyCodes[input::HOME] = 0x73;
			keyCodes[input::INSERT] = 0x72;
			keyCodes[input::END] = 0x77;
			keyCodes[input::PAGE_UP] = 0x74;
			keyCodes[input::PAGE_DOWN] = 0x79;
			keyCodes[input::TAB] = 0x30;
			keyCodes[input::SPACE] = 0x31;
			keyCodes[input::SEMICOLON] = 0x29;
			keyCodes[input::APOSTROPHE] = 0x27;
			keyCodes[input::SLASH] = 0x2C;
			keyCodes[input::BACKSLASH] = 0x2A;
			keyCodes[input::PERIOD] = 0x2F;
			keyCodes[input::COMMA] = 0x2B;
			keyCodes[input::EQUAL] = 0x18;
			keyCodes[input::MINUS] = 0x1B;
			keyCodes[input::LEFT_BRACKET] = 0x21;
			keyCodes[input::RIGHT_BRACKET] = 0x1E;
			keyCodes[input::LEFT_ARROW] = 0x7B;
			keyCodes[input::RIGHT_ARROW] = 0x7C;
			keyCodes[input::UP_ARROW] = 0x7E;
			keyCodes[input::DOWN_ARROW] = 0x7D;
			keyCodes[input::SHIFT_LEFT] = 0x38;
			keyCodes[input::SHIFT_RIGHT] = 0x3C;
			keyCodes[input::CONTROL_LEFT] = 0x3B;
			keyCodes[input::CONTROL_RIGHT] = 0x3E;
			keyCodes[input::ALT_LEFT] = 0x3A;
			keyCodes[input::ALT_RIGHT] = 0x3D;
			keyCodes[input::SUPER_LEFT] = 0x37;
			keyCodes[input::SUPER_RIGHT] = 0x36;
			keyCodes[input::F1] = 0x7A;
			keyCodes[input::F2] = 0x7B;
			keyCodes[input::F3] = 0x63;
			keyCodes[input::F4] = 0x76;
			keyCodes[input::F5] = 0x60;
			keyCodes[input::F6] = 0x61;
			keyCodes[input::F7] = 0x62;
			keyCodes[input::F8] = 0x64;
			keyCodes[input::F9] = 0x65;
			keyCodes[input::F10] = 0x6D;
			keyCodes[input::F11] = 0x67;
			keyCodes[input::F12] = 0x6F;
			[CocoaApp sharedApplication];
			[NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
			[NSThread detachNewThreadSelector:@selector(doNothing:) toTarget:NSApp withObject:nil];
			delegate = [[AppDelegate alloc] init];
			[NSApp setDelegate:delegate];
		}

		void free() {
			[delegate release];
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
			while (true) {
				NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:[NSDate distantPast] inMode:NSDefaultRunLoopMode dequeue:YES];
				if (event != nullptr) {
					[NSApp sendEvent:event];
				}
				break;
			}
		}

		uint16 codeFor(input::Key key) {
			return keyCodes[key];
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
