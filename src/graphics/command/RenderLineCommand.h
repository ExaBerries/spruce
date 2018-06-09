#pragma once
#include <common.h>
#include <graphics/command/Command.h>
#include <math/math.h>
#include <graphics/color.h>

namespace spruce {
	class RenderLineCommand : public Command {
		public:
			vec3f a;
			vec3f b;
			color cola;
			color colb;

			RenderLineCommand(vec3f a, vec3f b, color cola, color colb);
			virtual ~RenderLineCommand();

			void execute();
			string getName();
	};
}
