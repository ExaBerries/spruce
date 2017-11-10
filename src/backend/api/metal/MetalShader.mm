#include <backend/api/metal/MetalShader.h>
#include <backend/api/metal/MetalContext.h>
#include <io/file.h>

namespace spruce {
	MetalShader::MetalShader(const string& vertSource, const string& fragSource, uint16 attributesCount, VertexAttribute* attributes) : Shader(vertSource, fragSource, attributesCount, attributes) {
	}

	MetalShader::~MetalShader() {
	}

	void MetalShader::compile() {
		string source = vertSource + "\n" + fragSource;
		NSString* objcSource = [NSString stringWithCString:source.c_str() encoding:[NSString defaultCStringEncoding]];
		NSError* compileError = NULL;
		library = [device newLibraryWithSource:objcSource options:nil error:&compileError];
		if (!library) {
			NSLog(@"%@", compileError);
		}
		vertexFunction = [library newFunctionWithName:@"vertexShader"];
		fragmentFunction = [library newFunctionWithName:@"fragmentShader"];
		MTLVertexDescriptor* vertexDescriptor = [MTLVertexDescriptor vertexDescriptor];
		uint8 off = 0;
		for (uint8 i = 0; i < attributeCount; i++) {
			vertexDescriptor.attributes[i].format = MTLVertexFormatFloat3;
			vertexDescriptor.attributes[i].bufferIndex = 0;
			vertexDescriptor.attributes[i].offset = off;
			off += attributes[i].size * sizeof(float);
		}
		vertexDescriptor.layouts[0].stride = off;
		vertexDescriptor.layouts[0].stepFunction = MTLVertexStepFunctionPerVertex;
		MTLRenderPipelineDescriptor* desc = [[MTLRenderPipelineDescriptor alloc] init];
		desc.label = @"Spruce Render Pipeline";
		desc.vertexFunction = vertexFunction;
		desc.fragmentFunction = fragmentFunction;
		desc.colorAttachments[0].pixelFormat = MTLPixelFormatBGRA8Unorm_sRGB;
		desc.vertexDescriptor = vertexDescriptor;
		desc.depthAttachmentPixelFormat = [view getDepthPixelFormat];
		NSError* error = NULL;
		pipelineState = [device newRenderPipelineStateWithDescriptor:desc error:&error];
		if (!pipelineState) {
			NSLog(@"%@", error);
		}
	}

	void MetalShader::enable() {
		[renderEncoder setRenderPipelineState:this->pipelineState];
	}

	void MetalShader::disable() {
	}

	uint16 MetalShader::getAttributeLocation(string name) {
		return 0;
	}

	uint16 MetalShader::registerUniform(string name, uint16 index) {
		uniformLocations[name] = index;
		return index;
	}

	void MetalShader::setUniform(string name, const int& value) {
		[renderEncoder setVertexBytes:&value length:sizeof(value) atIndex:uniformLocations[name]];
	}

	void MetalShader::setUniform(string name, const vec2i& vector) {
		vector_int2 vec = {vector.x, vector.y};
		[renderEncoder setVertexBytes:&vec length:sizeof(vec) atIndex:uniformLocations[name]];
	}

	void MetalShader::setUniform(string name, const float& value) {
		[renderEncoder setVertexBytes:&value length:sizeof(value) atIndex:uniformLocations[name]];
	}

	void MetalShader::setUniform(string name, const vec2f& vector) {
		vector_float2 vec = {vector.x, vector.y};
		[renderEncoder setVertexBytes:&vec length:sizeof(vec) atIndex:uniformLocations[name]];
	}

	void MetalShader::setUniform(string name, const vec3f& vector) {
		vector_float3 vec = {vector.x, vector.y, vector.z};
		[renderEncoder setVertexBytes:&vec length:sizeof(vec) atIndex:uniformLocations[name]];
	}

	void MetalShader::setUniform(string name, const mat4f& matrix) {
		vector_float4 r0 = {matrix.values[0],matrix.values[1],matrix.values[2],matrix.values[3]};
		vector_float4 r1 = {matrix.values[4],matrix.values[5],matrix.values[6],matrix.values[7]};
		vector_float4 r2 = {matrix.values[8],matrix.values[9],matrix.values[10],matrix.values[11]};
		vector_float4 r3 = {matrix.values[12],matrix.values[13],matrix.values[14],matrix.values[15]};
		matrix_float4x4 mat = matrix_from_rows(r0,r1,r2,r3);
		[renderEncoder setVertexBytes:&mat length:sizeof(mat) atIndex:uniformLocations[name]];
	}

	void MetalShader::setUniform(string name, const quaternion& quaternion) {
		vector_float4 quat = {quaternion.x, quaternion.y, quaternion.z, quaternion.w};
		[renderEncoder setVertexBytes:&quat length:sizeof(quat) atIndex:uniformLocations[name]];
	}

	void MetalShader::setUniform(string name, const color& color) {
		vector_float4 col = {color.r, color.g, color.b, color.a};
		[renderEncoder setVertexBytes:&col length:sizeof(col) atIndex:uniformLocations[name]];
	}
}
