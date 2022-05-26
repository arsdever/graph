#pragma once

#include <graph/primitives/concepts.hpp>
#include <graph/primitives/tags.hpp>

namespace graph
{
    template <is_vertex V,
              is_edge E,
              is_container vertex_container = std::vector<typename V::ptr_t>,
              is_container edge_container = std::vector<typename E::ptr_t>,
              typename constraints = void>
    class graph
    {
    public:
        graph() { }
        void add_vertex(typename V::ptr_t v)
        {
            if (std::find(vertices.begin(), vertices.end(), v) ==
                vertices.end())
                std::back_inserter(vertices) = v;
        }
        void add_edge(typename V::ptr_t v1, typename V::ptr_t v2)
        {
            add_vertex(v1);
            add_vertex(v2);
            if (std::find_if(edges.begin(),
                             edges.end(),
                             [ v1, v2 ](auto e) -> bool
                             {
                if constexpr (std::is_base_of<directed_graph_tag,
                                              constraints>::value)
                    return e->source() == v1 && e->target() == v2;
                else
                    return (e->source() == v1 && e->target() == v2) ||
                           (e->source() == v2 && e->target() == v1);
                }) == edges.end())
                std::back_inserter(edges) = std::make_shared<E>(v1, v2);
        }

    private:
        vertex_container vertices;
        edge_container edges;
    };
} // namespace graph