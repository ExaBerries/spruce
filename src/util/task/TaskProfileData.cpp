#ifdef DEBUG
#ifdef TASK_PROFILE
#include <util/task/TaskProfileData.h>

namespace spruce {
	namespace util {
		namespace task {
			TaskProfileData::TaskProfileData() {
				startTime = 0;
				endTime = 0;
				thread = 0;
			}

			TaskProfileData::TaskProfileData(const TaskProfileData& data) {
				this->name = data.name;
				this->startTime = data.startTime;
				this->endTime = data.endTime;
				this->thread = data.thread;
			}

			TaskProfileData::~TaskProfileData() {
			}

			uint32 TaskProfileData::size() {
				return sizeof(uint32) + name.size() + 1 + sizeof(uint64) + sizeof(uint64) + sizeof(uint8);
			}

			void TaskProfileData::serialize(uint8* data, uint32& i, uint32 size) {
				uint32 stringSize = name.size() + 1;
				memcpy(data + i, &stringSize, sizeof(uint32));
				i += sizeof(uint32);
				memcpy(data + i, name.c_str(), stringSize);
				i += stringSize;
				memcpy(data + i, &startTime, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(data + i, &endTime, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(data + i, &thread, sizeof(uint8));
				i += sizeof(uint8);
			}

			TaskProfileData TaskProfileData::deserialize(uint8* data, uint32& i, uint32 size) {
				TaskProfileData taskData;
				uint32 stringSize = 0;
				memcpy(&stringSize, data + i, sizeof(uint32));
				i += sizeof(uint32);
				this->name = string((char*) data + i);
				i += stringSize;
				memcpy(&startTime, data + i, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(&endTime, data + i, sizeof(uint64));
				i += sizeof(uint64);
				memcpy(&thread, data + i, sizeof(uint8));
				i += sizeof(uint8);
				return taskData;
			}
		}
	}
}
#endif
#endif
