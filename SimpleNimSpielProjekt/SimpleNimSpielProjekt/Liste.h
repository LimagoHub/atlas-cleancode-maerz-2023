#pragma once
namespace atlas
{
	namespace collection
	{
		template<class T>
		class Liste
		{
		public:
			virtual void add(T value)=0;
			virtual T get() = 0;
			virtual bool move_first()
			{
				if (is_empty()) return false;
				while (move_previous());
				return true;
			};
			virtual bool move_last() = 0;
			virtual bool move_next() = 0;
			virtual bool move_previous() = 0;
			virtual bool is_empty() = 0;
			virtual bool is_begin_of_list() = 0;
			virtual bool is_end_of_list() = 0;
			virtual bool remove() = 0;
			virtual void clear()
			{
				while (remove());
			};
		};
	}
}

