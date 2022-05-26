#include <stdafx.hpp>

#include <graph/primitives/edge.hpp>
#include <graph/primitives/graph.hpp>
#include <graph/primitives/vertex.hpp>

#include "helper.hpp"

int main(int argc, char** argv)
{
    auto args = parse_args(argc, argv);

    graph::graph<graph::vertex, graph::edge> graph;

    auto v1 = std::make_shared<graph::vertex>();
    auto v2 = std::make_shared<graph::vertex>();
    auto v3 = std::make_shared<graph::vertex>();

    graph.add_vertex(v1);
    graph.add_edge(v2, v3);

    return 0;
}