#include <stdafx.hpp>

#include <graph/primitives/graph.hpp>

#include "helper.hpp"

int main(int argc, char** argv)
{
    auto args = parse_args(argc, argv);

    struct vtx
    {
        using ptr_t = graph::shared<vtx>;
        using wptr_t = graph::weak<vtx>;
        using uptr_t = graph::unique<vtx>;
        using id_t = int;
        id_t id() { return 0; }
    };

    struct edg
    {
        using ptr_t = graph::shared<edg>;
        using wptr_t = graph::weak<edg>;
        using uptr_t = graph::unique<edg>;
        using id_t = int;
        using source_t = vtx::ptr_t;
        using target_t = vtx::ptr_t;
        id_t id() { return 0; }
        source_t source() { return nullptr; }
        target_t target() { return nullptr; }
    };

    graph::graph<vtx, edg> graph;

    return 0;
}