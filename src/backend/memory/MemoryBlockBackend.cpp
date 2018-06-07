#include <backend/memory/MemoryBlockBackend.h>

namespace spruce {
	namespace mem {
		MemoryBlockBackend::MemoryBlockBackend(void* start, uint32 size) : block(start, size) {
		}

		MemoryBlockBackend::MemoryBlockBackend(const MemoryBlockBackend& blk) : block(blk.block.start, blk.block.size) {
			this->block.current = blk.block.current;
			slog(":(");
		}

		MemoryBlockBackend::~MemoryBlockBackend() {
		}
	}
}
