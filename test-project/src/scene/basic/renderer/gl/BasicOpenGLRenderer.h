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

			BasicRendererData encode(Basic& encodeData) noexcept override;
			void execute(BasicRendererData& executeData) noexcept override;

			owner<MeshAPIData> createMeshAPIData(Mesh& mesh) noexcept override;
			owner<TextureAPIData> createTextureAPIData(Texture& texture) noexcept override;
	};
}
