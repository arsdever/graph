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
        template <typename... ARGS>
        using adjacency_list_t = std::vector<ARGS...>;
        using id_t = int;

    public:
        vertex(id_t id = 0)
            : _id(id)
        {
        }
        id_t id() { return _id; }
        void add_adjacency(wptr_t adj) { _adjacency_list.push_back(adj); }
        adjacency_list_t<wptr_t> const& adjacency_list() const
        {
            return _adjacency_list;
        }
        bool is_adjacent_to(wptr_t other) const
        {
            return std::find_if(std::begin(_adjacency_list),
                                std::end(_adjacency_list),
                                [ other ](auto v) {
                return v.lock() == other.lock();
                   }) != _adjacency_list.end();
        }

    private:
        id_t _id;
        adjacency_list_t<wptr_t> _adjacency_list;
    };
} // namespace graphlib