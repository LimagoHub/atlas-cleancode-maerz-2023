#pragma once


namespace atlas {
    namespace generators {
        template<class T>
        class item_generator {
        public:
            ~item_generator() = default;

            virtual T next_item() const = 0;
        };
    }
}