#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>
#include <graphics/renderer/api/metal/wrapper/MetalFunction.h>

namespace spruce {
	class MetalLibrary : public MetalObj {
		public:
			MetalLibrary(void* ptr);
			MetalLibrary(const MetalLibrary& other) = delete;
			MetalLibrary(MetalLibrary&& other) = delete;
			~MetalLibrary();

			owner<MetalFunction> newFunctionWithName(const string& name);

			MetalLibrary& operator=(const MetalLibrary& other) = delete;
			MetalLibrary& operator=(MetalLibrary&& other) = delete;
	};
}
#endif
