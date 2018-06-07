#include <system/MemoryBlock.h>
#include <common.h>

namespace spruce {
	MemoryBlock::MemoryBlock(void* start, uint64 size) {
		this->start = start;
		this->current = start;
		this->size = size;
	}

	MemoryBlock::~MemoryBlock() {
	}

	void* MemoryBlock::alloc(uint64 size) {
		if ((uint64)((uint8*) current + size - (uint8*) start) >= this->size) {
			return nullptr;
		}
		void* p = current;
		current = (uint8*) current + size;
		return p;
	}

	void MemoryBlock::free() {
		current = start;
	}
}
