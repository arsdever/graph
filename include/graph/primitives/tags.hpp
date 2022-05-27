#pragma once

namespace graphlib
{
    struct directed_graph_tag
    {
    };

    struct undirected_graph_tag
    {
    };

    template <typename... TAGS>
    struct tags : TAGS...
    {
    };
} // namespace graphlib