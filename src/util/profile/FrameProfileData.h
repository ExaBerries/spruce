#pragma once
#include <common.h>

namespace spruce {
	namespace util {
		namespace profile {
			class FrameProfileData {
				public:
					uint64 startTime;
					uint64 endTime;
					float delta;

					FrameProfileData();
					virtual ~FrameProfileData();

					uint32 size();
					void serialize(uint8* data, uint32& i, uint32 size);
					FrameProfileData deserialize(uint8* data, uint32& i, uint32 size);
			};
		}
	}
}
