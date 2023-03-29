#pragma once
#include "ArrayFactory.h"


namespace atlas
{
	namespace client
	{
		template<class T>
		class ArrayClient
		{

			atlas::container::ArrayFactory<T>& factory;


		public:


			ArrayClient(atlas::container::ArrayFactory<T>& factory)
				: factory(factory)
			{
			}

			void doSomethingWithArray()
			{
				auto feld = factory.createAndFill(100000000);
			}
		};
	}
}

