#include <system/memory.h>
#include <backend/memory/memorymanager.h>
#include <thread>

namespace spruce {
	std::mutex memMutex;

	MemoryBlock& allocBlock(uint64 size) {
		std::lock_guard<std::mutex> memLock(memMutex);
		return mem::allocBlock(size);
	}

	void freeBlock(MemoryBlock& blk) {
		mem::freeBlock(blk);
	}
}
