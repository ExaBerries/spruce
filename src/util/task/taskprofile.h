#pragma once
#ifdef DEBUG
#ifdef TASK_PROFILE
#include <common.h>
#include <io/FileHandle.h>
#include <util/task/ProfileData.h>

namespace spruce {
	namespace util {
		namespace task {
			extern ProfileData data;
			extern std::mutex dataMutex;
			extern FileHandle saveFile;

			ProfileData loadProfiledata(FileHandle file);
			void saveProfileData(ProfileData profileData, FileHandle file);
		}
	}
}
#else
#warning included __FILE__ when TASK_PROFILE is undefined
#endif
#else
#ifdef TASK_PROFILE
#warning TASK_PROFILE is defined but DEBUG is not, define DEBUG to use task profiling
#endif
#endif
