#pragma once
#include <common.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			class Command {
				public:
					Command();
					virtual ~Command();

					virtual void execute() = 0;
					virtual string getName() const = 0;
			};
		}
	}

	namespace cmd = graphics::cmd;
}
