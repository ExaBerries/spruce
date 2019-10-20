#pragma once
#include <common.h>

#ifdef __APPLE__
#include <objc/objc.h>
#include <Metal/Metal.h>
#include <MetalKit/MetalKit.h>

#include <graphics/renderer/api/metal/wrapper/MetalStorageMode.h>
#include <graphics/renderer/api/metal/wrapper/MetalResourceStorageMode.h>
#include <graphics/renderer/api/metal/wrapper/MetalPrimitive.h>
#include <graphics/renderer/api/metal/wrapper/MetalIndexType.h>
#include <graphics/renderer/api/metal/wrapper/MetalVertexFormat.h>
#include <graphics/renderer/api/metal/wrapper/MetalVertexStepFunction.h>
#include <graphics/renderer/api/metal/wrapper/MetalPixelFormat.h>
#include <graphics/renderer/api/metal/wrapper/MetalLoadAction.h>
#include <graphics/renderer/api/metal/wrapper/MetalStoreAction.h>
#include <graphics/renderer/api/metal/wrapper/MetalTextureUsage.h>
#include <graphics/renderer/api/metal/wrapper/MetalCompareFunction.h>

namespace spruce {
	constexpr MTLStorageMode mapStorageMode(MetalStorageMode mode) {
		switch (mode) {
			case MetalStorageMode::SHARED:
				return MTLStorageModeShared;
			case MetalStorageMode::MANAGED:
				return MTLStorageModeManaged;
			case MetalStorageMode::PRIVATE:
				return MTLStorageModePrivate;
			default:
				return MTLStorageModeShared;
		}
	}

	constexpr MTLResourceOptions mapResourceStorageMode(MetalResourceStorageMode mode) {
		switch (mode) {
			case MetalResourceStorageMode::SHARED:
				return MTLResourceStorageModeShared;
			case MetalResourceStorageMode::MANAGED:
				return MTLResourceStorageModeManaged;
			case MetalResourceStorageMode::PRIVATE:
				return MTLResourceStorageModePrivate;
			default:
				return MTLResourceStorageModeShared;
		}
	}

	constexpr MTLPrimitiveType mapPrimitive(MetalPrimitive primitive) {
		switch (primitive) {
			case MetalPrimitive::POINT:
				return MTLPrimitiveTypePoint;
			case MetalPrimitive::LINE:
				return MTLPrimitiveTypeLine;
			case MetalPrimitive::LINE_STRIP:
				return MTLPrimitiveTypeLineStrip;
			case MetalPrimitive::TRIANGLE:
				return MTLPrimitiveTypeTriangle;
			case MetalPrimitive::TRIANGLE_STRIP:
				return MTLPrimitiveTypeTriangleStrip;
			default:
				return MTLPrimitiveTypeTriangle;
		}
	}

	constexpr MTLIndexType mapIndexType(MetalIndexType type) {
		switch (type) {
			case MetalIndexType::UINT16:
				return MTLIndexTypeUInt16;
			case MetalIndexType::UINT32:
				return MTLIndexTypeUInt32;
			default:
				return MTLIndexTypeUInt16;
		}
	}

