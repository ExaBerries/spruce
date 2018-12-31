#pragma once
#include <common.h>
#include <graphics/renderer/RendererAbstractor.h>
#include <app/API.h>
#include <app/Application.h>
#include <graphics/MeshFwd.h>
#include <graphics/MeshAPIData.h>
#include <graphics/TextureFwd.h>
#include <graphics/TextureAPIData.h>

namespace spruce {
	namespace graphics {
		template <typename AppT, typename DataT, enum app::API api>
		class Renderer : public RendererAbstractor {
			public:
				Renderer() = default;
				Renderer(const Renderer&) = default;
				Renderer(Renderer&&) noexcept = default;
				virtual ~Renderer() = default;

				std::any encodeBackend(Application& app) {
					return encode((AppT&) app);
				}

				void executeBackend(std::any data) {
					DataT dataCasted = std::any_cast<DataT>(data);
					execute(dataCasted);
				}

				virtual DataT encode(AppT& app) = 0;
				virtual void execute(DataT& data) = 0;

				virtual MeshAPIData* createMeshAPIData(Mesh& mesh) = 0;
				virtual TextureAPIData* createTextureAPIData(Texture& texture) = 0;

				Renderer& operator=(const Renderer&) = default;
				Renderer& operator=(Renderer&&) noexcept = default;
		};
	}

	using graphics::Renderer;
}
