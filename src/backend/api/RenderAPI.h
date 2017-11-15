#pragma once
#include <common.h>
#include <backend/Window.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/MeshRenderer.h>
#include <graphics/ShapeRenderer.h>
#include <graphics/Texture.h>
#include <input/input.h>

namespace spruce {
	class RenderAPI {
		public:
			Window* window;

			RenderAPI(Window* window);
			virtual ~RenderAPI();
			virtual void init() = 0;
			virtual void updateStart() = 0;
			virtual void updateEnd() = 0;

			virtual Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) = 0;
			virtual Shader* createShader(uint8* vertData, uint16 vertDataSize, uint8* fragData, uint16 fragDataSize, uint16 attributesCount, VertexAttribute* attributes) = 0;
			virtual Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes) = 0;
			virtual MeshRenderer* createMeshRenderer() = 0;
			virtual ShapeRenderer* createShapeRenderer() = 0;
			virtual Texture* createTexture(string& string) = 0;

			virtual void setBlend(bool value) = 0;
			virtual void setDepth(bool value) = 0;

			virtual string getGPUVendor() = 0;
			virtual uint16 getAPIVersionMajor() = 0;
			virtual uint16 getAPIVersionMinor() = 0;
			virtual string getAPIRendererName() = 0;
	};
}
