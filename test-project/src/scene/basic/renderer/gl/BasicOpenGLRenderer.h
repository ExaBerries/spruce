#pragma once
#include <spruce.h>
#include <graphics/renderer/api/opengl/opengl.h>
#include <scene/basic/renderer/BasicRendererData.h>
#include <SpruceTest.h>

using namespace spruce;

namespace sprucetest {
	class Basic;

	class BasicOpenGLRenderer : public OpenGLRenderer<Basic, BasicRendererData> {
		public:
			OpenGLShader* shader;

			BasicOpenGLRenderer(Application& app);
			~BasicOpenGLRenderer();

			BasicRendererData encode(Basic& encodeData) override;
			void execute(BasicRendererData& executeData) override;

			owner<MeshAPIData> createMeshAPIData(Mesh& mesh) override;
			owner<TextureAPIData> createTextureAPIData(Texture& texture) override;
	};
}
