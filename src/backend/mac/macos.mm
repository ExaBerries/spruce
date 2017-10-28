#include <backend/os.h>
#include <system/system.h>
#include <input/input.h>
#include <sys/sysctl.h>
#include <backend/mac/CocoaWindow.h>

namespace spruce {
	namespace os {
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
				return;
			}
			[NSApp sendEvent:event];
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
