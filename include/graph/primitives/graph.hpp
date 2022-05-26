#pragma once

#include <graph/primitives/edge.hpp>
#include <graph/primitives/vertex.hpp>

namespace graph
{
    template <is_vertex V,
              is_edge E,
              is_container vertex_container = std::vector<V>,
              is_container edge_container = std::vector<E>>
    class graph
    {
    public:
        graph() { }

    private:
        vertex_container vertices;
        edge_container edges;
    };
} // namespace graph