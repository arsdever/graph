#pragma once

namespace graph
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
} // namespace graph