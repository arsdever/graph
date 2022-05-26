#pragma once

#include <graph/primitives/concepts.hpp>
#include <graph/primitives/vertex.hpp>

namespace graph
{
    class edge
    {
    public:
        using ptr_t = shared<edge>;
        using wptr_t = weak<edge>;
        using uptr_t = graph::unique<edge>;
        using id_t = int;
        using source_t = typename vertex::ptr_t;
        using target_t = typename vertex::ptr_t;

    public:
        id_t id() { return 0; }
        source_t source() { return nullptr; }
        target_t target() { return nullptr; }
    };
} // namespace graph