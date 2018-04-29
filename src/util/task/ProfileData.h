#pragma once
#ifdef DEBUG
#ifdef TASK_PROFILE
#include <common.h>
#include <util/task/TaskProfileData.h>

namespace spruce {
	namespace util {
		namespace task {
			class ProfileData {
				public:
					std::vector<TaskProfileData> profiles;
					std::vector<uint64> frameTimes;

					ProfileData();
					virtual ~ProfileData();
			};
		}
	}
}
#endif
#endif
