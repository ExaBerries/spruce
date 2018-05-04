#pragma once
#include <backend/task/FunctionData.h>
#include <common.h>
#include <util/function.h>
#include <tuple>
#include <thread>
#ifdef DEBUG
#ifdef TASK_PROFILE
#include <system/system.h>
#include <util/task/taskprofile.h>
#endif
#endif

namespace spruce {
	namespace task {
		#ifdef DEBUG
		#ifdef TASK_PROFILE
		uint8 convert(std::thread::id id);
		#endif
		#endif

		template <typename OUTPUT, typename ... ARGS>
		class FunctionDataTemplate : public FunctionData {
			public:
				OUTPUT* output;
				std::function<OUTPUT(ARGS...)> function;
				std::tuple<ARGS...> args;
				uint64 taskId;

				FunctionDataTemplate(OUTPUT* output, std::function<OUTPUT(ARGS...)> function, std::tuple<ARGS...> args, uint64 taskId) : args(args) {
					this->output = output;
					this->function = function;
					this->taskId = taskId;
				}

				~FunctionDataTemplate() {
				}

				void execute() {
					#ifdef DEBUG
					#ifdef TASK_PROFILE
					util::task::TaskProfileData data;
					data.startTime = sys::timeNano();
					data.thread = convert(std::this_thread::get_id());
					data.taskId = taskId;
					#endif
					#endif
					(*output) = util::execute(function, args);
					#ifdef DEBUG
					#ifdef TASK_PROFILE
					util::task::dataMutex.lock();
					data.endTime = sys::timeNano();
					util::task::data.profiles.push_back(data);
					util::task::dataMutex.unlock();
					#endif
					#endif
				}
		};

		template <typename ... ARGS>
		class FunctionDataTemplate<void, ARGS...> : public FunctionData {
			public:
				bool* output;
				std::function<void(ARGS...)> function;
				std::tuple<ARGS...> args;
				uint64 taskId;

				FunctionDataTemplate(bool* output, std::function<void(ARGS...)> function, std::tuple<ARGS...> args, uint64 taskId) : args(args) {
					this->output = output;
					this->function = function;
					this->taskId = taskId;
				}

				~FunctionDataTemplate() {
				}

				void execute() {
					#ifdef DEBUG
					#ifdef TASK_PROFILE
					util::task::TaskProfileData data;
					data.startTime = sys::timeNano();
					data.thread = convert(std::this_thread::get_id());
					#endif
					#endif
					util::execute(function, args);
					#ifdef DEBUG
					#ifdef TASK_PROFILE
					util::task::dataMutex.lock();
					data.endTime = sys::timeNano();
					util::task::data.profiles.push_back(data);
					util::task::dataMutex.unlock();
					#endif
					#endif
				}
		};
	}
}
