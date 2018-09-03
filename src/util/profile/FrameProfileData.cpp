#include <util/profile/FrameProfileData.h>
#ifdef DEBUG
#ifdef PROFILE

namespace spruce {
	namespace util {
		namespace profile {
			FrameProfileData::FrameProfileData() {
				encodeStartTime = 0;
				encodeEndTime = 0;
				executeStartTime = 0;
				executeEndTime = 0;
				delta = 0;
			}

			FrameProfileData::~FrameProfileData() {
			}

			uint32 FrameProfileData::size() const {
				return sizeof(uint64) + sizeof(uint64) + sizeof(uint64) + sizeof(uint64) + sizeof(float);
			}

			void FrameProfileData::serialize(uint8* data, uint32& i, uint32 size) const {
				memcpy(data + i, &encodeStartTime, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(data + i, &encodeEndTime, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(data + i, &executeStartTime, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(data + i, &executeEndTime, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(data + i, &delta, sizeof(float));
				i += sizeof(float);
			}

			FrameProfileData FrameProfileData::deserialize(uint8* data, uint32& i, uint32 size) {
				FrameProfileData taskData;
				memcpy(&encodeStartTime, data + i, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(&encodeEndTime, data + i, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(&executeStartTime, data + i, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(&executeEndTime, data + i, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(&delta, data + i, sizeof(float));
				i += sizeof(float);
				return taskData;
			}
		}
	}
}
#endif
#endif
