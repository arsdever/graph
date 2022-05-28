#pragma once

#include <graph/primitives/concepts.hpp>

namespace graphlib
{
	template <is_graph G>
	bool is_acyclic(G& graph)
	{
        return true;
    }
}