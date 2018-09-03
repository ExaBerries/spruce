#include <backend/api/metal/Metal.h>
#include <backend/api/metal/MetalContext.h>
#include <backend/api/metal/MetalMesh.h>
#include <backend/api/metal/MetalShader.h>
#include <backend/api/metal/MetalTexture.h>
#include <backend/api/metal/MetalRenderTarget.h>
#include <io/image.h>
#include <graphics/graphics.h>
#include <Metal/Metal.h>
#include <backend/mac/objcpp.h>

namespace spruce {
	Metal::Metal(Window* window) : RenderAPI(window, vec3f(2, 2, 1)) {
		fontVert =
			#include "font.metal"
		;
		fontFrag = "";
		shapeVert =
			#include "shape.metal"
		;
		shapeFrag = "";
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
		fontAttributes = buffer<VertexAttribute>(2);
		fontAttributes[0] = VertexAttribute("position", 3);
		fontAttributes[1] = VertexAttribute("texCoord", 2);
		fontShader = createShader(fontVert, fontFrag, fontAttributes);
		fontShader->compile(nullptr);
		fontShader->registerUniform("camera", Shader::VERTEX, 1);
		fontShader->registerUniform("tex", Shader::FRAGMENT, 2);
		fontShader->registerUniform("color", Shader::FRAGMENT, 3);
		shapeAttributes = buffer<VertexAttribute>(2);
		shapeAttributes[0] = VertexAttribute("position", 3);
		shapeAttributes[1] = VertexAttribute("color", 4);
		shapeShader = createShader(shapeVert, shapeFrag, shapeAttributes);
		shapeShader->compile(nullptr);
		shapeShader->registerUniform("camera", Shader::VERTEX, 1);
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
		id<CAMetalDrawable> drawable = [view getDrawable];
		if (drawable != nil) {
			[commandBuffer presentDrawable:[view getDrawable]];
		} else {
			serr("drawable is nil");
		}
		[commandBuffer commit];
		[view releaseDrawable];
		[commandBuffer release];
		[renderEncoder release];
	}

	string Metal::getError() {
		return "";
	}

	Mesh* Metal::createMesh(buffer<float> vertices, buffer<uint16> indices) {
		return new MetalMesh(vertices, indices);
	}

