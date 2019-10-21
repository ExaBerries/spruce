#pragma once
#include <types.h>

namespace spruce {
	namespace sys {
		[[nodiscard]] float timeSec();
		[[nodiscard]] int64 timeNano();
	}
}
