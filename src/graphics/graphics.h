#pragma once
#include <common.h>
#include <graphics/Screen.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/camera/Camera.h>
#include <graphics/camera/OrthographicCamera.h>
#include <graphics/camera/PerspectiveCamera.h>
#include <graphics/Texture.h>
#include <graphics/RenderPass.h>
#include <graphics/color.h>
#include <graphics/Font.h>
#include <graphics/CommandBuffer.h>
#include <graphics/Primitive.h>
#include <io/FileHandle.h>

namespace spruce {
	namespace graphics {
		extern float delta;
		extern uint16 width;
		extern uint16 height;
		extern bool vsync;

		CommandBuffer& getCommandBuffer();
		Mesh* createMesh(buffer<float> vertices, buffer<uint16> indices);
		Shader* createShader(const FileHandle& file, buffer<VertexAttribute> attributes);
		Shader* createShader(string& vertSource, string& fragSource, buffer<VertexAttribute> attributes);
		PerspectiveCamera* createPerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, vec3f& up, vec3f& dir);
		OrthographicCamera* createOrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, vec3f& up, vec3f& dir);
		Texture* createTexture(const FileHandle& path);
		Texture* createTexture(Texture::PixelFormat format, buffer<uint8> data, uint16 width, uint16 height);
		RenderTarget* createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height);

		void render(Mesh* mesh, Shader* shader, Primitive primitive);
		void render(buffer<float> vertices, buffer<uint16> indices, Shader* shader, graphics::Primitive primitive);
		void render(RenderPass* renderPass);
		void render(string str, Font& font, color color, vec3f position, quaternion rotation, vec2f size, Camera* camera);
		void renderLine(vec3f a, vec3f b, color colora, color colorb, Camera* camera);
		void renderRect(vec3f pos, vec2f size, color color, quaternion rotation, Camera* camera);

		uint16 getWindowWidth();
		uint16 getWindowHeight();
		vec3f getNDCSize();

		string getGPUVendor();
		uint16 getAPIVersionMajor();
		uint16 getAPIVersionMinor();
		string getAPIRendererName();
	}
}
