#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>

namespace spruce {
	class MetalFunction : public MetalObj {
		public:
			MetalFunction(void* ptr);
			MetalFunction(const MetalFunction& other) = delete;
			MetalFunction(MetalFunction&& other) = delete;
			~MetalFunction();

			MetalFunction& operator=(const MetalFunction& other) = delete;
			MetalFunction& operator=(MetalFunction&& other) = delete;
	};
}
#endif
