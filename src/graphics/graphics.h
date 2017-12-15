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

namespace spruce {
	namespace graphics {
		Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices);
		Shader* createShader(string path, uint16 attributesCount, VertexAttribute* attributes);
		Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes);
		ShapeRenderer* createShapeRenderer();
		PerspectiveCamera* createPerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, vec3f& up, vec3f& dir);
		OrthographicCamera* createOrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, vec3f& up, vec3f& dir);
		Texture* createTexture(string& path);
		RenderTarget* createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height);

		void render(Mesh* mesh, Shader* shader);
		void render(RenderPass* renderPass);

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
