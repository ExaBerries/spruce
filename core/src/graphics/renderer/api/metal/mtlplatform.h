#pragma once
#include <common.h>

#ifdef __APPLE__
#include <objc/objc.h>
#include <Metal/Metal.h>
#include <MetalKit/MetalKit.h>

#include <graphics/renderer/api/metal/wrapper/MetalStorageMode.h>
#include <graphics/renderer/api/metal/wrapper/MetalPrimitive.h>
#include <graphics/renderer/api/metal/wrapper/MetalIndexType.h>

namespace spruce {
	constexpr MTLResourceOptions mapMode(MetalStorageMode mode) {
		switch (mode) {
			case MetalStorageMode::STORAGE_MODE_SHARED:
				return MTLStorageModeShared;
			case MetalStorageMode::STORAGE_MODE_MANAGED:
				return MTLStorageModeManaged;
			case MetalStorageMode::STORAGE_MODE_PRIVATE:
				return MTLStorageModePrivate;
			default:
				return MTLStorageModeShared;
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
}
#endif
