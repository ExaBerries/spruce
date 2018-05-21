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
		fontAttributes = new VertexAttribute[2];
		fontAttributes[0] = VertexAttribute("position", 3);
		fontAttributes[1] = VertexAttribute("texCoord", 2);
		fontShader = createShader(fontVert, fontFrag, 2, fontAttributes);
		fontShader->compile(nullptr);
		fontShader->registerUniform("camera", 1);
		fontShader->registerUniform("tex", 2);
		fontShader->registerUniform("color", 3);
		fontMesh = createMesh(0, nullptr, 0, nullptr);
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

	void Metal::bind(Mesh* mesh) {
	}

	void Metal::bind(Texture* texture) {
	}

	void Metal::unbind(Texture* texture) {
	}

	void Metal::bind(Shader* shader) {
		[renderEncoder setRenderPipelineState:((MetalShader*)shader)->pipelineState];
	}

	void Metal::setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const int32& value) {
		if (location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&value length:sizeof(value) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		} else if (location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&value length:sizeof(value) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		}
	}

	void Metal::setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const vec2i& vector) {
		vector_int2 vec = {vector.x, vector.y};
		if (location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&vec length:sizeof(vec) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		} else if (location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&vec length:sizeof(vec) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		}
	}

	void Metal::setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const float& value) {
		if (location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&value length:sizeof(value) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		} else if (location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&value length:sizeof(value) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		}
	}

	void Metal::setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const vec2f& vector) {
		vector_float2 vec = {vector.x, vector.y};
		if (location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&vec length:sizeof(vec) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		} else if (location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&vec length:sizeof(vec) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		}
	}

	void Metal::setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const vec3f& vector) {
		vector_float3 vec = {vector.x, vector.y, vector.z};
		if (location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&vec length:sizeof(vec) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		} else if (location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&vec length:sizeof(vec) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		}
	}

	void Metal::setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const mat4f& matrix) {
		vector_float4 r0 = {matrix.values[0],matrix.values[1],matrix.values[2],matrix.values[3]};
		vector_float4 r1 = {matrix.values[4],matrix.values[5],matrix.values[6],matrix.values[7]};
		vector_float4 r2 = {matrix.values[8],matrix.values[9],matrix.values[10],matrix.values[11]};
		vector_float4 r3 = {matrix.values[12],matrix.values[13],matrix.values[14],matrix.values[15]};
		matrix_float4x4 mat = matrix_from_rows(r0,r1,r2,r3);
		if (location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&mat length:sizeof(mat) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		} else if (location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&mat length:sizeof(mat) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		}
	}

	void Metal::setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const quaternion& quaternion) {
		vector_float4 quat = {quaternion.x, quaternion.y, quaternion.z, quaternion.w};
		if (location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&quat length:sizeof(quat) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		} else if (location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&quat length:sizeof(quat) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		}
	}

	void Metal::setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const color& color) {
		vector_float4 col = {color.r, color.g, color.b, color.a};
		if (location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&col length:sizeof(col) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		} else if (location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&col length:sizeof(col) atIndex:((MetalShader*)shader)->uniformLocations[name]];
		}
	}

	void Metal::setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const Texture* texture) {
		if (location == Shader::VERTEX) {
			[renderEncoder setVertexTexture:((MetalTexture*)texture)->mtlTexture atIndex:((MetalShader*)shader)->uniformLocations[name]];
		} else if (location == Shader::FRAGMENT) {
			[renderEncoder setFragmentTexture:((MetalTexture*)texture)->mtlTexture atIndex:((MetalShader*)shader)->uniformLocations[name]];
		}
	}

	void Metal::setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const graphics::RenderPass* renderPass) {
		id<MTLTexture> texture;
		if (((MetalRenderTarget*)renderPass->target)->color != nullptr) {
			texture = ((MetalRenderTarget*)renderPass->target)->color->mtlTexture;
		} else {
			texture = ((MetalRenderTarget*)renderPass->target)->depth->mtlTexture;
		}
		if (location == Shader::VERTEX) {
			[renderEncoder setVertexTexture:texture atIndex:((MetalShader*)shader)->uniformLocations[name]];
		} else if (location == Shader::FRAGMENT) {
			[renderEncoder setFragmentTexture:texture atIndex:((MetalShader*)shader)->uniformLocations[name]];
		}
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
