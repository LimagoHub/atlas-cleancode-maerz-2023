#pragma once


#include <chrono>
#include "stopwatch.h"


namespace atlas
{


	namespace time {
		class stopwatch_impl : public stopwatch {
		public:
			void start() {
				startTime_ = std::chrono::high_resolution_clock::now();
			}

			void stop() {
				endTime_ = std::chrono::high_resolution_clock::now();
			}

			std::chrono::milliseconds elapsedDuration() {
				return std::chrono::duration_cast<std::chrono::milliseconds>(endTime_ - startTime_);
			}


		private:
			std::chrono::steady_clock::time_point startTime_;
			std::chrono::steady_clock::time_point endTime_;
		};

	}

}
