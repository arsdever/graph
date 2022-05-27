#pragma once

#include <graph/primitives/concepts.hpp>

namespace graphlib
{
    class vertex
    {
    public:
        using ptr_t = shared<vertex>;
        using wptr_t = weak<vertex>;
        using uptr_t = unique<vertex>;
        using id_t = int;

    public:
        vertex(id_t id = 0)
            : _id(id)
        {
        }
        id_t id() { return _id; }

    private:
        id_t _id;
    };
} // namespace graphlib