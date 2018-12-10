#include <backend/api/metal/MetalShader.h>
#include <backend/api/metal/MetalContext.h>
#include <backend/api/metal/MetalTexture.h>
#include <backend/api/metal/MetalRenderTarget.h>
#include <backend/mac/objcpp.h>
#include <io/file.h>
#include <app/app.h>

namespace spruce {
	MetalShader::MetalShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes, MetalContext& context) : Shader(vertData, fragData, attributes), context(context) {
	}

	MetalShader::MetalShader(const string& vertSource, const string& fragSource, buffer<VertexAttribute> attributes, MetalContext& context) : Shader(vertSource, fragSource, attributes), context(context) {
	}

	MetalShader::~MetalShader() {
		[pipelineState release];
		[library release];
		[vertexFunction release];
		[fragmentFunction release];
	}

	void MetalShader::compileData() {
		NSError* compileError = NULL;
		dispatch_data_t data = dispatch_data_create(vertData, vertData.size, nil, DISPATCH_DATA_DESTRUCTOR_DEFAULT);
		library = [context.device newLibraryWithData:data error:&compileError];
		if (!library) {
			NSLog(@"%@", compileError);
		}
		dispatch_release(data);
	}

	void MetalShader::compileSource() {
		string source = vertSource + "\n" + fragSource;
		NSString* objcSource = convertStr(source);
		NSError* compileError = NULL;
		library = [context.device newLibraryWithSource:objcSource options:nil error:&compileError];
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
		MetalRenderTarget* target = nullptr;
		if (renderPass != nullptr && renderPass->target != nullptr && ((MetalRenderTarget*)renderPass->target)->renderPassDescriptor != nullptr) {
			target = (MetalRenderTarget*) renderPass->target;
		} else {
			target = (MetalRenderTarget*) app::window->surface->target;
		}
		vertexFunction = [library newFunctionWithName:@"vertexShader"];
		fragmentFunction = [library newFunctionWithName:@"fragmentShader"];
		MTLVertexDescriptor* vertexDescriptor = [MTLVertexDescriptor vertexDescriptor];
		uint8 offset = 0;
		for (uint8 i = 0; i < attributes.size; i++) {
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
		desc.colorAttachments[0].pixelFormat = target->renderPassDescriptor.colorAttachments[0].texture.pixelFormat;
		if (desc.colorAttachments[0].pixelFormat != MTLPixelFormatInvalid) {
			desc.colorAttachments[0].blendingEnabled = YES;
			desc.colorAttachments[0].rgbBlendOperation = MTLBlendOperationAdd;
			desc.colorAttachments[0].alphaBlendOperation = MTLBlendOperationAdd;
			desc.colorAttachments[0].sourceRGBBlendFactor = MTLBlendFactorSourceAlpha;
			desc.colorAttachments[0].sourceAlphaBlendFactor = MTLBlendFactorSourceAlpha;
			desc.colorAttachments[0].destinationRGBBlendFactor = MTLBlendFactorOneMinusSourceAlpha;
			desc.colorAttachments[0].destinationAlphaBlendFactor = MTLBlendFactorOneMinusSourceAlpha;
		}
		desc.vertexDescriptor = vertexDescriptor;
		desc.depthAttachmentPixelFormat = target->renderPassDescriptor.depthAttachment.texture.pixelFormat;
		NSError* error = NULL;
		pipelineState = [context.device newRenderPipelineStateWithDescriptor:desc error:&error];
		if (!pipelineState) {
			NSLog(@"%@", error);
		}
		[desc release];
	}
}
