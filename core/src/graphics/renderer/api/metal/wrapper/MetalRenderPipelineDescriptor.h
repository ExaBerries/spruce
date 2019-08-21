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
			~MetalRenderPipelineDescriptor();

			void setVertexFunction(const MetalFunction* function);
			void setFragmentFunction(const MetalFunction* function);
			void setVertexDescriptor(const MetalVertexDescriptor& descriptor);
			void setColorAttachmentPixelFormat(uint32 index, MetalPixelFormat format);
			void setColorAttachmentBlending(uint32 index, bool blend);
			void setDepthAttachmentPixelFormat(MetalPixelFormat format);
			void setStencilAttachmentPixelFormat(MetalPixelFormat format);

			MetalRenderPipelineDescriptor& operator=(const MetalRenderPipelineDescriptor& other) = delete;
			MetalRenderPipelineDescriptor& operator=(MetalRenderPipelineDescriptor&& other) noexcept = delete;
	};
}
#endif
