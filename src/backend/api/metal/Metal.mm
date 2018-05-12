#include <backend/api/metal/Metal.h>
#include <backend/api/metal/MetalContext.h>
#include <backend/api/metal/MetalMesh.h>
#include <backend/api/metal/MetalShader.h>
#include <backend/api/metal/MetalShapeRenderer.h>
#include <backend/api/metal/MetalTexture.h>
#include <backend/api/metal/MetalRenderTarget.h>
#include <io/image.h>
#include <graphics/graphics.h>
#include <Metal/Metal.h>
#include <backend/mac/objcpp.h>

namespace spruce {
	Metal::Metal(Window* window) : RenderAPI(window, vec3f(2, 2, 1)) {
		fontVert =
				#include <backend/api/metal/font.metal>
		;
		fontFrag = "";
	}

	Metal::~Metal() {
		[device release];
		[commandQueue release];
		[depthStencilState release];
	}

	void Metal::init() {
		MTLDepthStencilDescriptor* depthStencilDescriptor = [MTLDepthStencilDescriptor new];
		depthStencilDescriptor.depthCompareFunction = MTLCompareFunctionLess;
		depthStencilDescriptor.depthWriteEnabled = YES;
		depthStencilState = [device newDepthStencilStateWithDescriptor:depthStencilDescriptor];
		[depthStencilDescriptor release];
	}

	void Metal::renderStart() {
		commandBuffer = [commandQueue commandBuffer];
		[commandBuffer enqueue];
		[view update];
		MTLRenderPassDescriptor* desc = [view getRenderPassDescriptor];
		if (desc == nullptr) {
			return;
		}
		renderEncoder = [commandBuffer renderCommandEncoderWithDescriptor:desc];
		renderEncoder.label = @"SpruceRenderEncoder";
		[renderEncoder setViewport:(MTLViewport){0.0, 0.0, [view getDrawableSize].width, [view getDrawableSize].height, 0.0, 1.0}];
		[renderEncoder setDepthStencilState:depthStencilState];
	}

	void Metal::renderEnd() {
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

	string Metal::getError() {
		return "";
	}

	Mesh* Metal::createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) {
		return new MetalMesh(vertexCount, vertices, indexCount, indices);
	}

	Shader* Metal::createShader(uint8* vertData, uint16 vertDataSize, uint8* fragData, uint16 fragDataSize, uint16 attributeCount, VertexAttribute* attributes) {
		return new MetalShader(vertData, vertDataSize, fragData, fragDataSize, attributeCount, attributes);
	}

	Shader* Metal::createShader(string& vert, string& frag, uint16 attributeCount, VertexAttribute* attributes) {
		return new MetalShader(vert, frag, attributeCount, attributes);
	}

	ShapeRenderer* Metal::createShapeRenderer() {
		return new MetalShapeRenderer();
	}

	Texture* Metal::createTexture(const FileHandle& path) {
		uint16 width = 0;
		uint16 height = 0;
		uint16 bitsPerPixel = 0;
		uint8* data = io::loadImage(path, width, height, bitsPerPixel);
		return new MetalTexture(Texture::RGBA, data, width, height);
	}

	Texture* Metal::createTexture(Texture::PixelFormat format, uint8* data, uint16 width, uint16 height) {
		return new MetalTexture(format, data, width, height);
	}

	RenderTarget* Metal::createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height) {
		return new MetalRenderTarget(format, width, height);
	}

	void Metal::render(Mesh* mesh, Shader* shader) {
		[renderEncoder setVertexBuffer:((MetalMesh*)mesh)->vertexBuffer offset:0 atIndex:0];
		if (mesh->indexCount > 0) {
			[renderEncoder drawIndexedPrimitives:MTLPrimitiveTypeTriangle indexCount:((MetalMesh*)mesh)->indexCount indexType:MTLIndexTypeUInt16 indexBuffer:((MetalMesh*)mesh)->indexBuffer indexBufferOffset:0];
		} else {
			[renderEncoder drawPrimitives:MTLPrimitiveTypeTriangle vertexStart:0 vertexCount:mesh->vertexCount];
		}
	}

	void Metal::renderStart(graphics::RenderPass* renderPass) {
		if (renderEncoder != nil) {
			[renderEncoder endEncoding];
			[renderEncoder release];
		}
		if (renderPass->target != nullptr) {
			renderEncoder = [commandBuffer renderCommandEncoderWithDescriptor:((MetalRenderTarget*)renderPass->target)->renderPassDescriptor];
			renderEncoder.label = @"SpruceRenderEncoder";
			[renderEncoder setViewport:(MTLViewport){0.0, 0.0, (double) renderPass->target->width, (double) renderPass->target->height, 0.0, 1.0}];
		} else {
			renderEncoder = [commandBuffer renderCommandEncoderWithDescriptor:[view getRenderPassDescriptor]];
			[renderEncoder setViewport:(MTLViewport){0.0, 0.0, [view getDrawableSize].width, [view getDrawableSize].height, 0.0, 1.0}];
		}
		[renderEncoder setDepthStencilState:depthStencilState];
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
		NSString* rendererName = [device name];
		return convertStr(rendererName);
	}

	void Metal::setPerspective(mat4f& matrix, float& near, float& far, float& fov, float& aspectRatio) {
		float size = 1.0 / tan(fov / 2.0);
		matrix.values[0] = size / aspectRatio;
		matrix.values[1] = 0.0;
		matrix.values[2] = 0.0;
		matrix.values[3] = 0.0;
		matrix.values[4] = 0.0;
		matrix.values[5] = size;
		matrix.values[6] = 0.0;
		matrix.values[7] = 0.0;
		matrix.values[8] = 0.0;
		matrix.values[9] = 0.0;
		matrix.values[10] = (far + near) / (near - far);
		matrix.values[11] = (2.0 * far * near) / (near - far);
		matrix.values[12] = 0.0;
		matrix.values[13] = 0.0;
		matrix.values[14] = -1.0;
		matrix.values[15] = 0.0;
	}

	void Metal::setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) {
		matrix.values[0] = 2.0 / (right - left);
		matrix.values[1] = 0.0;
		matrix.values[2] = 0.0;
		matrix.values[3] = (left + right) / (left - right);
		matrix.values[4] = 0.0;
		matrix.values[5] = -2.0 / (top - bottom);
		matrix.values[6] = 0.0;
		matrix.values[7] = (bottom + top) / (bottom - top);
		matrix.values[8] = 0.0;
		matrix.values[9] = 0.0;
		matrix.values[10] = -1.0 / (far - near);
		matrix.values[11] = near / (near - far);
		matrix.values[12] = 0.0;
		matrix.values[13] = 0.0;
		matrix.values[14] = 0.0;
		matrix.values[15] = 1.0;
	}
}
