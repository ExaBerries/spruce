#include <task/async.h>

namespace spruce {
	void waitForMainTasks() {
		while (task::executeMainTask()) {};
	}

	void waitForGraphicsTasks(bool concurrent) {
		while (task::executeGraphicsTask(concurrent)) {};
	}
}
