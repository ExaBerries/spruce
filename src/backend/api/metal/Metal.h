#include <backend/api/RenderAPI.h>
#include <common.h>
#include <graphics/graphics.h>
#include <objc/objc.h>

namespace spruce {
	namespace app {
		extern graphics::Screen* screen;
	}

	class Metal : public RenderAPI {
		public:
			Metal(Window* window);
			~Metal();

			void init();
			void updateStart();
			void updateEnd();

			Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices);
			Shader* createShader(uint8* vertData, uint16 vertDataSize, uint8* fragData, uint16 fragDataSize, uint16 attributesCount, VertexAttribute* attributes);
			Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes);
			MeshRenderer* createMeshRenderer();
			ShapeRenderer* createShapeRenderer();
			Texture* createTexture(string& path);

			void setBlend(bool value);
			void setDepth(bool value);

			string getGPUVendor();
			uint16 getAPIVersionMajor();
			uint16 getAPIVersionMinor();
			string getAPIRendererName();
	};
}
