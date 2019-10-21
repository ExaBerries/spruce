#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>
#include <graphics/renderer/api/metal/wrapper/MetalVertexDescriptor.h>
#include <graphics/renderer/api/metal/wrapper/MetalFunction.h>
#include <graphics/renderer/api/metal/wrapper/MetalPixelFormat.h>

namespace spruce {
	class MetalRenderPipelineDescriptor : public MetalObj {
		public:
			MetalRenderPipelineDescriptor();
			MetalRenderPipelineDescriptor(const MetalRenderPipelineDescriptor& other) = delete;
			MetalRenderPipelineDescriptor(MetalRenderPipelineDescriptor&& other) = delete;
			~MetalRenderPipelineDescriptor() override;

			void setVertexFunction(const MetalFunction* function) noexcept;
			void setFragmentFunction(const MetalFunction* function) noexcept;
			void setVertexDescriptor(const MetalVertexDescriptor& descriptor) noexcept;
			void setColorAttachmentPixelFormat(uint32 index, MetalPixelFormat format) noexcept;
			void setColorAttachmentBlending(uint32 index, bool blend) noexcept;
			void setDepthAttachmentPixelFormat(MetalPixelFormat format) noexcept;
			void setStencilAttachmentPixelFormat(MetalPixelFormat format) noexcept;

			MetalRenderPipelineDescriptor& operator=(const MetalRenderPipelineDescriptor& other) = delete;
			MetalRenderPipelineDescriptor& operator=(MetalRenderPipelineDescriptor&& other) noexcept = delete;
	};
}
#endif
