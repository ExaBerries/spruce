#pragma once
#include <types.h>
#include <vector>
#include <system/MemoryBlock.h>

namespace spruce {
	namespace mem {
		void* allocBuffer(uint64 size);
		void freeBuffer(uint64 size, void* buffer);

		MemoryBlock& allocBlock(uint64 size);
		void freeBlock(MemoryBlock& memBlock);

		void update();
	}
}
