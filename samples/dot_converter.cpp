#include <stdafx.hpp>

#include <graph/primitives/edge.hpp>
#include <graph/primitives/graph.hpp>
#include <graph/primitives/vertex.hpp>

#include "helper.hpp"

int main(int argc, char** argv)
{
    auto args = parse_args(argc, argv);

    graphlib::graph<graphlib::vertex, graphlib::edge> graph;

    auto v1 = graph.create_vertex();
    auto v2 = graph.create_vertex();
    auto v3 = graph.create_vertex();

    auto e1 = graph.add_edge(v2, v3);
    auto e2 = graph.add_edge(v2, v3);
    auto e3 = graph.add_edge(v3, v3);

    std::cout << e1.lock()->is_loop() << std::endl;
    std::cout << (e2.lock() == e1.lock()) << std::endl;
    std::cout << e3.lock()->is_loop() << std::endl;

    return 0;
}