#pragma once
#include <types.h>

namespace spruce {
	namespace sys {
		[[nodiscard]] float timeSec() noexcept;
		[[nodiscard]] int64 timeNano() noexcept;
	}
}
