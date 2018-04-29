#pragma once
#ifdef DEBUG
#ifdef TASK_PROFILE
#include <common.h>

namespace spruce {
	namespace util {
		namespace task {
			class TaskProfileData {
				public:
					string name;
					uint64 startTime;
					uint64 endTime;
					uint8 thread;

					TaskProfileData();
					TaskProfileData(const TaskProfileData& data);
					virtual ~TaskProfileData();

					uint32 size();
					void serialize(uint8* data, uint32& i, uint32 size);
					TaskProfileData deserialize(uint8* data, uint32& i, uint32 size);
			};
		}
	}
}
#endif
#endif
