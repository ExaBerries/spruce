#pragma once
#include <common.h>
#include <input/InputSource.h>
#include <vector>

namespace spruce {
	namespace input {
		class InputMap {
			private:
				std::vector<InputSource> inputs;
			public:
				InputMap();
				virtual ~InputMap();

				bool active(string name);
				void add(InputSource source);
		};
	}
}
