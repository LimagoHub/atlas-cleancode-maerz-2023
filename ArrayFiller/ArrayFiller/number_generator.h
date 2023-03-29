#pragma once
#include "item_generator.h"
namespace atlas {
    namespace generators {
        class number_generator : public item_generator<std::int32_t> {
        public:
            std::int32_t next_item() const  override = 0;
        };
    }
}