	constexpr MTLVertexFormat mapVertexFormat(MetalVertexFormat format) {
		switch (format) {
			case MetalVertexFormat::INVALID:
				return MTLVertexFormatInvalid;
			case MetalVertexFormat::UCHAR:
				return MTLVertexFormatUChar;
			case MetalVertexFormat::UCHAR2:
				return MTLVertexFormatUChar2;
			case MetalVertexFormat::UCHAR3:
				return MTLVertexFormatUChar3;
			case MetalVertexFormat::UCHAR4:
				return MTLVertexFormatUChar4;
			case MetalVertexFormat::CHAR:
				return MTLVertexFormatChar;
			case MetalVertexFormat::CHAR2:
				return MTLVertexFormatChar2;
			case MetalVertexFormat::CHAR3:
				return MTLVertexFormatChar3;
			case MetalVertexFormat::CHAR4:
				return MTLVertexFormatChar4;
			case MetalVertexFormat::UCHARNOR:
				return MTLVertexFormatUCharNormalized;
			case MetalVertexFormat::UCHAR2NOR:
				return MTLVertexFormatUChar2Normalized;
			case MetalVertexFormat::UCHAR3NOR:
				return MTLVertexFormatUChar3Normalized;
			case MetalVertexFormat::UCHAR4NOR:
				return MTLVertexFormatUChar4Normalized;
			case MetalVertexFormat::CHARNOR:
				return MTLVertexFormatCharNormalized;
			case MetalVertexFormat::CHAR2NOR:
				return MTLVertexFormatChar2Normalized;
			case MetalVertexFormat::CHAR3NOR:
				return MTLVertexFormatChar3Normalized;
			case MetalVertexFormat::CHAR4NOR:
				return MTLVertexFormatChar4Normalized;
			case MetalVertexFormat::USHORT:
				return MTLVertexFormatUShort;
			case MetalVertexFormat::USHORT2:
				return MTLVertexFormatUShort2;
			case MetalVertexFormat::USHORT3:
				return MTLVertexFormatUShort3;
			case MetalVertexFormat::USHORT4:
				return MTLVertexFormatUShort4;
			case MetalVertexFormat::SHORT:
				return MTLVertexFormatShort;
			case MetalVertexFormat::SHORT2:
				return MTLVertexFormatShort2;
			case MetalVertexFormat::SHORT3:
				return MTLVertexFormatShort3;
			case MetalVertexFormat::SHORT4:
				return MTLVertexFormatShort4;
			case MetalVertexFormat::USHORTNOR:
				return MTLVertexFormatUShortNormalized;
			case MetalVertexFormat::USHORT2NOR:
				return MTLVertexFormatUShort2Normalized;
			case MetalVertexFormat::USHORT3NOR:
				return MTLVertexFormatUShort3Normalized;
			case MetalVertexFormat::USHORT4NOR:
				return MTLVertexFormatUShort4Normalized;
			case MetalVertexFormat::SHORTNOR:
				return MTLVertexFormatShortNormalized;
			case MetalVertexFormat::SHORT2NOR:
				return MTLVertexFormatShort2Normalized;
			case MetalVertexFormat::SHORT3NOR:
				return MTLVertexFormatShort3Normalized;
			case MetalVertexFormat::SHORT4NOR:
				return MTLVertexFormatShort4Normalized;
			case MetalVertexFormat::HALF:
				return MTLVertexFormatHalf;
			case MetalVertexFormat::HALF2:
				return MTLVertexFormatHalf2;
			case MetalVertexFormat::HALF3:
				return MTLVertexFormatHalf3;
			case MetalVertexFormat::HALF4:
				return MTLVertexFormatHalf4;
			case MetalVertexFormat::FLOAT:
				return MTLVertexFormatFloat;
			case MetalVertexFormat::FLOAT2:
				return MTLVertexFormatFloat2;
			case MetalVertexFormat::FLOAT3:
				return MTLVertexFormatFloat3;
			case MetalVertexFormat::FLOAT4:
				return MTLVertexFormatFloat4;
			case MetalVertexFormat::UINT:
				return MTLVertexFormatUInt;
			case MetalVertexFormat::UINT2:
				return MTLVertexFormatUInt2;
			case MetalVertexFormat::UINT3:
				return MTLVertexFormatUInt3;
			case MetalVertexFormat::UINT4:
				return MTLVertexFormatUInt4;
			case MetalVertexFormat::INT:
				return MTLVertexFormatInt;
			case MetalVertexFormat::INT2:
				return MTLVertexFormatInt2;
			case MetalVertexFormat::INT3:
				return MTLVertexFormatInt3;
			case MetalVertexFormat::INT4:
				return MTLVertexFormatInt4;
			case MetalVertexFormat::INT1010102NOR:
				return MTLVertexFormatInt1010102Normalized;
			case MetalVertexFormat::UINT1010102NOR:
				return MTLVertexFormatUInt1010102Normalized;
			case MetalVertexFormat::UCHAR4NOR_BGRA:
				return MTLVertexFormatUChar4Normalized_BGRA;
			default:
				return MTLVertexFormatInvalid;
		}
	}

