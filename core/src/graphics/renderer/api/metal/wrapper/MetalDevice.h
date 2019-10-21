#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>
#include <graphics/renderer/api/metal/wrapper/MetalCommandQueue.h>
#include <graphics/renderer/api/metal/wrapper/MetalStorageMode.h>
#include <graphics/renderer/api/metal/wrapper/MetalBuffer.h>
#include <graphics/renderer/api/metal/wrapper/MetalTexture.h>
#include <graphics/renderer/api/metal/wrapper/MetalPixelFormat.h>
#include <graphics/renderer/api/metal/wrapper/MetalResourceStorageMode.h>
#include <graphics/renderer/api/metal/wrapper/MetalStorageMode.h>
#include <graphics/renderer/api/metal/wrapper/MetalTextureUsage.h>
#include <graphics/renderer/api/metal/wrapper/MetalLibrary.h>
#include <graphics/renderer/api/metal/wrapper/MetalRenderPipelineState.h>
#include <graphics/renderer/api/metal/wrapper/MetalRenderPipelineDescriptor.h>
#include <graphics/renderer/api/metal/wrapper/MetalDepthStencilState.h>
#include <graphics/renderer/api/metal/wrapper/MetalCompareFunction.h>

namespace spruce {
	class MetalDevice : public MetalObj {
		public:
			MetalDevice();
			MetalDevice(void* ptr);
			MetalDevice(const MetalDevice&) = delete;
			MetalDevice(MetalDevice&&) noexcept = delete;
			~MetalDevice() override;

			[[nodiscard]] string getName();
			[[nodiscard]] bool getLowPower();
			[[nodiscard]] bool getHeadless();
			[[nodiscard]] bool getRemoveable();

			[[nodiscard]] owner<MetalCommandQueue> createCommandQueue();
			[[nodiscard]] owner<MetalBuffer> createBuffer(uint32 length, MetalResourceStorageMode resourceStorageMode);
			[[nodiscard]] owner<MetalTexture> createTexture(MetalPixelFormat format, vec2i size, bool mipmap, MetalResourceStorageMode resourceStorageMode, MetalStorageMode storageMode, MetalTextureUsage usage);
			[[nodiscard]] owner<MetalLibrary> createLibrary(const buffer<uint8>& data);
			[[nodiscard]] owner<MetalLibrary> createLibrary(const string& text);
			[[nodiscard]] owner<MetalRenderPipelineState> newRenderPipelineState(const MetalRenderPipelineDescriptor& descriptor);
			[[nodiscard]] owner<MetalDepthStencilState> newDepthStencilState(MetalCompareFunction compareFunction, bool depthWrite);

			MetalDevice& operator=(const MetalDevice&) = delete;
			MetalDevice& operator=(MetalDevice&&) noexcept = delete;
	};
}
#endif
