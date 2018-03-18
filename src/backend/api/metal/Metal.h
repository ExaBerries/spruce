#include <backend/api/RenderAPI.h>
#include <common.h>
#include <graphics/Screen.h>
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

			string getError();

			Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices);
			Shader* createShader(uint8* vertData, uint16 vertDataSize, uint8* fragData, uint16 fragDataSize, uint16 attributesCount, VertexAttribute* attributes);
			Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes);
			ShapeRenderer* createShapeRenderer();
			Texture* createTexture(string& path);
			Texture* createTexture(Texture::PixelFormat format, uint8* data, uint16 width, uint16 height);
			RenderTarget* createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height);

			void render(Mesh* mesh, Shader* shader);
			void renderStart(graphics::RenderPass* renderPass);

			void setBlend(bool value);
			void setDepth(bool value);

			string getGPUVendor();
			uint16 getAPIVersionMajor();
			uint16 getAPIVersionMinor();
			string getAPIRendererName();

			void setPerspective(mat4f& matrix, float& near, float& far, float& fov, float& aspectRatio);
			void setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far);
	};
}
