#pragma once

#include <graph/primitives/types.hpp>

namespace graph
{
    template <typename T>
    concept is_edge = has_id<T> && defines_ptr_types<T>;
} // namespace graph