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
			~MetalBuffer() override;

			[[nodiscard]] void* getContents() noexcept;
			void didModifyRange(uint32 start, uint32 length) noexcept;
			[[nodiscard]] uint64 getLength() noexcept;

			MetalBuffer& operator=(const MetalBuffer&) = delete;
			MetalBuffer& operator=(MetalBuffer&&) noexcept = delete;
	};
}
#endif
