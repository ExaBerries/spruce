#include <backend/api/metal/MetalTexture.h>
#include <backend/api/metal/MetalContext.h>

namespace spruce {
	MetalTexture::MetalTexture(PixelFormat format, uint8* data, uint16& width, uint16& height) : Texture(format, data, width, height) {
	}

	MetalTexture::MetalTexture(const MetalTexture& texture) : Texture(texture) {
		this->mtlTexture = texture.mtlTexture;
	}

	MetalTexture::~MetalTexture() {
		freeVRAM();
	}

	void MetalTexture::bind() {
	}

	void MetalTexture::unbind() {
	}

	void MetalTexture::toVRAM() {
		MTLPixelFormat format = MTLPixelFormatInvalid;
		if (this->format == Texture::RGB) {
			// TODO select a RGB format for metal
		} else if (this->format == Texture::RGBA) {
			format = MTLPixelFormatRGBA32Float;
		} else if (this->format == Texture::DEPTH) {
			format = MTLPixelFormatDepth32Float;
		} else if (this->format == Texture::RED) {
			format = MTLPixelFormatR32Float;
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
		[mtlTexture release];
	}
}
