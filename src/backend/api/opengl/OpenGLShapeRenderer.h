#pragma once
#include <graphics/ShapeRenderer.h>
#include <backend/api/opengl/platform.h>

namespace spruce {
	class OpenGLShapeRenderer : public ShapeRenderer {
		public:
			const static string vert;
			const static string frag;
			const static uint16 MAX_VERTICES;
			const static uint16 MAX_INDICES;
			GLuint lineVao;
			GLuint lineVbo;
			GLuint lineIbo;
			GLuint filledVao;
			GLuint filledVbo;
			GLuint filledIbo;
			uint16 lineVertexCount;
			uint16 lineIndexCount;
			uint16 filledVertexCount;
			uint16 filledIndexCount;
			float* lineVertices;
			uint16* lineIndices;
			float* filledVertices;
			uint16* filledIndices;
			VertexAttribute* attributes;
			Shader* shader;

			OpenGLShapeRenderer();
			~OpenGLShapeRenderer();
			void begin(Camera& camera);
			void end();
			void line(vec3f a, vec3f b, color colora, color colorb);
			void rect(vec2f pos, vec2f size, color color);
	};
}
