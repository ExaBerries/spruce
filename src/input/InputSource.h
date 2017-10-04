#pragma once
#include <common.h>

namespace spruce {
	namespace input {
		template<typename TYPE>
		class InputSource {
			public:
				InputSource();
				virtual ~InputSource();

				virtual void update();
				virtual TYPE poll();
		};
	}
}
