#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>
#include <graphics/renderer/api/metal/wrapper/MetalVertexFormat.h>
#include <graphics/renderer/api/metal/wrapper/MetalVertexStepFunction.h>

namespace spruce {
	class MetalVertexDescriptor : public MetalObj {
		public:
			MetalVertexDescriptor();
			MetalVertexDescriptor(const MetalVertexDescriptor& other) = delete;
			MetalVertexDescriptor(MetalVertexDescriptor&& other) = delete;
			~MetalVertexDescriptor() override;

			void reset();
			void setAttribute(uint32 index, MetalVertexFormat format, uint32 offset, uint32 bufferIndex);
			void setLayout(uint32 index, MetalVertexStepFunction function, uint32 stride, uint32 stepRate);

			MetalVertexDescriptor& operator=(const MetalVertexDescriptor& other) = delete;
			MetalVertexDescriptor& operator=(MetalVertexDescriptor&& other) = delete;
	};
}
#endif
