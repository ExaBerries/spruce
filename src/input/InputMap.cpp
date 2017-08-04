#include <input/InputMap.h>

namespace spruce {
	namespace input {
		InputMap::InputMap() {
		}

		InputMap::~InputMap() {
		}

		bool InputMap::active(string name) {
			for (int i = 0; i < inputs.size(); i++) {
				if (inputs[i].name == name) {
					return inputs[i].active();
				}
			}
			return false;
		}

		void InputMap::add(InputSource source) {
			inputs.push_back(source);
		}
	}
}
