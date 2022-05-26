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
        using uptr_t = unique<edge>;
        using id_t = int;
        using source_t = typename vertex::ptr_t;
        using target_t = typename vertex::ptr_t;

    public:
        edge(source_t source, target_t target, id_t id = 0)
            : _source(source)
            , _target(target)
            , _id(id)
        {
        }
        id_t id() { return 0; }
        source_t source() { return nullptr; }
        target_t target() { return nullptr; }

    private:
        source_t _source;
        target_t _target;
        id_t _id;
    };
} // namespace graph