	constexpr MTLVertexStepFunction mapVertexStepFunction(MetalVertexStepFunction function) {
		switch (function) {
			case MetalVertexStepFunction::CONSTANT:
				return MTLVertexStepFunctionConstant;
			case MetalVertexStepFunction::PER_VERTEX:
				return MTLVertexStepFunctionPerVertex;
			case MetalVertexStepFunction::PER_INSTANCE:
				return MTLVertexStepFunctionPerInstance;
			case MetalVertexStepFunction::PER_PATCH:
				return MTLVertexStepFunctionPerPatch;
			case MetalVertexStepFunction::PER_PATCH_CONTROL_POINT:
				return MTLVertexStepFunctionPerPatchControlPoint;
			default:
				return MTLVertexStepFunctionConstant;
		}
	}

	constexpr MTLPixelFormat mapPixelFormat(MetalPixelFormat format) {
		switch (format) {
			case MetalPixelFormat::INVALID:
				return MTLPixelFormatInvalid;
			case MetalPixelFormat::A8UNORM:
				return MTLPixelFormatA8Unorm;
			case MetalPixelFormat::R8UNORM:
				return MTLPixelFormatR8Unorm;
			case MetalPixelFormat::R8SNORM:
				return MTLPixelFormatR8Snorm;
			case MetalPixelFormat::R8UINT:
				return MTLPixelFormatR8Uint;
			case MetalPixelFormat::R8SINT:
				return MTLPixelFormatR8Sint;
			case MetalPixelFormat::R16UNORM:
				return MTLPixelFormatR16Unorm;
			case MetalPixelFormat::R16SNORM:
				return MTLPixelFormatR16Snorm;
			case MetalPixelFormat::R16UINT:
				return MTLPixelFormatR16Uint;
			case MetalPixelFormat::R16SINT:
				return MTLPixelFormatR16Sint;
			case MetalPixelFormat::R16FLOAT:
				return MTLPixelFormatR16Float;
			case MetalPixelFormat::RG8UNORM:
				return MTLPixelFormatRG8Unorm;
			case MetalPixelFormat::RG8SNORM:
				return MTLPixelFormatRG8Snorm;
			case MetalPixelFormat::RG8UINT:
				return MTLPixelFormatRG8Uint;
			case MetalPixelFormat::RG8SINT:
				return MTLPixelFormatRG8Sint;
			case MetalPixelFormat::R32UINT:
				return MTLPixelFormatR32Uint;
			case MetalPixelFormat::R32SINT:
				return MTLPixelFormatR32Sint;
			case MetalPixelFormat::R32FLOAT:
				return MTLPixelFormatR32Float;
			case MetalPixelFormat::RG16UNORM:
				return MTLPixelFormatRG16Unorm;
			case MetalPixelFormat::RG16SNORM:
				return MTLPixelFormatRG16Snorm;
			case MetalPixelFormat::RG16UINT:
				return MTLPixelFormatRG16Uint;
			case MetalPixelFormat::RG16SINT:
				return MTLPixelFormatRG16Sint;
			case MetalPixelFormat::RG16FLOAT:
				return MTLPixelFormatRG16Float;
			case MetalPixelFormat::RGBA8UNORM:
				return MTLPixelFormatRGBA8Unorm;
			case MetalPixelFormat::RGBA8UNORM_SRGB:
				return MTLPixelFormatRGBA8Unorm_sRGB;
			case MetalPixelFormat::RGBA8SNORM:
				return MTLPixelFormatRGBA8Snorm;
			case MetalPixelFormat::RGBA8UINT:
				return MTLPixelFormatRGBA8Uint;
			case MetalPixelFormat::RGBA8SINT:
				return MTLPixelFormatRGBA8Sint;
			case MetalPixelFormat::BGRA8UNORM:
				return MTLPixelFormatBGRA8Unorm;
			case MetalPixelFormat::BGRA8UNORM_SRGB:
				return MTLPixelFormatBGRA8Unorm_sRGB;
			case MetalPixelFormat::BGR10A2UNORM:
				return MTLPixelFormatBGR10A2Unorm;
			case MetalPixelFormat::RGB10A2UNORM:
				return MTLPixelFormatRGB10A2Unorm;
			case MetalPixelFormat::RGB10A2UINT:
				return MTLPixelFormatRGB10A2Uint;
			case MetalPixelFormat::RG11B10FLOAT:
				return MTLPixelFormatRG11B10Float;
			case MetalPixelFormat::RGB9E5FLOAT:
				return MTLPixelFormatRGB9E5Float;
			case MetalPixelFormat::RG32UINT:
				return MTLPixelFormatRG32Uint;
			case MetalPixelFormat::RG32SINT:
				return MTLPixelFormatRG32Sint;
			case MetalPixelFormat::RG32FLOAT:
				return MTLPixelFormatRG32Float;
			case MetalPixelFormat::RGBA16UNORM:
				return MTLPixelFormatRGBA16Unorm;
			case MetalPixelFormat::RGBA16SNORM:
				return MTLPixelFormatRGBA16Snorm;
			case MetalPixelFormat::RGBA16UINT:
				return MTLPixelFormatRGBA16Uint;
			case MetalPixelFormat::RGBA16SINT:
				return MTLPixelFormatRGBA16Sint;
			case MetalPixelFormat::RGBA16FLOAT:
				return MTLPixelFormatRGBA16Float;
			case MetalPixelFormat::RGBA32UINT:
				return MTLPixelFormatRGBA32Uint;
			case MetalPixelFormat::RGBA32SINT:
				return MTLPixelFormatRGBA32Sint;
			case MetalPixelFormat::RGBA32FLOAT:
				return MTLPixelFormatRGBA32Float;
			case MetalPixelFormat::BC1_RGBA:
				return MTLPixelFormatBC1_RGBA;
			case MetalPixelFormat::BC1_RGBA_SRGB:
				return MTLPixelFormatBC1_RGBA_sRGB;
			case MetalPixelFormat::BC2_RGBA:
				return MTLPixelFormatBC2_RGBA;
			case MetalPixelFormat::BC2_RGBA_SRGB:
				return MTLPixelFormatBC2_RGBA_sRGB;
			case MetalPixelFormat::BC3_RGBA:
				return MTLPixelFormatBC3_RGBA;
			case MetalPixelFormat::BC3_RGBA_SRGB:
				return MTLPixelFormatBC3_RGBA_sRGB;
			case MetalPixelFormat::BC4_RUNORM:
				return MTLPixelFormatBC4_RUnorm;
			case MetalPixelFormat::BC4_RSNORM:
				return MTLPixelFormatBC4_RSnorm;
			case MetalPixelFormat::BC5_RGUNORM:
				return MTLPixelFormatBC5_RGUnorm;
			case MetalPixelFormat::BC5_RGSNORM:
				return MTLPixelFormatBC5_RGSnorm;
			case MetalPixelFormat::BC6H_RGBFLOAT:
				return MTLPixelFormatBC6H_RGBFloat;
			case MetalPixelFormat::BC6H_RGBUFLOAT:
				return MTLPixelFormatBC6H_RGBUfloat;
			case MetalPixelFormat::BC7_RGBAUNORM:
				return MTLPixelFormatBC7_RGBAUnorm;
			case MetalPixelFormat::BC7_RGBAUNORM_SRGB:
				return MTLPixelFormatBC7_RGBAUnorm_sRGB;
			case MetalPixelFormat::GBGR422:
				return MTLPixelFormatGBGR422;
			case MetalPixelFormat::BGRG422:
				return MTLPixelFormatBGRG422;
			case MetalPixelFormat::DEPTH16UNORM:
				return MTLPixelFormatDepth16Unorm;
			case MetalPixelFormat::DEPTH32FLOAT:
				return MTLPixelFormatDepth32Float;
			case MetalPixelFormat::STENCIL8:
				return MTLPixelFormatStencil8;
			case MetalPixelFormat::DEPTH24UNORM_STENCIL8:
				return MTLPixelFormatDepth24Unorm_Stencil8;
			case MetalPixelFormat::X32_STENCIL8:
				return MTLPixelFormatX32_Stencil8;
			case MetalPixelFormat::X24_STENCIL8:
				return MTLPixelFormatX24_Stencil8;
			default:
				return MTLPixelFormatInvalid;
		}
	}

