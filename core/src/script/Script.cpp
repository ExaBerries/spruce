#include <script/Script.h>
#include <io/file.h>

namespace spruce {
	Script::Script(string code) : code(code) {
	}

	Script::Script(FileHandle& handle) {
		code = io::readFileTxt(handle);
	}

	Script::~Script() {
	}
}
