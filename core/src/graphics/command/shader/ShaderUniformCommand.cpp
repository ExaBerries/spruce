#include <graphics/command/shader/ShaderUniformCommand.h>
#include <app/app.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, int32 i) {
				this->type = INT32;
				this->shader = shader;
				this->name = name;
				this->i = i;
			}

			ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, float f) {
				this->type = FLOAT;
				this->shader = shader;
				this->name = name;
				this->f = f;
			}

			ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, vec2i v2i) {
				this->type = VEC2I;
				this->shader = shader;
				this->v2i = v2i;
			}

			ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, vec2f v2f) {
				this->type = VEC2F;
				this->shader = shader;
				this->name = name;
				this->v2f = v2f;
			}

			ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, vec3f v3f) {
				this->type = VEC3F;
				this->shader = shader;
				this->name = name;
				this->v3f = v3f;
			}

			ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, mat4f mat) {
				this->type = MAT4F;
				this->shader = shader;
				this->name = name;
				this->mat = mat;
			}

			ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, quaternion quat) {
				this->type = QUATERNION;
				this->shader = shader;
				this->name = name;
				this->quat = quat;
			}

			ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, color col) {
				this->type = COLOR;
				this->shader = shader;
				this->name = name;
				this->col = col;
			}

			ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, Texture* tex) {
				this->type = TEXTURE;
				this->shader = shader;
				this->name = name;
				this->tex = tex;
			}

			ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, graphics::RenderPass* pass) {
				this->type = RENDERPASS;
				this->shader = shader;
				this->name = name;
				this->pass = pass;
			}

			ShaderUniformCommand::~ShaderUniformCommand() {
			}

			void ShaderUniformCommand::execute() {
				switch (type) {
					case INT32:
						app::api->setUniform(shader, name, i);
						break;
					case FLOAT:
						app::api->setUniform(shader, name, f);
						break;
					case VEC2I:
						app::api->setUniform(shader, name, v2i);
						break;
					case VEC2F:
						app::api->setUniform(shader, name, v2f);
						 break;
					case VEC3F:
						app::api->setUniform(shader, name, v3f);
						break;
					case MAT4F:
						app::api->setUniform(shader, name, mat);
						break;
					case QUATERNION:
						app::api->setUniform(shader, name, quat);
						break;
					case COLOR:
						app::api->setUniform(shader, name, col);
						break;
					case TEXTURE:
						app::api->setUniform(shader, name, tex);
						break;
					case RENDERPASS:
						app::api->setUniform(shader, name, pass);
						break;
					default:
						break;
				}
			}

			string ShaderUniformCommand::getName() const {
				return "ShaderUniform";
			}
		}
	}
}
