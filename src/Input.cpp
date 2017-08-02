#include <input.h>
#include <Application.h>
#include <platform/Backend.h>

namespace spruce {
	namespace input {
		bool keyPressed(uint16 code) {
			return app::backend->keyPressed(code);
		}
	}
}
