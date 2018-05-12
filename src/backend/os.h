#pragma once
#include <common.h>
#include <app.h>
#include <backend/Window.h>
#include <input/Key.h>

namespace spruce {
	namespace os {
		void init();
		void free();

		Window* createWindow();
		bool supportsAPI(app::API api);
		bool supportsPrecompiledShader(app::API api);

		void updateStart();
		void updateEnd();

		uint16 codeFor(input::Key key);

		string getHomePath();
		string getBasePathInternal();
		string getBasePathExternal();
		bool isDir(string path);
		bool exists(string path);
		void createDir(string path);
	}
}
