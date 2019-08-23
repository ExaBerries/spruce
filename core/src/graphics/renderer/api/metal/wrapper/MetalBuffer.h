#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>

namespace spruce {
	class MetalBuffer : public MetalObj {
		public:
			MetalBuffer(void* ptr);
			MetalBuffer(const MetalBuffer&) = delete;
			MetalBuffer(MetalBuffer&&) noexcept = delete;
			~MetalBuffer();

			void* getContents();
			void didModifyRange(uint32 start, uint32 length);
			uint32 getLength();

			MetalBuffer& operator=(const MetalBuffer&) = delete;
			MetalBuffer& operator=(MetalBuffer&&) noexcept = delete;
	};
}
#endif
