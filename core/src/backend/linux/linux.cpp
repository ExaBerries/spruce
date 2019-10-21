#ifdef __linux__
#include <backend/os.h>
#include <system/system.h>
#include <input/input.h>
#include <app/app.h>
#include <backend/linux/X11AppBackend.h>
#include <backend/linux/X11Window.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <dirent.h>
#include <sys/stat.h>

namespace spruce {
	namespace os {
		buffer<uint16> keyCodes(nullptr);

		void init() {
			keyCodes = buffer<uint16>(80);
			keyCodes[input::A] = 38;
			keyCodes[input::B] = 56;
			keyCodes[input::C] = 54;
			keyCodes[input::D] = 40;
			keyCodes[input::E] = 26;
			keyCodes[input::F] = 41;
			keyCodes[input::G] = 42;
			keyCodes[input::H] = 43;
			keyCodes[input::I] = 31;
			keyCodes[input::J] = 44;
			keyCodes[input::K] = 45;
			keyCodes[input::L] = 46;
			keyCodes[input::M] = 58;
			keyCodes[input::N] = 57;
			keyCodes[input::O] = 32;
			keyCodes[input::P] = 33;
			keyCodes[input::Q] = 24;
			keyCodes[input::R] = 27;
			keyCodes[input::S] = 39;
			keyCodes[input::T] = 28;
			keyCodes[input::U] = 30;
			keyCodes[input::V] = 55;
			keyCodes[input::W] = 25;
			keyCodes[input::X] = 53;
			keyCodes[input::Y] = 29;
			keyCodes[input::Z] = 52;
			keyCodes[input::ZERO] = 19;
			keyCodes[input::ONE] = 10;
			keyCodes[input::TWO] = 11;
			keyCodes[input::THREE] = 12;
			keyCodes[input::FOUR] = 13;
			keyCodes[input::FIVE] = 14;
			keyCodes[input::SIX] = 15;
			keyCodes[input::SEVEN] = 16;
			keyCodes[input::EIGHT] = 17;
			keyCodes[input::NINE] = 18;
			keyCodes[input::ENTER] = 36;
			keyCodes[input::ESCAPE] = 9;
			keyCodes[input::DELETE] = 51;
			keyCodes[input::HOME] = 0; // TODO get keycode
			keyCodes[input::INSERT] = 0; // TODO get keycode
			keyCodes[input::END] = 0; // TODO get keycode
			keyCodes[input::PAGE_UP] = 0; // TODO get keycode
			keyCodes[input::PAGE_DOWN] = 0; // TODO get keycode
			keyCodes[input::TAB] = 23;
			keyCodes[input::SPACE] = 64;
			keyCodes[input::SEMICOLON] = 47;
			keyCodes[input::APOSTROPHE] = 49;
			keyCodes[input::SLASH] = 61;
			keyCodes[input::BACKSLASH] = 51;
			keyCodes[input::PERIOD] = 60;
			keyCodes[input::COMMA] = 59;
			keyCodes[input::EQUAL] = 21;
			keyCodes[input::MINUS] = 20;
			keyCodes[input::LEFT_BRACKET] = 34;
			keyCodes[input::RIGHT_BRACKET] = 35;
			keyCodes[input::ARROW_LEFT] = 113;
			keyCodes[input::ARROW_RIGHT] = 114;
			keyCodes[input::ARROW_UP] = 111;
			keyCodes[input::ARROW_DOWN] = 116;
			keyCodes[input::SHIFT_LEFT] = 50;
			keyCodes[input::SHIFT_RIGHT] = 62;
			keyCodes[input::CONTROL_LEFT] = 37;
			keyCodes[input::CONTROL_RIGHT] = 0; // TODO get keycode
			keyCodes[input::ALT_LEFT] = 64;
			keyCodes[input::ALT_RIGHT] = 108;
			keyCodes[input::SUPER_LEFT] = 133;
			keyCodes[input::SUPER_RIGHT] = 134;
			keyCodes[input::F1] = 67;
			keyCodes[input::F2] = 68;
			keyCodes[input::F3] = 69;
			keyCodes[input::F4] = 70;
			keyCodes[input::F5] = 71;
			keyCodes[input::F6] = 72;
			keyCodes[input::F7] = 73;
			keyCodes[input::F8] = 74;
			keyCodes[input::F9] = 75;
			keyCodes[input::F10] = 76;
			keyCodes[input::F11] = 95;
			keyCodes[input::F12] = 96;
		}

		void free() {
		}

		[[nodiscard]] owner<ApplicationBackend> createAppBackend() {
			return new X11AppBackend();
		}

		bool supportsAPI(app::API api) {
			if (api == app::OPENGL) {
				return true;
			} else if (api == app::VULKAN) {
				return true;
			}
			return false;
		}

		bool supportsPrecompiledShader(app::API api) {
			if (api == app::OPENGL) {
				return true;
			} else if (api == app::VULKAN) {
				return true;
			}
			return false;
		}

		uint16 codeFor(input::Key key) {
			return keyCodes[key];
		}

		string getHomePath() {
			return getenv("HOME");
		}

		string getBasePathInternal() {
			#ifdef DEBUG
				return "assets/";
			#else
				return "";
			#endif
		}

		string getBasePathExternal() {
			return string();
		}

		bool isDir(const string& path) {
			struct stat s;
			if (stat(path.c_str(), &s) == 0) {
				return (s.st_mode & S_IFDIR);
			} else {
				serr("stat error, may not exist ", path);
				return false;
			}
		}

		bool exists(const string& path) {
			struct stat s;
			if (stat(path.c_str(), &s) == 0) {
				return true;
			} else {
				return false;
			}
		}

		void createDir(const string& path) {
			mkdir(path.c_str(), S_IWUSR);
		}

		std::vector<string> listSubFiles(const string& path) {
			std::vector<string> subFiles;
			DIR* dir;
			struct dirent* entry;
			if ((dir  = opendir(path.c_str())) == NULL) {
				serr("error calling opendir on ", path);
			}
			while ((entry = readdir(dir)) != NULL) {
				string name(entry->d_name);
				if (name != string(".") && name != string("..")) {
					subFiles.push_back(name);
				}
			}
			closedir(dir);
			return subFiles;
		}
	}

	namespace sys {
		string getCPUName() {
			return "";
		}

		uint16 getCPUCoreCount() {
			return 0;
		}

		uint64 getCPUFrequency() {
			return 0;
		}

		uint64 getCacheLineSize() {
			return 0;
		}

		uint64 getL1CacheSize() {
			return 0;
		}

		uint64 getL2CacheSize() {
			return 0;
		}

		uint64 getL3CacheSize() {
			return 0;
		}

		uint64 getRAMSize() {
			return 0;
		}

		uint64 getSwapUsed() {
			return 0;
		}
	}
}
#endif
