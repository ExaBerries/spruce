#pragma once

namespace spruce {
	namespace task {
		class FunctionData {
			public:
				FunctionData();
				virtual ~FunctionData();

				virtual void execute();
		};
	}
}
