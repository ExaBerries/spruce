#include <graphics/command/RenderBufferCommand.h>
#include <app.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	RenderBufferCommand::RenderBufferCommand(buffer<float> vertices, buffer<uint16> indices, Shader* shader, graphics::Primitive primitive) : vertices(vertices), indices(indices) {
		this->shader = shader;
		this->primitive = primitive;
	}

	RenderBufferCommand::~RenderBufferCommand() {
	}

	void RenderBufferCommand::execute() {
		app::api->render(vertices, indices, shader, primitive);
		if (vertices != nullptr) {
			vertices.free();
		}
		if (indices != nullptr) {
			indices.free();
		}
	}

	string RenderBufferCommand::getName() {
		return "RenderBuffer";
	}
}
