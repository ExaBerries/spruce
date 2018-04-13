#include <task/async.h>

namespace spruce {
	void waitForMainTasks() {
		while (task::executeMainTask());
	}

	void waitForGraphicsTasks() {
		while (task::executeGraphicsTask());
	}
}
