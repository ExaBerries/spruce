#pragma once
#include <common.h>
#include <app/API.h>
#include <backend/Window.h>
#include <input/Key.h>
#include <backend/ApplicationBackend.h>

namespace spruce {
	namespace os {
		void init();
		void free();

		[[nodiscard]] owner<ApplicationBackend> createAppBackend();

		uint16 codeFor(input::Key key);

		string getHomePath();
		string getBasePathInternal();
		string getBasePathExternal();
		bool isDir(const string& path);
		bool exists(const string& path);
		void createDir(const string& path);
		std::vector<string> listSubFiles(const string& path);
	}
}
