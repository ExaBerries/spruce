#pragma once
#include <common.h>

namespace spruce {
	class Frame {
		public:
			std::any rendererData;

			Frame() = default;
			Frame(const Frame&) = delete;
			Frame(Frame&&) = delete;
			~Frame() = default;

			Frame& operator=(const Frame&) = delete;
			Frame& operator=(Frame&&) = delete;
	};
}
