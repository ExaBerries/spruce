#pragma once
#include <common.h>
#include <graphics/command/Command.h>
#include <graphics/Primitive.h>
#include <graphics/Shader.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			class RenderBufferCommand : public Command {
				public:
					buffer<float> vertices;
					buffer<uint16> indices;
					Shader* shader;
					graphics::Primitive primitive;

					RenderBufferCommand(buffer<float> vertices, buffer<uint16> indices, Shader* shader, graphics::Primitive primitive);
					virtual ~RenderBufferCommand();

					void execute();
					string getName() const;
			};
		}
	}
}
