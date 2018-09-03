#pragma once
#include <common.h>

namespace spruce {
	class Command {
		public:
			Command();
			virtual ~Command();

			virtual void execute() = 0;
			virtual string getName() const = 0;
	};
}
