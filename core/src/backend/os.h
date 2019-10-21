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

		[[nodiscard]] uint16 codeFor(input::Key key);

		[[nodiscard]] string getHomePath();
		[[nodiscard]] string getBasePathInternal();
		[[nodiscard]] string getBasePathExternal();
		[[nodiscard]] bool isDir(const string& path);
		[[nodiscard]] bool exists(const string& path);
		void createDir(const string& path);
		[[nodiscard]] std::vector<string> listSubFiles(const string& path);
	}
}
