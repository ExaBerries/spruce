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

				explicit OpenGLRenderer(Application& app);
				OpenGLRenderer(const OpenGLRenderer&) = delete;
				OpenGLRenderer(OpenGLRenderer&&) = delete;
				~OpenGLRenderer() override = default;

				void setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) override;
				void setPerspective(mat4f& matrix, float near, float far, float fov, float aspectRatio) override;

				OpenGLRenderer& operator=(const OpenGLRenderer&) = delete;
				OpenGLRenderer& operator=(OpenGLRenderer&&) = delete;
		};

		template <typename EncodeT, typename ExecuteT>
		OpenGLRenderer<EncodeT, ExecuteT>::OpenGLRenderer(Application& app) : context(*static_cast<OpenGLContext*>(app.engine.apiContext)) {
		}

		template <typename EncodeT, typename ExecuteT>
		void OpenGLRenderer<EncodeT, ExecuteT>::setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) {
			matrix.values[0] = 2.0f / (right - left);
			matrix.values[1] = 0.0f;
			matrix.values[2] = 0.0f;
			matrix.values[3] = (left + right) / (left - right);
			matrix.values[4] = 0.0f;
			matrix.values[5] = 2.0f / (top - bottom);
			matrix.values[6] = 0.0f;
			matrix.values[7] = (top + bottom) / (bottom - top);
			matrix.values[8] = 0.0f;
			matrix.values[9] = 0.0f;
			matrix.values[10] = 2.0f / (near - far);
			matrix.values[11] = near / (near - far);
			matrix.values[12] = 0.0f;
			matrix.values[13] = 0.0f;
			matrix.values[14] = 0.0f;
			matrix.values[15] = 1.0f;
		}

		template <typename EncodeT, typename ExecuteT>
		void OpenGLRenderer<EncodeT, ExecuteT>::setPerspective(mat4f& matrix, float near, float far, float fov, float aspectRatio) {
			float size = 1.0f / tan(fov / 2.0f);
			matrix.values[0] = size / aspectRatio;
			matrix.values[1] = 0.0f;
			matrix.values[2] = 0.0f;
			matrix.values[3] = 0.0f;
			matrix.values[4] = 0.0f;
			matrix.values[5] = size;
			matrix.values[6] = 0.0f;
			matrix.values[7] = 0.0f;
			matrix.values[8] = 0.0f;
			matrix.values[9] = 0.0f;
			matrix.values[10] = (far + near) / (near - far);
			matrix.values[11] = (2.0f * far * near) / (near - far);
			matrix.values[12] = 0.0f;
			matrix.values[13] = 0.0f;
			matrix.values[14] = -1.0f;
			matrix.values[15] = 0.0f;
		}
	}

	using graphics::OpenGLRenderer;
}
