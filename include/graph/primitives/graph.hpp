#pragma once

#include <graph/primitives/concepts.hpp>
#include <graph/primitives/tags.hpp>

namespace graphlib
{
    template <is_vertex V,
              is_edge E,
              is_container vertex_container = std::vector<typename V::ptr_t>,
              is_container edge_container = std::vector<typename E::ptr_t>,
              typename constraints = void>
    class graph
    {
    public:
        typename V::wptr_t create_vertex()
        {
            typename V::ptr_t vertex = std::make_shared<V>(vertices.size());
            add_vertex(vertex);
            return vertex;
        }
        typename V::wptr_t add_vertex(typename V::wptr_t vertex)
        {
            if (std::find(vertices.begin(), vertices.end(), vertex.lock()) ==
                vertices.end())
                std::back_inserter(vertices) = vertex.lock();
            return vertex;
        }
        typename E::wptr_t add_edge(typename V::id_t v1_id,
                                    typename V::id_t v2_id)
        {
            auto v1_it = std::find(vertices.begin(), vertices.end(), v1_id);
            auto v2_it = std::find(vertices.begin(), vertices.end(), v2_id);
            if (v1_it == vertices.end() || v2_it == vertices.end())
                return E::wptr_t();
            return add_edge(*v1_it, *v2_it);
        }
        typename E::wptr_t add_edge(typename V::wptr_t v1,
                                    typename V::wptr_t v2)
        {
            add_vertex(v1);
            add_vertex(v2);
            auto edge_it = std::find_if(edges.begin(),
                                        edges.end(),
                                        [ v1, v2 ](auto e) -> bool
                                        {
                if constexpr (std::is_base_of<directed_graph_tag,
                                              constraints>::value)
                    return e->source().lock() == v1.lock() &&
                           e->target().lock() == v2.lock();
                else
                    return (e->source().lock() == v1.lock() &&
                            e->target().lock() == v2.lock()) ||
                           (e->source().lock() == v2.lock() &&
                            e->target().lock() == v1.lock());
            });
            if (edge_it == edges.end())
            {
                typename E::ptr_t edge =
                    std::make_shared<E>(v1.lock(), v2.lock());
                std::back_inserter(edges) = edge;
                return edge;
            }

            return *edge_it;
        }
        std::size_t vertex_count() const { return vertices.size(); }

    private:
        vertex_container vertices;
        edge_container edges;
    };
} // namespace graphlib