#pragma once
#include <common.h>
#include <graphics/Screen.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/ShapeRenderer.h>
#include <graphics/Camera.h>
#include <graphics/PerspectiveCamera.h>
#include <graphics/OrthographicCamera.h>
#include <graphics/Texture.h>
#include <graphics/RenderPass.h>
#include <graphics/color.h>
#include <graphics/Font.h>
#include <graphics/CommandBuffer.h>
#include <io/FileHandle.h>

namespace spruce {
	namespace graphics {
		CommandBuffer& getCommandBuffer();
		Mesh* createMesh(buffer<float> vertices, buffer<uint16> indices);
		Shader* createShader(const FileHandle& file, buffer<VertexAttribute> attributes);
		Shader* createShader(string& vertSource, string& fragSource, buffer<VertexAttribute> attributes);
		ShapeRenderer* createShapeRenderer();
		PerspectiveCamera* createPerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, vec3f& up, vec3f& dir);
		OrthographicCamera* createOrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, vec3f& up, vec3f& dir);
		Texture* createTexture(const FileHandle& path);
		Texture* createTexture(Texture::PixelFormat format, buffer<uint8> data, uint16 width, uint16 height);
		RenderTarget* createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height);

		void render(Mesh* mesh, Shader* shader);
		void render(RenderPass* renderPass);
		void render(string str, Font& font, spruce::color color, vec3f position, quaternion rotation, vec2f size, Camera* camera);

		void setBlend(bool value);
		void setDepth(bool value);

		uint16 getWidth();
		uint16 getHeight();
		vec3f getNDCSize();

		string getGPUVendor();
		uint16 getAPIVersionMajor();
		uint16 getAPIVersionMinor();
		string getAPIRendererName();
	}
}
