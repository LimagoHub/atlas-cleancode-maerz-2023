#pragma once
#include <memory>
#include "number_generator.h"
namespace atlas {
    namespace generators {
        /// This *Interface Class* uses the *Factory Method* creation design pattern.
        class number_generator_factory {

        public:

            virtual ~number_generator_factory() = default;

            [[nodiscard]] virtual auto create() const->std::unique_ptr<number_generator> = 0;
        };

    }
}