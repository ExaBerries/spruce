#pragma once
#include <common.h>
#include <graphics/Shader.h>
#include <backend/api/vulkan/VulkanContext.h>

namespace spruce {
	class VulkanShader : public Shader {
		public:
			VkShaderModule vertShaderModule;
			VkShaderModule fragShaderModule;
			VkPipelineLayout pipelineLayout;
			VkVertexInputBindingDescription bindingDescription;
			buffer<VkVertexInputAttributeDescription> attributeDescriptions;

			VulkanShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes);
			VulkanShader(const string& vertSource, const string& fragSource, buffer<VertexAttribute> attributes);
			VulkanShader(const VulkanShader& shader) = delete;
			~VulkanShader();

			void compile(graphics::RenderPass* renderPass);

			uint16 getAttributeLocation(string name);
			void registerUniform(std::string name, ShaderUniformLocation location, uint16 index);
	};
}
