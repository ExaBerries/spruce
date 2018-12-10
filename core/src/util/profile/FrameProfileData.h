#pragma once
#ifdef DEBUG
#ifdef PROFILE
#include <common.h>

namespace spruce {
	namespace util {
		namespace profile {
			class FrameProfileData {
				public:
					uint64 encodeStartTime;
					uint64 encodeEndTime;
					uint64 executeStartTime;
					uint64 executeEndTime;
					float delta;

					FrameProfileData();
					virtual ~FrameProfileData();

					uint32 size() const;
					void serialize(uint8* data, uint32& i, uint32 size) const;
					FrameProfileData deserialize(uint8* data, uint32& i, uint32 size);
			};
		}
	}
}
#endif
#endif
