#include <backend/api/metal/Metal.h>
#include <backend/api/metal/MetalContext.h>
#include <backend/api/metal/MetalMesh.h>
#include <backend/api/metal/MetalShader.h>
#include <backend/api/metal/MetalMeshRenderer.h>
#include <backend/api/metal/MetalShapeRenderer.h>
#include <backend/api/metal/MetalTexture.h>
#include <io/image.h>

namespace spruce {
	Metal::Metal(Window* window) : RenderAPI(window) {
	}

	Metal::~Metal() {
		[device release];
		[commandQueue release];
		[commandBuffer release];
		[renderEncoder release];
		[depthStencilState release];
	}

	void Metal::init() {
		MTLDepthStencilDescriptor* depthStencilDescriptor = [MTLDepthStencilDescriptor new];
		depthStencilDescriptor.depthCompareFunction = MTLCompareFunctionLess;
		depthStencilDescriptor.depthWriteEnabled = YES;
		depthStencilState = [device newDepthStencilStateWithDescriptor:depthStencilDescriptor];
	}

	void Metal::updateStart() {
		commandBuffer = [commandQueue commandBuffer];
		[commandBuffer enqueue];
		[view update];
		MTLRenderPassDescriptor* desc = [view getRenderPassDescriptor];
		if (desc == nullptr) {
			return;
		}
		renderEncoder = [commandBuffer renderCommandEncoderWithDescriptor:desc];
		renderEncoder.label = @"SpruceRenderEncoder";
		[renderEncoder setViewport:(MTLViewport){0.0, 0.0, view.frame.size.width, view.frame.size.height, 0.0, 1.0}];
		[renderEncoder setDepthStencilState:depthStencilState];
	}

	void Metal::updateEnd() {
		if ([view getRenderPassDescriptor] == nullptr) {
			return;
		}
		[renderEncoder endEncoding];
		[commandBuffer presentDrawable:[view getDrawable]];
		[commandBuffer commit];
		[view releaseDrawable];
		[commandBuffer release];
		[renderEncoder release];
	}

	Mesh* Metal::createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) {
		return new MetalMesh(vertexCount, vertices, indexCount, indices);
	}

	Shader* Metal::createShader(string& vert, string& frag, uint16 attributeCount, VertexAttribute* attributes) {
		return new MetalShader(vert, frag, attributeCount, attributes);
	}

	MeshRenderer* Metal::createMeshRenderer() {
		return new MetalMeshRenderer();
	}

	ShapeRenderer* Metal::createShapeRenderer() {
		return new MetalShapeRenderer();
	}

	Texture* Metal::createTexture(string& path) {
		uint16 width = 0;
		uint16 height = 0;
		uint16 bitsPerPixel = 0;
		uint8* data = io::loadImage(path, width, height, bitsPerPixel);
		return new MetalTexture(data, width, height, bitsPerPixel);
	}

	void Metal::setBlend(bool value) {
	}

	void Metal::setDepth(bool value) {
	}

	string Metal::getGPUVendor() {
		return "";
	}

	uint16 Metal::getAPIVersionMajor() {
		return 0;
	}

	uint16 Metal::getAPIVersionMinor() {
		return 0;
	}

	string Metal::getAPIRendererName() {
		return "";
	}
}
