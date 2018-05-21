#include <graphics/command/ShaderUniformCommand.h>
#include <app.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, int32 i) {
		this->type = INT32;
		this->shader = shader;
		this->name = name;
		this->location = location;
		this->i = i;
	}

	ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, float f) {
		this->type = FLOAT;
		this->shader = shader;
		this->name = name;
		this->location = location;
		this->f = f;
	}

	ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, vec2i v2i) {
		this->type = VEC2I;
		this->shader = shader;
		this->location = location;
		this->v2i = v2i;
	}

	ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, vec2f v2f) {
		this->type = VEC2F;
		this->shader = shader;
		this->name = name;
		this->location = location;
		this->v2f = v2f;
	}

	ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, vec3f v3f) {
		this->type = VEC3F;
		this->shader = shader;
		this->name = name;
		this->location = location;
		this->v3f = v3f;
	}

	ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, mat4f mat) {
		this->type = MAT4F;
		this->shader = shader;
		this->name = name;
		this->location = location;
		this->mat = mat;
	}

	ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, quaternion quat) {
		this->type = QUATERNION;
		this->shader = shader;
		this->name = name;
		this->location = location;
		this->quat = quat;
	}

	ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, color col) {
		this->type = COLOR;
		this->shader = shader;
		this->name = name;
		this->location = location;
		this->col = col;
	}

	ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, const Texture* tex) {
		this->type = TEXTURE;
		this->shader = shader;
		this->name = name;
		this->location = location;
		this->tex = tex;
	}

	ShaderUniformCommand::ShaderUniformCommand(Shader* shader, string name, Shader::ShaderUniformLocation location, const graphics::RenderPass* pass) {
		this->type = RENDERPASS;
		this->shader = shader;
		this->name = name;
		this->location = location;
		this->pass = pass;
	}

	ShaderUniformCommand::~ShaderUniformCommand() {
	}

	void ShaderUniformCommand::execute() {
		switch (type) {
			case INT32:
				app::api->setUniform(shader, name, location, i);
				break;
			case FLOAT:
				app::api->setUniform(shader, name, location, f);
				break;
			case VEC2I:
				app::api->setUniform(shader, name, location, v2i);
				break;
			case VEC2F:
				app::api->setUniform(shader, name, location, v2f);
				 break;
			case VEC3F:
				app::api->setUniform(shader, name, location, v3f);
				break;
			case MAT4F:
				app::api->setUniform(shader, name, location, mat);
				break;
			case QUATERNION:
				app::api->setUniform(shader, name, location, quat);
				break;
			case COLOR:
				app::api->setUniform(shader, name, location, col);
				break;
			case TEXTURE:
				app::api->setUniform(shader, name, location, tex);
				break;
			case RENDERPASS:
				app::api->setUniform(shader, name, location, pass);
				break;
			default:
				break;
		}
	}

	string ShaderUniformCommand::getName() {
		return "ShaderUniform";
	}
}
