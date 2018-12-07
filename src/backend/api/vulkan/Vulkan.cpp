#include <backend/api/vulkan/Vulkan.h>

namespace spruce {
	Vulkan::Vulkan(Window* window) : RenderAPI(window, vec3f(2, 2, 2)) {
	}

	Vulkan::~Vulkan() {
	}

	void Vulkan::init() {
	}

	void Vulkan::renderStart() {
	}

	void Vulkan::renderEnd() {
	}

	string Vulkan::getError() {
		return "";
	}

	Mesh* Vulkan::createMesh(buffer<float> vertices, buffer<uint16> indices) {
		return nullptr;
	}

	Shader* Vulkan::createShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes) {
		return nullptr;
	}

	Shader* Vulkan::createShader(string& vertSource, string& fragSource, buffer<VertexAttribute> attributes) {
		return nullptr;
	}

	Texture* Vulkan::createTexture(const FileHandle& path) {
		return nullptr;
	}

	Texture* Vulkan::createTexture(Texture::PixelFormat format, buffer<uint8> data, uint16 width, uint16 height) {
		return nullptr;
	}

	RenderTarget* Vulkan::createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height) {
		return nullptr;
	}

	void Vulkan::render(Mesh* mesh, Shader* shader, graphics::Primitive primitive) {
	}

	void Vulkan::render(buffer<float> vertices, buffer<uint16> indices, Shader* shader, graphics::Primitive primitive) {
	}

	void Vulkan::changeTarget(RenderTarget* target) {
	}

	void Vulkan::bind(Mesh* mesh) {
	}

	void Vulkan::bind(Texture* texture) {
	}

	void Vulkan::unbind(Texture* texture) {
	}

	void Vulkan::bind(Shader* shader) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const int32& value) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const vec2i& vector) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const float& value) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const vec2f& vector) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const vec3f& vector) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const mat4f& matrix) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const quaternion& quaternion) {
	}

	void Vulkan::setUniform(Shader* shader, string name, const color& color) {
	}

	void Vulkan::setUniform(Shader* shader, string name, Texture* texture) {
	}

	void Vulkan::setUniform(Shader* shader, string name, graphics::RenderPass* renderPass) {
	}

	string Vulkan::getGPUVendor() {
		return "";
	}

	uint16 Vulkan::getAPIVersionMajor() {
		return 0;
	}

	uint16 Vulkan::getAPIVersionMinor() {
		return 0;
	}

	string Vulkan::getAPIRendererName() {
		return "";
	}

	void Vulkan::setPerspective(mat4f& matrix, float& near, float& far, float& fov, float& aspectRatio) {
	}

	void Vulkan::setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) {
	}
}
