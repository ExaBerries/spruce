#include <backend/api/vulkan/VulkanMesh.h>

namespace spruce {
	VulkanMesh::VulkanMesh(buffer<float> vertices, buffer<uint16> indices, VulkanContext& context) : Mesh(vertices, indices), context(context) {
		vertexBuffer = 0;
		indexBuffer = 0;
	}

	VulkanMesh::~VulkanMesh() {
		freeVRAM();
	}

	void VulkanMesh::toVRAM(Shader* shader) {
		VkBufferCreateInfo vertexBufferInfo = {};
		vertexBufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		vertexBufferInfo.size = vertices.size * sizeof(float);
		vertexBufferInfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
		vertexBufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

		if (vkCreateBuffer(context.device, &vertexBufferInfo, nullptr, &vertexBuffer) != VK_SUCCESS) {
			serr("failed to create vertex buffer!");
		}

		VkMemoryRequirements vertexMemRequirements;
		vkGetBufferMemoryRequirements(context.device, vertexBuffer, &vertexMemRequirements);

		vulkanAlloc(context, vertexBufferMemory, vertexMemRequirements);

		vkBindBufferMemory(context.device, vertexBuffer, vertexBufferMemory, 0);

		VkBufferCreateInfo indexBufferInfo = {};
		indexBufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		indexBufferInfo.size = vertices.size * sizeof(float);
		indexBufferInfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
		indexBufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

		if (vkCreateBuffer(context.device, &indexBufferInfo, nullptr, &indexBuffer) != VK_SUCCESS) {
			serr("failed to create index buffer!");
		}

		VkMemoryRequirements indexMemRequirements;
		vkGetBufferMemoryRequirements(context.device, indexBuffer, &indexMemRequirements);

		vulkanAlloc(context, indexBufferMemory, indexMemRequirements);

		vkBindBufferMemory(context.device, indexBuffer, indexBufferMemory, 0);
	}

	void VulkanMesh::freeVRAM() {
		vkDestroyBuffer(context.device, vertexBuffer, nullptr);
		vkFreeMemory(context.device, vertexBufferMemory, nullptr);
		vkDestroyBuffer(context.device, indexBuffer, nullptr);
		vkFreeMemory(context.device, indexBufferMemory, nullptr);
	}
}
