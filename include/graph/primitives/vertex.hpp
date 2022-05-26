#pragma once

#include <graph/primitives/concepts.hpp>

namespace graph
{
    class vertex
    {
    public:
        using ptr_t = shared<vertex>;
        using wptr_t = weak<vertex>;
        using uptr_t = unique<vertex>;
        using id_t = int;

    public:
        id_t id() { return 0; }
    };

} // namespace graph