#include <backend/api/metal/MetalShader.h>
#include <backend/api/metal/MetalContext.h>
#include <backend/api/metal/MetalTexture.h>
#include <backend/api/metal/MetalRenderTarget.h>
#include <backend/mac/objcpp.h>
#include <io/file.h>

namespace spruce {
	MetalShader::MetalShader(uint8* vertData, uint16 vertDataSize, uint8* fragData, uint16 fragDataSize, uint16 attributeCount, VertexAttribute* attributes) : Shader(vertData, vertDataSize, fragData, fragDataSize, attributeCount, attributes) {
	}

	MetalShader::MetalShader(const string& vertSource, const string& fragSource, uint16 attributesCount, VertexAttribute* attributes) : Shader(vertSource, fragSource, attributesCount, attributes) {
	}

	MetalShader::~MetalShader() {
		[pipelineState release];
		[library release];
		[vertexFunction release];
		[fragmentFunction release];
	}

	void MetalShader::compileData() {
		NSError* compileError = NULL;
		dispatch_data_t data = dispatch_data_create(vertData, vertDataSize, dispatch_get_main_queue(), DISPATCH_DATA_DESTRUCTOR_DEFAULT);
		library = [device newLibraryWithData:data error:&compileError];
		if (!library) {
			NSLog(@"%@", compileError);
		}
	}

	void MetalShader::compileSource() {
		string source = vertSource + "\n" + fragSource;
		NSString* objcSource = convertStr(source);
		NSError* compileError = NULL;
		library = [device newLibraryWithSource:objcSource options:nil error:&compileError];
		if (!library) {
			NSLog(@"%@", compileError);
		}
	}

	void MetalShader::compile(graphics::RenderPass* renderPass) {
		if (vertData == nullptr) {
			compileSource();
		} else {
			compileData();
		}
		vertexFunction = [library newFunctionWithName:@"vertexShader"];
		fragmentFunction = [library newFunctionWithName:@"fragmentShader"];
		MTLVertexDescriptor* vertexDescriptor = [MTLVertexDescriptor vertexDescriptor];
		uint8 offset = 0;
		for (uint8 i = 0; i < attributeCount; i++) {
			MTLVertexFormat format = MTLVertexFormatInvalid;
			if (attributes[i].size == 1) {
				format = MTLVertexFormatFloat;
			} else if (attributes[i].size == 2) {
				format = MTLVertexFormatFloat2;
			} else if (attributes[i].size == 3) {
				format = MTLVertexFormatFloat3;
			} else if (attributes[i].size == 4) {
				format = MTLVertexFormatFloat4;
			}
			vertexDescriptor.attributes[i].format = format;
			vertexDescriptor.attributes[i].bufferIndex = 0;
			vertexDescriptor.attributes[i].offset = offset;
			offset += attributes[i].size * sizeof(float);
		}
		vertexDescriptor.layouts[0].stride = offset;
		vertexDescriptor.layouts[0].stepFunction = MTLVertexStepFunctionPerVertex;
		MTLRenderPipelineDescriptor* desc = [[MTLRenderPipelineDescriptor alloc] init];
		desc.label = @"Spruce Render Pipeline";
		desc.vertexFunction = vertexFunction;
		desc.fragmentFunction = fragmentFunction;
		if (renderPass != nullptr && ((MetalRenderTarget*)renderPass->target)->color != nullptr) {
			desc.colorAttachments[0].pixelFormat = ((MetalRenderTarget*)renderPass->target)->color->mtlTexture.pixelFormat;
		} else {
			desc.colorAttachments[0].pixelFormat = MTLPixelFormatBGRA8Unorm_sRGB;
		}
		desc.colorAttachments[0].blendingEnabled = YES;
		desc.colorAttachments[0].rgbBlendOperation = MTLBlendOperationAdd;
		desc.colorAttachments[0].alphaBlendOperation = MTLBlendOperationAdd;
		desc.colorAttachments[0].sourceRGBBlendFactor = MTLBlendFactorSourceAlpha;
		desc.colorAttachments[0].sourceAlphaBlendFactor = MTLBlendFactorSourceAlpha;
		desc.colorAttachments[0].destinationRGBBlendFactor = MTLBlendFactorOneMinusSourceAlpha;
		desc.colorAttachments[0].destinationAlphaBlendFactor = MTLBlendFactorOneMinusSourceAlpha;
		desc.vertexDescriptor = vertexDescriptor;
		if (renderPass != nullptr) {
			desc.depthAttachmentPixelFormat = ((MetalRenderTarget*)renderPass->target)->depth->mtlTexture.pixelFormat;
		} else {
			desc.depthAttachmentPixelFormat = [view getDepthPixelFormat];
		}
		NSError* error = NULL;
		pipelineState = [device newRenderPipelineStateWithDescriptor:desc error:&error];
		if (!pipelineState) {
			NSLog(@"%@", error);
		}
		[desc release];
	}

	uint16 MetalShader::getAttributeLocation(string name) {
		return 0;
	}

	uint16 MetalShader::registerUniform(string name, uint16 index) {
		uniformLocations[name] = index;
		return index;
	}
}
