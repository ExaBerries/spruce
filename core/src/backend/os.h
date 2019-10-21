#pragma once
#include <common.h>
#include <app/API.h>
#include <backend/Window.h>
#include <input/Key.h>
#include <backend/ApplicationBackend.h>

namespace spruce {
	namespace os {
		void init() noexcept;
		void free() noexcept;

		[[nodiscard]] owner<ApplicationBackend> createAppBackend() noexcept;

		[[nodiscard]] uint16 codeFor(input::Key key) noexcept;

		[[nodiscard]] string getHomePath() noexcept;
		[[nodiscard]] string getBasePathInternal() noexcept;
		[[nodiscard]] string getBasePathExternal() noexcept;
		[[nodiscard]] bool isDir(const string& path) noexcept;
		[[nodiscard]] bool exists(const string& path) noexcept;
		void createDir(const string& path) noexcept;
		[[nodiscard]] std::vector<string> listSubFiles(const string& path) noexcept;
	}
}
