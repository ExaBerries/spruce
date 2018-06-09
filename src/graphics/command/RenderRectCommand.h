#pragma once
#include <common.h>
#include <graphics/command/Command.h>
#include <math/math.h>
#include <graphics/color.h>

namespace spruce {
	class RenderRectCommand : public Command {
		public:
			vec2f pos;
			vec2f size;
			spruce::color color;

			RenderRectCommand(vec2f pos, vec2f size, spruce::color color);
			virtual ~RenderRectCommand();

			void execute();
			string getName();
	};
}
