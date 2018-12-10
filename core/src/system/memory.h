#pragma once
#include <types.h>
#include <system/MemoryBlock.h>
#include <system/buffer.h>

namespace spruce {
	MemoryBlock& allocBlock(uint64 size);
	void freeBlock(MemoryBlock& blk);
}
