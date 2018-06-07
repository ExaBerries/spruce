#ifdef DEBUG
#ifdef TASK_PROFILE
#include <util/task/taskprofile.h>
#include <util/task/TaskProfileData.h>
#include <io/file.h>

namespace spruce {
	namespace util {
		namespace task {
			ProfileData data;
			std::mutex dataMutex;
			FileHandle saveFile(FileHandle::EXTERNAL, "spruce/idk.stp");

			ProfileData loadProfiledata(FileHandle file) {
				ProfileData profileData;
				buffer<uint8> data = io::readFileBin(file);
				uint32 size = data.size;
				if (data[0] == 0) {
					uint32 i = sizeof(uint8);
					uint32 profileCount = 0;
					memcpy(&profileCount, data + i, sizeof(uint32));
					i += sizeof(uint32);
					for (uint32 j = 0; j < profileCount; j++) {
						TaskProfileData taskData;
						taskData.deserialize(data, i, size);
						profileData.profiles.push_back(taskData);
					}
					uint32 frameTimeCount = 0;
					memcpy(&frameTimeCount, data + i, sizeof(uint32));
					i += sizeof(uint32);
					for (uint32 j = 0; j < frameTimeCount; j++) {
						uint64 frameTime = 0;
						memcpy(&frameTime, data + i, sizeof(uint64));
						i += sizeof(uint64);
						profileData.frameTimes.push_back(frameTime);
					}
					uint32 frameCount = 0;
					memcpy(&frameCount, data + i, sizeof(uint32));
					i += sizeof(uint32);
				}
				return profileData;
			}

			void saveProfileData(ProfileData profileData, FileHandle file) {
				uint32 size = 0;
				size += sizeof(uint8);
				size += sizeof(uint32);
				for (uint32 i = 0; i < profileData.profiles.size(); i++) {
					size += profileData.profiles[i].size();
				}
				size += sizeof(uint32);
				size += sizeof(uint64) * profileData.frameTimes.size();
				buffer<uint8> data(size);
				uint32 i = 0;
				data[i] = 0;
				i += sizeof(uint8);
				uint32 profileCount = profileData.profiles.size();
				memcpy(data + i, &profileCount, sizeof(uint32));
				i += sizeof(uint32);
				for (uint32 j = 0; j < profileData.profiles.size(); j++) {
					profileData.profiles[j].serialize(data, i, size);
				}
				uint32 frameCount = profileData.frameTimes.size();
				memcpy(data + i, &frameCount, sizeof(uint32));
				i += sizeof(uint32);
				for (uint32 j = 0; j < profileData.frameTimes.size(); j++) {
					memcpy(data + i, &profileData.frameTimes[j], sizeof(uint64));
					i += sizeof(uint64);
				}
				io::writeFileBin(file, data);
				delete[] data;
			}
		}
	}
}
#endif
#endif
