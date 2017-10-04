#include <input/InputSource.h>

namespace spruce {
	namespace input {
		template<typename TYPE>
		InputSource<TYPE>::InputSource() {
		}

		template<typename TYPE>
		InputSource<TYPE>::~InputSource() {
		}

		template<typename TYPE>
		void InputSource<TYPE>::update() {
		};

		template <typename TYPE>
		TYPE InputSource<TYPE>::poll() {
		}
	}
}
