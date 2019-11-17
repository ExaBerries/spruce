#pragma once
#include <spruce.h>
#include <scene/cube/renderer/CubeRenderData.h>
#include <graphics/renderer/api/opengl/opengl.h>
#include <SpruceTest.h>

using namespace spruce;

namespace sprucetest {
	class Cube;

	class CubeOpenGLRenderer : public OpenGLRenderer<Cube, CubeRenderData> {
		public:
			OpenGLShader* shader;
			OpenGLShader* postShader;
			OpenGLColorRenderTarget* mainTarget;
			OpenGLColorRenderTarget* bloomTarget;
			OpenGLFramebuffer* main;

			CubeOpenGLRenderer(Application& app);
			~CubeOpenGLRenderer();

			CubeRenderData encode(Cube& encodeData) override;
			void execute(CubeRenderData& executeData) override;

			owner<MeshAPIData> createMeshAPIData(Mesh& mesh) override;
			owner<TextureAPIData> createTextureAPIData(Texture& texture) override;
	};
}
