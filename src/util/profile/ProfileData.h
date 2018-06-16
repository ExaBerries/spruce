#pragma once

#ifdef DEBUG
#ifdef PROFILE
#include <common.h>
#include <util/profile/TaskProfileData.h>
#include <util/profile/FrameProfileData.h>

namespace spruce {
	namespace util {
		namespace profile {
			class ProfileData {
				public:
					uint64 startTime;
					std::vector<FrameProfileData> frameProfiles;
					std::vector<TaskProfileData> taskProfiles;

					ProfileData();
					virtual ~ProfileData();
			};
		}
	}
}
#endif
#endif
