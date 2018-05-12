#include <backend/os.h>
#include <system/system.h>
#include <input/input.h>
#include <app.h>
#include <backend/mac/CocoaWindow.h>
#include <backend/mac/objcpp.h>
#include <sys/sysctl.h>
#include <sys/stat.h>
#include <system/system.h>

@interface CocoaApp : NSApplication {
}
- (void) doNothing:(id) object;
- (void) quit;
@end

@implementation CocoaApp
- (void) doNothing:(id) object {
}

- (void) quit {
	spruce::app::window->close();
}
@end

@interface AppDelegate : NSObject <NSApplicationDelegate>
@end

@implementation AppDelegate
- (void) applicationDidFinishLaunching:(NSNotification*)notification {
	[NSApp stop:nil];
	[NSApp activateIgnoringOtherApps:YES];
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
			keyCodes[input::ARROW_LEFT] = 0x7B;
			keyCodes[input::ARROW_RIGHT] = 0x7C;
			keyCodes[input::ARROW_UP] = 0x7E;
			keyCodes[input::ARROW_DOWN] = 0x7D;
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
			NSString* appName = @"spruce";
			NSMenu* bar = [[NSMenu alloc] init];
			[NSApp setMainMenu:bar];
			NSMenuItem* appMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
			NSMenu* appMenu = [[NSMenu alloc] init];
			[appMenuItem setSubmenu:appMenu];
			[appMenu addItemWithTitle:[NSString stringWithFormat:@"About %@", appName] action:@selector(orderFrontStandardAboutPanel:) keyEquivalent:@""];
			[appMenu addItem:[NSMenuItem separatorItem]];
			NSMenu* servicesMenu = [[NSMenu alloc] init];
			[NSApp setServicesMenu:servicesMenu];
			[[appMenu addItemWithTitle:@"Services" action:NULL keyEquivalent:@""] setSubmenu:servicesMenu];
			[servicesMenu release];
			[appMenu addItem:[NSMenuItem separatorItem]];
			[appMenu addItemWithTitle:[NSString stringWithFormat:@"Hide %@", appName] action:@selector(hide:) keyEquivalent:@"h"];
			[[appMenu addItemWithTitle:@"Hide Others" action:@selector(hideOtherApplications:) keyEquivalent:@"h"] setKeyEquivalentModifierMask:NSEventModifierFlagOption | NSEventModifierFlagCommand];
			[appMenu addItemWithTitle:@"Show All" action:@selector(unhideAllApplications:) keyEquivalent:@""];
			[appMenu addItem:[NSMenuItem separatorItem]];
			//[appMenu addItemWithTitle:[NSString stringWithFormat:@"Quit  %@", appName] action:@s    n b elector(terminate:) keyEquivalent:@"q"];
			[appMenu addItemWithTitle:[NSString stringWithFormat:@"Quit  %@", appName] action:@selector(quit) keyEquivalent:@"q"];
			NSMenuItem* windowMenuItem = [bar addItemWithTitle:@"" action:NULL keyEquivalent:@""];
			[bar release];
			NSMenu* windowMenu = [[NSMenu alloc] initWithTitle:@"Window"];
			[NSApp setWindowsMenu:windowMenu];
			[windowMenuItem setSubmenu:windowMenu];
		}

		void free() {
			[delegate release];
			delegate = nullptr;
		}

		Window* createWindow() {
			return new CocoaWindow();
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

		bool supportsPrecompiledShader(app::API api) {
			if (api == app::METAL) {
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

		string getHomePath() {
			return getenv("HOME");
		}

		string getBasePathInternal() {
			if (app::debug) {
				return "assets/";
			} else {
				NSBundle* bundle = [NSBundle mainBundle];
				return convertStr(bundle.resourcePath) + "/";
			}
		}

		string getBasePathExternal() {
			return string(getHomePath() + "/Library/Application Support/");
		}

		bool isDir(string path) {
			struct stat s;
			if (stat(path.c_str(), &s) == 0) {
				return (s.st_mode & S_IFDIR);
			} else {
				serr("stat error, may not exist ", path);
				return false;
			}
		}

		bool exists(string path) {
			struct stat s;
			if (stat(path.c_str(), &s) == 0) {
				return true;
			} else {
				return false;
			}
		}

		void createDir(string path) {
			mkdir(path.c_str(), S_IWUSR);
		}
	}

	namespace sys {
		string getCPUName() {
			size_t length = 128;
			char buffer[length];
			sysctlbyname("machdep.cpu.brand_string", &buffer, &length, NULL, 0);
			return string(buffer);
		}

		uint16 getCPUCoreCount() {
			uint32 coreCount = 0;
			size_t size = sizeof(coreCount);
			sysctlbyname("hw.physicalcpu", &coreCount, &size, NULL, 0);
			return coreCount;
		}

		uint64 getCPUFrequency() {
			uint64 frequency = 0;
			size_t size = sizeof(frequency);
			sysctlbyname("hw.cpufrequency", &frequency, &size, NULL, 0);
			return frequency;
		}

		uint64 getCacheLineSize() {
			uint64 cacheLineSize = 0;
			size_t size = sizeof(cacheLineSize);
			sysctlbyname("hw.cachelinesize", &cacheLineSize, &size, NULL, 0);
			return cacheLineSize;
		}

		uint64 getL1CacheSize() {
			uint64 l1CacheSize = 0;
			size_t size = sizeof(l1CacheSize);
			sysctlbyname("hw.l1icachesize", &l1CacheSize, &size, NULL, 0);
			return l1CacheSize;
		}

		uint64 getL2CacheSize() {
			uint64 l2CacheSize = 0;
			size_t size = sizeof(l2CacheSize);
			sysctlbyname("hw.l2cachesize", &l2CacheSize, &size, NULL, 0);
			return l2CacheSize;
		}

		uint64 getL3CacheSize() {
			uint64 l3CacheSize = 0;
			size_t size = sizeof(l3CacheSize);
			sysctlbyname("hw.l3cachesize", &l3CacheSize, &size, NULL, 0);
			return l3CacheSize;
		}

		uint64 getRAMSize() {
			uint64 ramSize = 0;
			size_t size = sizeof(ramSize);
			sysctlbyname("hw.memsize", &ramSize, &size, NULL, 0);
			return ramSize;
		}

		uint64 getSwapUsed() {
			uint64 swapUsed = 0;
			size_t size = sizeof(swapUsed);
			sysctlbyname("vm.swapused", &swapUsed, &size, NULL, 0);
			return swapUsed;
		}
	}
}
