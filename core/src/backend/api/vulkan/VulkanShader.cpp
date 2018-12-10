#if defined(__linux__) || defined(__WIN32__)
#include <backend/api/vulkan/VulkanShader.h>

namespace spruce {
	VulkanShader::VulkanShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes, VulkanContext& context) : Shader(vertData, fragData, attributes), context(context) {
	}

	VulkanShader::VulkanShader(const string& vertSource, const string& fragSource, buffer<VertexAttribute> attributes, VulkanContext& context) : Shader(vertSource, fragSource, attributes), context(context) {
	}

	VulkanShader::~VulkanShader() {
		vkDestroyShaderModule(context.device, fragShaderModule, nullptr);
		vkDestroyShaderModule(context.device, vertShaderModule, nullptr);
	}

	void VulkanShader::compile(graphics::RenderPass* renderPass) {
		if (vertData == nullptr || vertSource.size() > 0 || fragSource.size() > 0) {
			serr("vulkan does not support source shaders");
		}

		VkShaderModuleCreateInfo vertCreateInfo = {};
		vertCreateInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		vertCreateInfo.codeSize = vertData.size;
		vertCreateInfo.pCode = (const uint32*) vertData;
		if (vkCreateShaderModule(context.device, &vertCreateInfo, nullptr, &vertShaderModule) != VK_SUCCESS) {
		    serr("failed to create vert shader module");
		}

		VkShaderModuleCreateInfo fragCreateInfo = {};
		fragCreateInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		fragCreateInfo.codeSize = fragData.size;
		fragCreateInfo.pCode = (const uint32*) fragData;
		if (vkCreateShaderModule(context.device, &fragCreateInfo, nullptr, &fragShaderModule) != VK_SUCCESS) {
		    serr("failed to create frag shader module");
		}

		VkPipelineShaderStageCreateInfo vertShaderStageInfo = {};
		vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
		vertShaderStageInfo.module = vertShaderModule;
		vertShaderStageInfo.pName = "main";

		VkPipelineShaderStageCreateInfo fragShaderStageInfo = {};
		fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
		fragShaderStageInfo.module = fragShaderModule;
		fragShaderStageInfo.pName = "main";

		VkPipelineShaderStageCreateInfo shaderStages[] = {vertShaderStageInfo, fragShaderStageInfo};

		this->attributeDescriptions = buffer<VkVertexInputAttributeDescription>(attributes.size);
		uint16 stride = 0;
		uint16 offset = 0;
		for (uint16 i = 0; i < attributes.size; i++) {
			attributeDescriptions[i].binding = 0;
			attributeDescriptions[i].location = getAttributeLocation(attributes[i].name);
			if (attributes[i].size == 1) {
				attributeDescriptions[i].format = VK_FORMAT_R32_SFLOAT;
			} else if (attributes[i].size == 2) {
				attributeDescriptions[i].format = VK_FORMAT_R32G32_SFLOAT;
			} else if (attributes[i].size == 3) {
				attributeDescriptions[i].format = VK_FORMAT_R32G32B32_SFLOAT;
			} else if (attributes[i].size == 4) {
				attributeDescriptions[i].format = VK_FORMAT_R32G32B32A32_SFLOAT;
			}
			attributeDescriptions[i].offset = offset;
			stride += attributes[i].size;
			offset += attributes[i].size;
		}

		bindingDescription.binding = 0;
		bindingDescription.stride = stride;
		bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

		VkPipelineVertexInputStateCreateInfo vertexInputInfo = {};
		vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		vertexInputInfo.vertexBindingDescriptionCount = 1;
		vertexInputInfo.pVertexBindingDescriptions = &bindingDescription;
		vertexInputInfo.vertexAttributeDescriptionCount = attributeDescriptions.size;
		vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions;

		VkPipelineInputAssemblyStateCreateInfo inputAssembly = {};
		inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		inputAssembly.primitiveRestartEnable = VK_FALSE;

		VkViewport viewport = {};
		viewport.x = 0.0f;
		viewport.y = 0.0f;
		viewport.width = (float) context.swapChainExtent.width;
		viewport.height = (float) context.swapChainExtent.height;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		VkRect2D scissor = {};
		scissor.offset = {0, 0};
		scissor.extent = context.swapChainExtent;

		VkPipelineViewportStateCreateInfo viewportState = {};
		viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		viewportState.viewportCount = 1;
		viewportState.pViewports = &viewport;
		viewportState.scissorCount = 1;
		viewportState.pScissors = &scissor;

		VkPipelineRasterizationStateCreateInfo rasterizer = {};
		rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		rasterizer.depthClampEnable = VK_FALSE;
		rasterizer.rasterizerDiscardEnable = VK_FALSE;
		rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
		rasterizer.lineWidth = 1.0f;
		rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
		rasterizer.frontFace = VK_FRONT_FACE_CLOCKWISE;
		rasterizer.depthBiasEnable = VK_FALSE;

		VkPipelineMultisampleStateCreateInfo multisampling = {};
		multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		multisampling.sampleShadingEnable = VK_FALSE;
		multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;

		VkPipelineColorBlendAttachmentState colorBlendAttachment = {};
		colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
		colorBlendAttachment.blendEnable = VK_FALSE;

		VkPipelineColorBlendStateCreateInfo colorBlending = {};
		colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		colorBlending.logicOpEnable = VK_FALSE;
		colorBlending.logicOp = VK_LOGIC_OP_COPY;
		colorBlending.attachmentCount = 1;
		colorBlending.pAttachments = &colorBlendAttachment;
		colorBlending.blendConstants[0] = 0.0f;
		colorBlending.blendConstants[1] = 0.0f;
		colorBlending.blendConstants[2] = 0.0f;
		colorBlending.blendConstants[3] = 0.0f;

		VkPipelineLayoutCreateInfo pipelineLayoutInfo = {};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pushConstantRangeCount = 0;

		if (vkCreatePipelineLayout(context.device, &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
			serr("failed to create pipeline layout!");
		}
	}

	uint16 VulkanShader::getAttributeLocation(string name) {
		return 0;
	}

	void VulkanShader::registerUniform(std::string name, Shader::ShaderUniformLocation location, uint16 index) {
	}
}
#endif
