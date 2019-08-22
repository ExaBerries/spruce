#include <graphics/renderer/api/metal/wrapper/MetalVertexDescriptor.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	constexpr MTLVertexDescriptor* castVertexDescriptor(void* ptr) {
		return (__bridge MTLVertexDescriptor*) ptr;
	}

	MetalVertexDescriptor::MetalVertexDescriptor() : MetalObj([MTLVertexDescriptor vertexDescriptor]) {
	}

	MetalVertexDescriptor::~MetalVertexDescriptor() {
		[castVertexDescriptor(ptr) release];
	}

	void MetalVertexDescriptor::reset() {
		[castVertexDescriptor(ptr) reset];
	}

	void MetalVertexDescriptor::setAttribute(uint32 index, MetalVertexFormat format, uint32 offset, uint32 bufferIndex) {
		castVertexDescriptor(ptr).attributes[index].format = mapVertexFormat(format);
		castVertexDescriptor(ptr).attributes[index].offset = offset;
		castVertexDescriptor(ptr).attributes[index].bufferIndex = bufferIndex;
	}

	void MetalVertexDescriptor::setLayout(uint32 index, MetalVertexStepFunction function, uint32 stride, uint32 stepRate) {
		castVertexDescriptor(ptr).layouts[index].stepFunction = mapVertexStepFunction(function);
		castVertexDescriptor(ptr).layouts[index].stride = stride;
		castVertexDescriptor(ptr).layouts[index].stepRate = stepRate;
	}
}
#endif
