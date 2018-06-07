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
			void renderStart();
			void renderEnd();

			string getError();

			Mesh* createMesh(buffer<float> vertices, buffer<uint16> indices);
			Shader* createShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes);
			Shader* createShader(string& vertSource, string& fragSource, buffer<VertexAttribute> attributes);
			ShapeRenderer* createShapeRenderer();
			Texture* createTexture(const FileHandle& path);
			Texture* createTexture(Texture::PixelFormat format, buffer<uint8> data, uint16 width, uint16 height);
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