	Shader* Metal::createShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes) {
		return new MetalShader(vertData, fragData, attributes);
	}

	Shader* Metal::createShader(string& vert, string& frag, buffer<VertexAttribute> attributes) {
		return new MetalShader(vert, frag, attributes);
	}

	Texture* Metal::createTexture(const FileHandle& path) {
		uint16 width = 0;
		uint16 height = 0;
		uint16 bitsPerPixel = 0;
		buffer<uint8> data = io::loadImage(path, width, height, bitsPerPixel);
		return new MetalTexture(Texture::RGBA, data, width, height);
	}

	Texture* Metal::createTexture(Texture::PixelFormat format, buffer<uint8> data, uint16 width, uint16 height) {
		return new MetalTexture(format, data, width, height);
	}

	RenderTarget* Metal::createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height) {
		return new MetalRenderTarget(format, width, height);
	}

	void Metal::render(Mesh* mesh, Shader* shader, graphics::Primitive primitive) {
		MTLPrimitiveType mtlPrimitive;
		switch (primitive) {
			case graphics::TRIANGLE:
				mtlPrimitive = MTLPrimitiveTypeTriangle;
				break;
			case graphics::TRIANGLE_STRIP:
				mtlPrimitive = MTLPrimitiveTypeTriangleStrip;
				break;
			case graphics::LINE:
				mtlPrimitive = MTLPrimitiveTypeLine;
				break;
			case graphics::LINE_STRIP:
				mtlPrimitive = MTLPrimitiveTypeLineStrip;
				break;
			default:
				mtlPrimitive = MTLPrimitiveTypeTriangle;
				break;
		}
		[renderEncoder setVertexBuffer:((MetalMesh*)mesh)->vertexBuffer offset:0 atIndex:0];
		if (mesh->indices.size > 0) {
			[renderEncoder drawIndexedPrimitives:mtlPrimitive indexCount:((MetalMesh*)mesh)->indices.size indexType:MTLIndexTypeUInt16 indexBuffer:((MetalMesh*)mesh)->indexBuffer indexBufferOffset:0];
		} else {
			[renderEncoder drawPrimitives:mtlPrimitive vertexStart:0 vertexCount:mesh->vertices.size];
		}
	}

	void Metal::render(buffer<float> vertices, buffer<uint16> indices, Shader* shader, graphics::Primitive primitive) {
		id<MTLBuffer> vertexBuffer;
		id<MTLBuffer> indexBuffer;

		if (vertices.size > 0) {
			vertexBuffer = [device newBufferWithLength:(vertices.size * sizeof(float)) options:MTLResourceStorageModeManaged];
			memcpy(vertexBuffer.contents, vertices.data, vertices.size * sizeof(float));
			[vertexBuffer didModifyRange:NSMakeRange(0, vertices.size * sizeof(float))];
		} else {
			serr("no vertices to render");
			return;
		}
		if (indices.size > 0) {
			indexBuffer = [device newBufferWithLength:(indices.size * sizeof(uint16)) options:MTLResourceStorageModeManaged];
			memcpy(indexBuffer.contents, indices.data, indices.size * sizeof(uint16));
			[indexBuffer didModifyRange:NSMakeRange(0, indices.size * sizeof(uint16))];
		}

		MTLPrimitiveType mtlPrimitive;
		switch (primitive) {
			case graphics::TRIANGLE:
				mtlPrimitive = MTLPrimitiveTypeTriangle;
				break;
			case graphics::TRIANGLE_STRIP:
				mtlPrimitive = MTLPrimitiveTypeTriangleStrip;
				break;
			case graphics::LINE:
				mtlPrimitive = MTLPrimitiveTypeLine;
				break;
			case graphics::LINE_STRIP:
				mtlPrimitive = MTLPrimitiveTypeLineStrip;
				break;
			default:
				mtlPrimitive = MTLPrimitiveTypeTriangle;
				break;
		}
		[renderEncoder setVertexBuffer:vertexBuffer offset:0 atIndex:0];
		if (indices.size > 0) {
			[renderEncoder drawIndexedPrimitives:mtlPrimitive indexCount:indices.size indexType:MTLIndexTypeUInt16 indexBuffer:indexBuffer indexBufferOffset:0];
		} else {
			[renderEncoder drawPrimitives:mtlPrimitive vertexStart:0 vertexCount:vertices.size];
		}

		if (vertices.size > 0) {
			[vertexBuffer release];
		}
		if (indices.size > 0) {
			[indexBuffer release];
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

	void Metal::setUniform(Shader* shader, string name, const int32& value) {
		Shader::UniformData& uniformData = shader->uniformLocations[name];
		if (uniformData.location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&value length:sizeof(value) atIndex:uniformData.index];
		} else if (uniformData.location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&value length:sizeof(value) atIndex:uniformData.index];
		}
	}

	void Metal::setUniform(Shader* shader, string name, const vec2i& vector) {
		Shader::UniformData& uniformData = shader->uniformLocations[name];
		vector_int2 vec = {vector.x, vector.y};
		if (uniformData.location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&vec length:sizeof(vec) atIndex:uniformData.index];
		} else if (uniformData.location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&vec length:sizeof(vec) atIndex:uniformData.index];
		}
	}

	void Metal::setUniform(Shader* shader, string name, const float& value) {
		Shader::UniformData& uniformData = shader->uniformLocations[name];
		if (uniformData.location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&value length:sizeof(value) atIndex:uniformData.index];
		} else if (uniformData.location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&value length:sizeof(value) atIndex:uniformData.index];
		}
	}

	void Metal::setUniform(Shader* shader, string name, const vec2f& vector) {
		Shader::UniformData& uniformData = shader->uniformLocations[name];
		vector_float2 vec = {vector.x, vector.y};
		if (uniformData.location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&vec length:sizeof(vec) atIndex:uniformData.index];
		} else if (uniformData.location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&vec length:sizeof(vec) atIndex:uniformData.index];
		}
	}

	void Metal::setUniform(Shader* shader, string name, const vec3f& vector) {
		Shader::UniformData& uniformData = shader->uniformLocations[name];
		vector_float3 vec = {vector.x, vector.y, vector.z};
		if (uniformData.location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&vec length:sizeof(vec) atIndex:uniformData.index];
		} else if (uniformData.location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&vec length:sizeof(vec) atIndex:uniformData.index];
		}
	}

	void Metal::setUniform(Shader* shader, string name, const mat4f& matrix) {
		Shader::UniformData& uniformData = shader->uniformLocations[name];
		vector_float4 r0 = {matrix.values[0],matrix.values[1],matrix.values[2],matrix.values[3]};
		vector_float4 r1 = {matrix.values[4],matrix.values[5],matrix.values[6],matrix.values[7]};
		vector_float4 r2 = {matrix.values[8],matrix.values[9],matrix.values[10],matrix.values[11]};
		vector_float4 r3 = {matrix.values[12],matrix.values[13],matrix.values[14],matrix.values[15]};
		matrix_float4x4 mat = matrix_from_rows(r0,r1,r2,r3);
		if (uniformData.location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&mat length:sizeof(mat) atIndex:uniformData.index];
		} else if (uniformData.location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&mat length:sizeof(mat) atIndex:uniformData.index];
		}
	}

	void Metal::setUniform(Shader* shader, string name, const quaternion& quaternion) {
		Shader::UniformData& uniformData = shader->uniformLocations[name];
		vector_float4 quat = {quaternion.x, quaternion.y, quaternion.z, quaternion.w};
		if (uniformData.location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&quat length:sizeof(quat) atIndex:uniformData.index];
		} else if (uniformData.location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&quat length:sizeof(quat) atIndex:uniformData.index];
		}
	}

	void Metal::setUniform(Shader* shader, string name, const color& color) {
		Shader::UniformData& uniformData = shader->uniformLocations[name];
		vector_float4 col = {color.r, color.g, color.b, color.a};
		if (uniformData.location == Shader::VERTEX) {
			[renderEncoder setVertexBytes:&col length:sizeof(col) atIndex:uniformData.index];
		} else if (uniformData.location == Shader::FRAGMENT) {
			[renderEncoder setFragmentBytes:&col length:sizeof(col) atIndex:uniformData.index];
		}
	}

	void Metal::setUniform(Shader* shader, string name, Texture* texture) {
		Shader::UniformData& uniformData = shader->uniformLocations[name];
		if (uniformData.location == Shader::VERTEX) {
			[renderEncoder setVertexTexture:((MetalTexture*)texture)->mtlTexture atIndex:uniformData.index];
		} else if (uniformData.location == Shader::FRAGMENT) {
			[renderEncoder setFragmentTexture:((MetalTexture*)texture)->mtlTexture atIndex:uniformData.index];
		}
	}

	void Metal::setUniform(Shader* shader, string name, graphics::RenderPass* renderPass) {
		Shader::UniformData& uniformData = shader->uniformLocations[name];
		id<MTLTexture> texture;
		if (((MetalRenderTarget*)renderPass->target)->color != nullptr) {
			texture = ((MetalRenderTarget*)renderPass->target)->color->mtlTexture;
		} else {
			texture = ((MetalRenderTarget*)renderPass->target)->depth->mtlTexture;
		}
		if (uniformData.location == Shader::VERTEX) {
			[renderEncoder setVertexTexture:texture atIndex:uniformData.index];
		} else if (uniformData.location == Shader::FRAGMENT) {
			[renderEncoder setFragmentTexture:texture atIndex:uniformData.index];
		}
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
