#pragma once
#include <common.h>
#include <backend/Window.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/ShapeRenderer.h>
#include <graphics/Texture.h>
#include <graphics/RenderPass.h>
#include <graphics/RenderTarget.h>
#include <graphics/Font.h>
#include <input/input.h>
#include <io/FileHandle.h>

namespace spruce {
	class RenderAPI {
		public:
			string fontVert;
			string fontFrag;
			Window* window;
			vec3f ndcSize;

			RenderAPI(Window* window, vec3f ndcSize);
			virtual ~RenderAPI();

			virtual void init() = 0;
			virtual void renderStart() = 0;
			virtual void renderEnd() = 0;

			virtual string getError() = 0;

			virtual Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) = 0;
			virtual Shader* createShader(uint8* vertData, uint16 vertDataSize, uint8* fragData, uint16 fragDataSize, uint16 attributesCount, VertexAttribute* attributes) = 0;
			virtual Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes) = 0;
			virtual ShapeRenderer* createShapeRenderer() = 0;
			virtual Texture* createTexture(const FileHandle& file) = 0;
			virtual Texture* createTexture(Texture::PixelFormat format, uint8* data, uint16 width, uint16 height) = 0;
			virtual RenderTarget* createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height) = 0;

			virtual void render(Mesh* mesh, Shader* shader) = 0;
			virtual void renderStart(graphics::RenderPass* renderPass) = 0;

			virtual void setBlend(bool value) = 0;
			virtual void setDepth(bool value) = 0;

			virtual string getGPUVendor() = 0;
			virtual uint16 getAPIVersionMajor() = 0;
			virtual uint16 getAPIVersionMinor() = 0;
			virtual string getAPIRendererName() = 0;

			virtual void setPerspective(mat4f& matrix, float& near, float& far, float& fov, float& aspectRatio) = 0;
			virtual void setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) = 0;
	};
}
