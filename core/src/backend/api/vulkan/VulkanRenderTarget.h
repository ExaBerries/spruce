#pragma once
#include <common.h>
#include <backend/api/vulkan/VulkanContext.h>
#include <graphics/RenderTarget.h>

namespace spruce {
	class VulkanRenderTarget : public RenderTarget {
		public:
			VulkanRenderTarget(uint16 width, uint16 height);
			VulkanRenderTarget(const VulkanRenderTarget& target) = delete;
			virtual ~VulkanRenderTarget();
	};
}
