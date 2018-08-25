#pragma once
#include <common.h>
#include <io/FileHandle.h>

namespace spruce {
	class Script {
		public:
			string code;

			Script(string code);
			Script(FileHandle& handle);
			virtual ~Script();
	};
}
