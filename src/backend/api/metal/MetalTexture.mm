#include <backend/api/metal/MetalTexture.h>
#include <backend/api/metal/MetalContext.h>

namespace spruce {
	MetalTexture::MetalTexture(uint8* data, uint16& width, uint16& height, uint16& bitsPerPixel) : Texture(data, width, height, bitsPerPixel) {
	}

	MetalTexture::MetalTexture(const MetalTexture& texture) : Texture(texture) {
		this->mtlTexture = texture.mtlTexture;
	}

	MetalTexture::~MetalTexture() {
		freeVRAM();
	}

	void MetalTexture::bind(uint16 unit) {
	}

	void MetalTexture::toVRAM() {
		MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatRGBA32Float width:this->width height:this->height mipmapped:NO];
		desc.storageMode = MTLStorageModeManaged;
		mtlTexture = [device newTextureWithDescriptor:desc];
		[mtlTexture replaceRegion:MTLRegionMake2D(0, 0, this->width, this->height) mipmapLevel:0 slice:0 withBytes:this->data bytesPerRow:(this->width * this->bitsPerPixel / 8) bytesPerImage:0];
	}

	void MetalTexture::freeVRAM() {
		[mtlTexture release];
	}
}
