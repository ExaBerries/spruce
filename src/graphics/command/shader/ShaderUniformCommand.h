#pragma once
#include <common.h>
#include <graphics/command/Command.h>
#include <graphics/Shader.h>

namespace spruce {
	class ShaderUniformCommand : public Command {
		public:
			enum Type {
				INT32,
				FLOAT,
				VEC2I,
				VEC2F,
				VEC3F,
				MAT4F,
				QUATERNION,
				COLOR,
				TEXTURE,
				RENDERPASS
			};
			Type type;
			Shader* shader;
			string name;
			union {
				int32 i;
				float f;
				vec2i v2i;
				vec2f v2f;
				vec3f v3f;
				mat4f mat;
				quaternion quat;
				color col;
				Texture* tex;
				graphics::RenderPass* pass;
			};

			ShaderUniformCommand(Shader* shader, string name, int32 i);
			ShaderUniformCommand(Shader* shader, string name, float f);
			ShaderUniformCommand(Shader* shader, string name, vec2i v2i);
			ShaderUniformCommand(Shader* shader, string name, vec2f v2f);
			ShaderUniformCommand(Shader* shader, string name, vec3f v3f);
			ShaderUniformCommand(Shader* shader, string name, mat4f mat);
			ShaderUniformCommand(Shader* shader, string name, quaternion quat);
			ShaderUniformCommand(Shader* shader, string name, color col);
			ShaderUniformCommand(Shader* shader, string name, Texture* tex);
			ShaderUniformCommand(Shader* shader, string name, graphics::RenderPass* pass);
			virtual ~ShaderUniformCommand();

			void execute();
			string getName() const;
	};
}
