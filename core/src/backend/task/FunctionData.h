#pragma once
#include <types.h>

namespace spruce {
	namespace task {
		class FunctionData {
			public:
				FunctionData() = default;
				FunctionData(const FunctionData&) = delete;
				FunctionData(FunctionData&&) noexcept = delete;
				virtual ~FunctionData() = default;

				virtual void execute();

				FunctionData& operator=(const FunctionData&) = delete;
				FunctionData& operator=(FunctionData&&) noexcept = delete;
		};
	}
}
