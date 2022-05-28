#pragma once

#include <graph/primitives/concepts.hpp>
#include <graph/primitives/tags.hpp>

namespace graphlib
{
    template <is_vertex V,
              is_edge E,
              typename constraints = void,
              template <typename, typename...> typename vertex_container =
                  std::vector,
              template <typename, typename...> typename edge_container =
                  std::vector>
    requires is_container<vertex_container<typename V::ptr_t>> &&
        is_container<edge_container<typename E::ptr_t>>
    class graph
    {
    public:
        using vertex_t = V;
        using edge_t = E;
        template <typename T, typename... ARGS>
        using vertex_container_t = vertex_container<T, ARGS...>;
        template <typename T, typename... ARGS>
        using edge_container_t = edge_container<T, ARGS...>;

    public:
        typename V::wptr_t create_vertex()
        {
            typename V::ptr_t vertex = std::make_shared<V>(_vertices.size());
            add_vertex(vertex);
            return vertex;
        }
        typename V::wptr_t add_vertex(typename V::wptr_t vertex)
        {
            if (std::find(_vertices.begin(), _vertices.end(), vertex.lock()) ==
                _vertices.end())
                std::back_inserter(_vertices) = vertex.lock();
            return vertex;
        }
        typename E::wptr_t add_edge(typename V::id_t v1_id,
                                    typename V::id_t v2_id)
        {
            auto v1_it = std::find(_vertices.begin(), _vertices.end(), v1_id);
            auto v2_it = std::find(_vertices.begin(), _vertices.end(), v2_id);
            if (v1_it == _vertices.end() || v2_it == _vertices.end())
                return E::wptr_t();
            return add_edge(*v1_it, *v2_it);
        }
        typename E::wptr_t add_edge(typename V::wptr_t v1,
                                    typename V::wptr_t v2)
        {
            add_vertex(v1);
            add_vertex(v2);
            auto edge_it = std::find_if(_edges.begin(),
                                        _edges.end(),
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
            if (edge_it == _edges.end())
            {
                typename E::ptr_t edge =
                    std::make_shared<E>(v1.lock(), v2.lock());
                std::back_inserter(_edges) = edge;
                return edge;
            }

            return *edge_it;
        }
        std::size_t vertex_count() const { return _vertices.size(); }
        std::size_t edge_count() const { return _edges.size(); }
        vertex_container_t<typename V::ptr_t> vertices() const
        {
            return _vertices;
        }
        edge_container_t<typename E::ptr_t> edges() const { return _edges; }
        void remove_vertex(typename V::id_t id)
        {
            auto end =
                std::remove_if(std::begin(_vertices),
                               std::end(_vertices),
                               [ &id ](auto v) { return v->id() == id; });
            std::erase(_vertices, end);
        }
        void remove_edge(typename E::id_t id)
        {
            auto end =
                std::remove_if(std::begin(_edges),
                               std::end(_edges),
                               [ &id ](auto e) { return e->id() == id; });
            std::erase(_edges, end);
        }

    private:
        vertex_container_t<typename V::ptr_t> _vertices;
        edge_container_t<typename E::ptr_t> _edges;
    };
} // namespace graphlib