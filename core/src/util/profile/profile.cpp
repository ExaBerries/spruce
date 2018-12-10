
#ifdef DEBUG
#ifdef PROFILE
#include <util/profile/profile.h>
#include <util/profile/TaskProfileData.h>
#include <io/file.h>

namespace spruce {
	namespace util {
		namespace profile {
			ProfileData data;
			std::mutex dataMutex;
			FileHandle saveFile(FileHandle::EXTERNAL, "spruce/idk.stp");

			ProfileData loadProfiledata(FileHandle file) {
				ProfileData profileData;
				buffer<uint8> data = io::readFileBin(file);
				uint32 size = data.size;
				if (data[0] == 0x1) {
					uint32 i = sizeof(uint8);
					uint64 startTime = 0;
					memcpy(&startTime, data + i, sizeof(uint64));
					profileData.startTime = startTime;
					i += sizeof(uint64);
					uint32 taskProfileCount = 0;
					memcpy(&taskProfileCount, data + i, sizeof(uint32));
					i += sizeof(uint32);
					for (uint32 j = 0; j < taskProfileCount; j++) {
						TaskProfileData taskData;
						taskData.deserialize(data, i, size);
						profileData.taskProfiles.push_back(taskData);
					}
					uint32 frameTimeCount = 0;
					memcpy(&frameTimeCount, data + i, sizeof(uint32));
					i += sizeof(uint32);
					for (uint32 j = 0; j < frameTimeCount; j++) {
						FrameProfileData frameData;
						frameData.deserialize(data, i, size);
						profileData.frameProfiles.push_back(frameData);
					}
					uint32 frameCount = 0;
					memcpy(&frameCount, data + i, sizeof(uint32));
					i += sizeof(uint32);
				}
				data.free();
				return profileData;
			}

			void saveProfileData(ProfileData profileData, FileHandle file) {
				uint32 size = 0;
				size += sizeof(uint8);
				size += sizeof(uint64);
				size += sizeof(uint32);
				for (uint32 i = 0; i < profileData.taskProfiles.size(); i++) {
					size += profileData.taskProfiles[i].size();
				}
				size += sizeof(uint32);
				for (uint32 i = 0; i < profileData.frameProfiles.size(); i++) {
					size += profileData.frameProfiles[i].size();
				}
				buffer<uint8> data(size);
				uint32 i = 0;
				data[i] = 0x1;
				i += sizeof(uint8);
				memcpy(data + i, &profileData.startTime, sizeof(uint64));
				i += sizeof(uint64);
				uint32 taskProfileCount = profileData.taskProfiles.size();
				memcpy(data + i, &taskProfileCount, sizeof(uint32));
				i += sizeof(uint32);
				for (uint32 j = 0; j < profileData.taskProfiles.size(); j++) {
					profileData.taskProfiles[j].serialize(data, i, size);
				}
				uint32 frameCount = profileData.frameProfiles.size();
				memcpy(data + i, &frameCount, sizeof(uint32));
				i += sizeof(uint32);
				for (uint32 j = 0; j < profileData.frameProfiles.size(); j++) {
					profileData.frameProfiles[j].serialize(data, i, size);
				}
				io::writeFileBin(file, data);
				data.free();
			}
		}
	}
}
#endif
#endif
