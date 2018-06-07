#pragma once
#include <common.h>
#include <system/MemoryBlock.h>

namespace spruce {
	namespace mem {
		class MemoryBlockBackend {
			public:
				MemoryBlock block;

				MemoryBlockBackend(void* start, uint32 size);
				MemoryBlockBackend(const MemoryBlockBackend& blk);
				virtual ~MemoryBlockBackend();
		};
	}
}
