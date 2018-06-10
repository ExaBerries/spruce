#include <backend/api/metal/MetalTexture.h>
#include <backend/api/metal/MetalContext.h>

namespace spruce {
	MetalTexture::MetalTexture(PixelFormat format, buffer<uint8> data, uint16& width, uint16& height) : Texture(format, data, width, height) {
	}

	MetalTexture::~MetalTexture() {
		freeVRAM();
	}

	void MetalTexture::toVRAM() {
		MTLPixelFormat format = MTLPixelFormatInvalid;
		switch (this->format) {
			case RGB:
				format = MTLPixelFormatRGBA32Float; // TODO select a proper RGB format for metal, currently interpreted as RGBA
				break;
			case RGBA:
				format = MTLPixelFormatRGBA32Float;
				break;
			case DEPTH:
				format = MTLPixelFormatDepth32Float;
				break;
			case RED:
				format = MTLPixelFormatR32Float;
				break;
			default:
				format = MTLPixelFormatInvalid;
				break;
		}
		MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:format width:this->width height:this->height mipmapped:NO];
		if (this->format == Texture::DEPTH) {
			desc.resourceOptions = MTLResourceStorageModePrivate;
			desc.storageMode = MTLStorageModePrivate;
			desc.usage = MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead;
		} else {
			desc.storageMode = MTLStorageModeManaged;
		}
		mtlTexture = [device newTextureWithDescriptor:desc];
		if (data != nullptr) {
			uint16 bytesPerRow = 0;
			bytesPerRow = width;
			if (this->format == Texture::RGB) {
				bytesPerRow *= 0;
			} else if (this->format == Texture::RGBA) {
				bytesPerRow *= sizeof(float);
			} else if (this->format == Texture::DEPTH) {
				bytesPerRow *= sizeof(float);
			} else if (this->format == Texture::RED) {
				bytesPerRow *= sizeof(float);
			}
			[mtlTexture replaceRegion:MTLRegionMake2D(0, 0, this->width, this->height) mipmapLevel:0 withBytes:this->data bytesPerRow:bytesPerRow];
		}
	}

	void MetalTexture::freeVRAM() {
		if (mtlTexture != nil) {
			[mtlTexture release];
			mtlTexture = nil;
		}
	}
}
