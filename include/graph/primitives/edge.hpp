#pragma once

#include <graph/primitives/types.hpp>

namespace graph
{
    template <typename T>
    concept is_edge = has_id<T> && defines_ptr_types<T> && requires(T t)
    {
        typename T::source_t;
        typename T::target_t;
        {
            t.source()
            } -> std::convertible_to<typename T::source_t>;
        {
            t.target()
            } -> std::convertible_to<typename T::target_t>;
    };
} // namespace graph