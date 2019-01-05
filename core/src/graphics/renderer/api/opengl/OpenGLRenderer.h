#pragma once
#include <common.h>
#include <graphics/renderer/Renderer.h>
#include <graphics/renderer/api/opengl/OpenGLContext.h>
#include <app/Application.h>
#include <graphics/renderer/api/opengl/glplatform.h>

namespace spruce {
	namespace graphics {
		template <typename EncodeT, typename ExecuteT>
		class OpenGLRenderer : public Renderer<EncodeT, ExecuteT, app::OPENGL> {
			public:
				OpenGLContext& context;

				explicit OpenGLRenderer(Application& app) : context(*((OpenGLContext*)app.engine.apiContext)) {
				}

				OpenGLRenderer(const OpenGLRenderer&) = delete;
				OpenGLRenderer(OpenGLRenderer&&) = delete;
				virtual ~OpenGLRenderer() = default;

				virtual ExecuteT encode(EncodeT& encodeData) = 0;
				virtual void execute(ExecuteT& executeData) = 0;

				virtual MeshAPIData* createMeshAPIData(Mesh& mesh) = 0;
				virtual TextureAPIData* createTextureAPIData(Texture& texture) = 0;

				OpenGLRenderer& operator=(const OpenGLRenderer&) = delete;
				OpenGLRenderer& operator=(OpenGLRenderer&&) = delete;
		};
	}

	using graphics::OpenGLRenderer;
}
