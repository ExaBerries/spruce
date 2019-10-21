#include <task/async.h>

namespace spruce {
	void waitForMainTasks() noexcept {
		while (task::executeMainTask()) {};
	}

	void waitForGraphicsTasks(bool concurrent) noexcept {
		while (task::executeGraphicsTask(concurrent)) {};
	}
}
