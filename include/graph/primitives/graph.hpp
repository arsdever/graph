#pragma once

#include <graph/primitives/edge.hpp>
#include <graph/primitives/vertex.hpp>

namespace graph
{
    template <is_vertex V,
              is_edge E,
              is_container vertex_container = std::vector<typename V::ptr_t>,
              is_container edge_container = std::vector<typename E::ptr_t>>
    class graph
    {
    public:
        graph() { }

        void add_vertex(typename V::ptr_t v)
        {
            std::back_inserter(vertices) = v;
        }
        void add_edge(typename V::ptr_t v1, typename V::ptr_t v2)
        {
            auto inserter = std::back_inserter(vertices);
            inserter = v1;
            inserter = v2;
        }

    private:
        vertex_container vertices;
        edge_container edges;
    };
} // namespace graph