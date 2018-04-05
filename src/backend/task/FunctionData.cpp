#include <backend/task/FunctionData.h>
#include <common.h>

namespace spruce {
	namespace task {
		FunctionData::FunctionData() {
		}

		FunctionData::~FunctionData() {
		}

		void FunctionData::execute() {
			slog("empty task");
		}
	}
}
