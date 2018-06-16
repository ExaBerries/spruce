#pragma once

#ifdef DEBUG
#ifdef PROFILE
#include <common.h>
#include <io/FileHandle.h>
#include <util/profile/ProfileData.h>

namespace spruce {
	namespace util {
		namespace profile {
			extern ProfileData data;
			extern std::mutex dataMutex;
			extern FileHandle saveFile;

			ProfileData loadProfiledata(FileHandle file);
			void saveProfileData(ProfileData profileData, FileHandle file);
		}
	}
}
#else
#warning included __FILE__ when PROFILE is undefined
#endif
#else
#ifdef PROFILE
#warning PROFILE is defined but DEBUG is not, define DEBUG to use profiling
#endif
#endif
