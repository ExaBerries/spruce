#pragma once
#include <common.h>
#include <graphics/CommandBuffer.h>
#include <thread>

namespace spruce {
	class Frame {
		public:
			std::vector<CommandBuffer> commandBuffers;
			#ifdef DEBUG
			#ifdef PROFILE
			uint64 encodeStartTime;
			uint64 encodeEndTime;
			uint64 executeStartTime;
			uint64 executeEndTime;
			float delta;
			#endif
			#endif

			Frame();
			Frame(const Frame& frame);
			virtual ~Frame();

			CommandBuffer& getCommandBuffer();

			Frame& operator=(Frame frame);
	};
}
