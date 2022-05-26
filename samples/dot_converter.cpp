#include <stdafx.hpp>

#include <graph/primitives/edge.hpp>
#include <graph/primitives/graph.hpp>
#include <graph/primitives/vertex.hpp>

#include "helper.hpp"

int main(int argc, char** argv)
{
    auto args = parse_args(argc, argv);

    graph::graph<graph::vertex, graph::edge> graph;

    return 0;
}