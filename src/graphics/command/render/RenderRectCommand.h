#pragma once
#include <common.h>
#include <graphics/command/Command.h>
#include <graphics/color.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			class RenderRectCommand : public Command {
				public:
					vec3f pos;
					vec2f size;
					spruce::color color;
					quaternion rotation;
					mat4f camera;

					RenderRectCommand(vec3f pos, vec2f size, spruce::color color, quaternion rotation, mat4f camera);
					virtual ~RenderRectCommand();

					void execute();
					string getName() const;
			};
		}
	}
}
