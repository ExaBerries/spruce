#pragma once
#include <common.h>
#include <graphics/Mesh.h>
#include <backend/api/vulkan/VulkanContext.h>

namespace spruce {
	class VulkanMesh : public Mesh {
		public:
			VulkanContext& context;
			VkBuffer vertexBuffer;
			VkDeviceMemory vertexBufferMemory;
			VkBuffer indexBuffer;
			VkDeviceMemory indexBufferMemory;

			VulkanMesh(buffer<float> vertices, buffer<uint16> indices, VulkanContext& context);
			VulkanMesh(const VulkanMesh& mesh) = delete;
			~VulkanMesh();

			void toVRAM(Shader* shader);
			void freeVRAM();
	};
}
