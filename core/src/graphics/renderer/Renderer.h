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
		template <typename EncodeT, typename ExecuteT, enum app::API api>
		class Renderer : public RendererAbstractor {
			public:
				Renderer() = default;
				Renderer(const Renderer&) = default;
				Renderer(Renderer&&) noexcept = default;
				virtual ~Renderer() = default;

				std::any encodeBackend(void* encodeData) {
					return encode(*((EncodeT*)encodeData));
				}

				void executeBackend(std::any executeData) {
					ExecuteT executeDataCasted = std::any_cast<ExecuteT>(executeData);
					execute(executeDataCasted);
				}

				virtual ExecuteT encode(EncodeT& encodeData) = 0;
				virtual void execute(ExecuteT& executeData) = 0;

				virtual MeshAPIData* createMeshAPIData(Mesh& mesh) = 0;
				virtual TextureAPIData* createTextureAPIData(Texture& texture) = 0;

				Renderer& operator=(const Renderer&) = default;
				Renderer& operator=(Renderer&&) noexcept = default;
		};
	}

	using graphics::Renderer;
}
