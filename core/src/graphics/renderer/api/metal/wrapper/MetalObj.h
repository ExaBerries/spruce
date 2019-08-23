#pragma once
#ifdef __APPLE__
#include <common.h>

namespace spruce {
	class MetalObj {
		public:
			void* ptr;

			MetalObj(void* ptr);
			MetalObj(const MetalObj&) = delete;
			MetalObj(MetalObj&&) noexcept = delete;
			virtual ~MetalObj() = default;

			MetalObj& operator=(const MetalObj&) = delete;
			MetalObj& operator=(MetalObj&&) noexcept = delete;
	};
}
#endif
