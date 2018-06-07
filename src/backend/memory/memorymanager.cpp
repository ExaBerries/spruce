#include <backend/memory/memorymanager.h>
#include <common.h>
#include <backend/memory/MemoryBlockBackend.h>

namespace spruce {
	namespace mem {
		std::vector<MemoryBlockBackend> memoryBlocks;

		void* allocBuffer(uint64 size) {
			if (size == 0) {
				return nullptr;
			}
			void* ptr = malloc(size);
			return ptr;
		}

		void freeBuffer(uint64 size, void* buffer) {
			free(buffer);
		}

		MemoryBlock& allocBlock(uint64 size) {
			memoryBlocks.emplace_back(malloc(size), size);
			return memoryBlocks.back().block;
		}

		void freeBlock(MemoryBlock& memBlock) {
			for (uint16 i = 0; i < memoryBlocks.size(); i++) {
				if (memoryBlocks[i].block.start == memBlock.start) {
					memoryBlocks.erase(memoryBlocks.begin() + i);
				}
			}
			memBlock.free();
			free(memBlock.start);
		}

		void update() {
		}
	}
}
