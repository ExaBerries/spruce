#pragma once
#include <common.h>
#include <graphics/renderer/Renderer.h>
#include <graphics/renderer/api/opengl/opengl.h>
#include <graphics/renderer/api/opengl/OpenGLContext.h>
#include <app/Application.h>

namespace spruce {
	namespace graphics {
		template <typename AppT, typename DataT>
		class OpenGLRenderer : public Renderer<AppT, DataT, app::OPENGL> {
			public:
				OpenGLContext& context;

				explicit OpenGLRenderer(AppT& app) : context(*((OpenGLContext*)app.engine.apiContext)) {
				}

				OpenGLRenderer(const OpenGLRenderer&) = delete;
				OpenGLRenderer(OpenGLRenderer&&) = delete;
				virtual ~OpenGLRenderer() = default;

				virtual DataT encode(AppT& app) = 0;
				virtual void execute(DataT& data) = 0;

				virtual MeshAPIData* createMeshAPIData(Mesh& mesh) = 0;
				virtual TextureAPIData* createTextureAPIData(Texture& texture) = 0;

				OpenGLRenderer& operator=(const OpenGLRenderer&) = delete;
				OpenGLRenderer& operator=(OpenGLRenderer&&) = delete;
		};
	}

	using graphics::OpenGLRenderer;
}
