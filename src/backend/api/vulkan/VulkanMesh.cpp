#include <backend/api/vulkan/VulkanMesh.h>

namespace spruce {
	VulkanMesh::VulkanMesh(buffer<float> vertices, buffer<uint16> indices) : Mesh(vertices, indices) {
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

		if (vkCreateBuffer(device, &vertexBufferInfo, nullptr, &vertexBuffer) != VK_SUCCESS) {
			serr("failed to create vertex buffer!");
		}

		VkMemoryRequirements vertexMemRequirements;
		vkGetBufferMemoryRequirements(device, vertexBuffer, &vertexMemRequirements);

		vulkanAlloc(vertexBufferMemory, vertexMemRequirements);

		vkBindBufferMemory(device, vertexBuffer, vertexBufferMemory, 0);

		VkBufferCreateInfo indexBufferInfo = {};
		indexBufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		indexBufferInfo.size = vertices.size * sizeof(float);
		indexBufferInfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
		indexBufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

		if (vkCreateBuffer(device, &indexBufferInfo, nullptr, &indexBuffer) != VK_SUCCESS) {
			serr("failed to create index buffer!");
		}

		VkMemoryRequirements indexMemRequirements;
		vkGetBufferMemoryRequirements(device, indexBuffer, &indexMemRequirements);

		vulkanAlloc(indexBufferMemory, indexMemRequirements);

		vkBindBufferMemory(device, indexBuffer, indexBufferMemory, 0);
	}

	void VulkanMesh::freeVRAM() {
		vkDestroyBuffer(device, vertexBuffer, nullptr);
		vkFreeMemory(device, vertexBufferMemory, nullptr);
		vkDestroyBuffer(device, indexBuffer, nullptr);
		vkFreeMemory(device, indexBufferMemory, nullptr);
	}
}
