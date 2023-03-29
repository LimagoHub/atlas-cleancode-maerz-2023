#pragma once
#include <thread>
#include <vector>
#include "ArrayFactory.h"
#include "number_generator_factory.h"

namespace atlas
{
	namespace container
	{
		template<class T>
		class ThreadedArrayFactoryImpl : public  ArrayFactory<T>
		{
			atlas::generators::number_generator_factory& numberGeneratorFactory_;
			std::size_t workerCount_;
			std::vector<std::thread> threadHolder_;
			std::size_t partitionSize_;

			auto calculatePartitionSize(size_t elementCount) -> void
			{
				partitionSize_ = static_cast<std::size_t>(std::floor(elementCount / workerCount_));
			}

			auto initializeThreadHolder()  -> void
			{
				threadHolder_ = std::vector<std::thread>{};
				threadHolder_.reserve(workerCount_);
			}

			auto addWorkersToThreads(std::shared_ptr<T[]> result)  -> void
			{
				for (auto segment = 0U; segment < workerCount_; ++segment) {
					start_single_worker_for_segment(result, segment);
				}
			}

			auto joinThreads() -> void
			{
				for (auto& thread : threadHolder_) {
					thread.join();
				}
			}

			auto  start_single_worker_for_segment(std::shared_ptr<T[]> result, const unsigned int segment) -> void
			{
				threadHolder_.emplace_back(
					[this, result](auto const startIndex, auto const endIndex) {
						this->fill_segment_worker(result, startIndex, endIndex);
					},
					segment * partitionSize_, (segment + 1) * partitionSize_);
			}

			auto fill_segment_worker(std::shared_ptr<T[]> result, std::size_t startIndex, std::size_t endIndex) -> void
			{
				auto const numberGenerator = numberGeneratorFactory_.create();

				for (auto i = startIndex; i < endIndex; ++i) {
					result[i] = numberGenerator->next_item();
					
				}
			}

		
		public:
			ThreadedArrayFactoryImpl(atlas::generators::number_generator_factory& number_generator_factory,
				std::size_t worker_count)
				: numberGeneratorFactory_(number_generator_factory),
				  workerCount_(worker_count)
			{
			}

			auto createAndFill(size_t size) -> std::shared_ptr<T[]> override
			{
				std::shared_ptr<T[]> result(new T[size]);
				calculatePartitionSize(size);
				initializeThreadHolder();
				addWorkersToThreads(result);
				joinThreads();
				return result;

			}
		};
	}
}

