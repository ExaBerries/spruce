#pragma once
#include <types.h>

namespace spruce {
	class MemoryBlock {
		public:
			void* start;
			void* current;
			uint64 size;

			MemoryBlock(void* start, uint64 size);
			MemoryBlock(const MemoryBlock& block) = delete;
			virtual ~MemoryBlock();

			void* alloc(uint64 size);
			void free();
	};
}
