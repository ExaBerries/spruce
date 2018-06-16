#include <util/profile/FrameProfileData.h>

namespace spruce {
	namespace util {
		namespace profile {
			FrameProfileData::FrameProfileData() {
				startTime = 0;
				endTime = 0;
				delta = 0;
			}

			FrameProfileData::~FrameProfileData() {
			}

			uint32 FrameProfileData::size() {
				return sizeof(uint64) + sizeof(uint64) + sizeof(float);
			}

			void FrameProfileData::serialize(uint8* data, uint32& i, uint32 size) {
				memcpy(data + i, &startTime, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(data + i, &endTime, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(data + i, &delta, sizeof(float));
				i += sizeof(float);
			}

			FrameProfileData FrameProfileData::deserialize(uint8* data, uint32& i, uint32 size) {
				FrameProfileData taskData;
				memcpy(&startTime, data + i, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(&endTime, data + i, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(&delta, data + i, sizeof(float));
				i += sizeof(float);
				return taskData;
			}
		}
	}
}