	constexpr MTLLoadAction mapLoadAction(MetalLoadAction loadAction) {
		switch (loadAction) {
			case MetalLoadAction::DONT_CARE:
				return MTLLoadActionDontCare;
			case MetalLoadAction::LOAD:
				return MTLLoadActionLoad;
			case MetalLoadAction::CLEAR:
				return MTLLoadActionClear;
			default:
				return MTLLoadActionDontCare;
		}
	}

	constexpr MTLStoreAction mapStoreAction(MetalStoreAction storeAction) {
		switch (storeAction) {
			case MetalStoreAction::DONT_CARE:
				return MTLStoreActionDontCare;
			case MetalStoreAction::STORE:
				return MTLStoreActionStore;
			case MetalStoreAction::MULTISAMPLE_RESOLVE:
				return MTLStoreActionMultisampleResolve;
			case MetalStoreAction::STORE_AND_MULTISAMPLE_RESOLVE:
				return MTLStoreActionStoreAndMultisampleResolve;
			case MetalStoreAction::UNKNOWN:
				return MTLStoreActionUnknown;
			case MetalStoreAction::CUSTOM_SAMPLE_DEPTH_STORE:
				return MTLStoreActionCustomSampleDepthStore;
			default:
				return MTLStoreActionDontCare;
		}
	}

