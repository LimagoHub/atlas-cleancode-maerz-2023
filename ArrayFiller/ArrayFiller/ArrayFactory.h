#pragma once
#include "memory"
namespace atlas
{
	namespace container
	{
		template<class T>
		class ArrayFactory
		{
		public:
			virtual auto createAndFill(size_t size)->std::shared_ptr<T[]> = 0;
		};
	}
}
