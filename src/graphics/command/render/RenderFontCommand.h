#pragma once
#include <common.h>
#include <graphics/command/Command.h>
#include <graphics/color.h>
#include <math/math.h>
#include <graphics/camera/Camera.h>
#include <graphics/Font.h>

namespace spruce {
	class RenderFontCommand: public Command {
		public:
			string str;
			Font& font;
			spruce::color color;
			vec3f position;
			quaternion rotation;
			vec2f size;
			mat4f camera;

			RenderFontCommand(string str, Font& font, spruce::color color, vec3f position, quaternion rotation, vec2f size, mat4f camera);
			virtual ~RenderFontCommand();

			void execute();
			string getName() const;
	};
}
