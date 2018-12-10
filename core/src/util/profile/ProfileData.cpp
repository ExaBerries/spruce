
#ifdef DEBUG
#ifdef PROFILE
#include <util/profile/ProfileData.h>

namespace spruce {
	namespace util {
		namespace profile {
			ProfileData::ProfileData() {
				startTime = 0;
			}

			ProfileData::~ProfileData() {
			}
		}
	}
}
#endif
#endif
