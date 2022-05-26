#pragma once

#include <graph/primitives/types.hpp>

namespace graph
{
    template <typename T>
    concept is_vertex = has_id<T> && defines_ptr_types<T>;
} // namespace graph