#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>
#include <graphics/renderer/api/metal/wrapper/MetalCommandQueue.h>
#include <graphics/renderer/api/metal/wrapper/MetalStorageMode.h>
#include <graphics/renderer/api/metal/wrapper/MetalBuffer.h>
#include <graphics/renderer/api/metal/wrapper/MetalRenderPipelineState.h>

namespace spruce {
	class MetalDevice : public MetalObj {
		public:
			MetalDevice();
			MetalDevice(void* ptr);
			MetalDevice(const MetalDevice&) = delete;
			MetalDevice(MetalDevice&&) noexcept = delete;
			~MetalDevice();

			string getName();
			bool getLowPower();
			bool getHeadless();
			bool getRemoveable();

			MetalCommandQueue* createCommandQueue();
			MetalBuffer* createMetalBuffer(uint32 length, MetalStorageMode storageMode);
			void createTexture();
			void createLibrary();
			MetalRenderPipelineState* newRenderPipelineState();
			void newComputePipelineState();

			MetalDevice& operator=(const MetalDevice&) = delete;
			MetalDevice& operator=(MetalDevice&&) noexcept = delete;
	};
}
#endif