	inline MTLTextureUsage mapTextureUsage(MetalTextureUsage usage) {
		MTLTextureUsage mtlUsage = 0;
		if ((int32)usage & (int32)MetalTextureUsage::UNKNOWN) {
			mtlUsage |= MTLTextureUsageUnknown;
		}
		if ((int32)usage & (int32)MetalTextureUsage::SHADER_READ) {
			mtlUsage |= MTLTextureUsageShaderRead;
		}
		if ((int32)usage & (int32)MetalTextureUsage::SHADER_WRITE) {
			mtlUsage |= MTLTextureUsageShaderWrite;
		}
		if ((int32)usage & (int32)MetalTextureUsage::RENDER_TARGET) {
			mtlUsage |= MTLTextureUsageRenderTarget;
		}
		if ((int32)usage & (int32)MetalTextureUsage::PIXEL_FORMAT_VIEW) {
			mtlUsage |= MTLTextureUsagePixelFormatView;
		}
		return mtlUsage;
	}

	constexpr MTLCompareFunction mapCompareFunction(MetalCompareFunction func) {
		switch (func) {
			case MetalCompareFunction::NEVER:
				return MTLCompareFunctionNever;
			case MetalCompareFunction::LESS:
				return MTLCompareFunctionLess;
			case MetalCompareFunction::EQUAL:
				return MTLCompareFunctionEqual;
			case MetalCompareFunction::LESS_EQUAL:
				return MTLCompareFunctionLessEqual;
			case MetalCompareFunction::GREATER:
				return MTLCompareFunctionGreater;
			case MetalCompareFunction::NOT_EQUAL:
				return MTLCompareFunctionNotEqual;
			case MetalCompareFunction::GREATER_EQUAL:
				return MTLCompareFunctionGreaterEqual;
			case MetalCompareFunction::ALWAYS:
				return MTLCompareFunctionAlways;
			default:
				return MTLCompareFunctionAlways;
		}
	}
}
#endif
