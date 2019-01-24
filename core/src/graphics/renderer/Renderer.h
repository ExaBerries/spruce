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
				virtual ~Renderer() override = default;

				std::any encodeBackend(void* encodeData) override;
				void executeBackend(std::any executeData) override;

				virtual ExecuteT encode(EncodeT& encodeData) override = 0;
				virtual void execute(ExecuteT& executeData) override = 0;

				virtual MeshAPIData* createMeshAPIData(Mesh& mesh) override = 0;
				virtual TextureAPIData* createTextureAPIData(Texture& texture) override = 0;
				virtual void setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) override = 0;
				virtual void setPerspective(mat4f& matrix, float near, float far, float fov, float aspectRatio) override = 0;

				Renderer& operator=(const Renderer&) = default;
				Renderer& operator=(Renderer&&) noexcept = default;
		};

		template <typename EncodeT, typename ExecuteT, enum app::API api>
		std::any Renderer<EncodeT, ExecuteT, api>::encodeBackend(void* encodeData) {
			return encode(*((EncodeT*)encodeData));
		}

		template <typename EncodeT, typename ExecuteT, enum app::API api>
		void Renderer<EncodeT, ExecuteT, api>::executeBackend(std::any executeData) {
			ExecuteT executeDataCasted = std::any_cast<ExecuteT>(executeData);
			execute(executeDataCasted);
		}
	}

	using graphics::Renderer;
}
