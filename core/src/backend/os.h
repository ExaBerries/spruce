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

		owner<ApplicationBackend> createAppBackend();

		uint16 codeFor(input::Key key);

		string getHomePath();
		string getBasePathInternal();
		string getBasePathExternal();
		bool isDir(string path);
		bool exists(string path);
		void createDir(string path);
		std::vector<string> listSubFiles(string path);
	}
}
