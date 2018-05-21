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
			Shader::ShaderUniformLocation location;
			union {
				int32 i;
				float f;
				vec2i v2i;
				vec2f v2f;
				vec3f v3f;
				mat4f mat;
				quaternion quat;
				color col;
				const Texture* tex;
				const graphics::RenderPass* pass;
			};

			ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, int32 i);
			ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, float f);
			ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, vec2i v2i);
			ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, vec2f v2f);
			ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, vec3f v3f);
			ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, mat4f mat);
			ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, quaternion quat);
			ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, color col);
			ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, const Texture* tex);
			ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, const graphics::RenderPass* pass);
			virtual ~ShaderUniformCommand();

			void execute();
			string getName();
	};
}
