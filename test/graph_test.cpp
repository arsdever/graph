#include <stdafx.hpp>

#include <graph/algorithms/acyclic_check.hpp>
#include <graph/primitives/edge.hpp>
#include <graph/primitives/graph.hpp>
#include <graph/primitives/tags.hpp>
#include <graph/primitives/vertex.hpp>
#include <gtest/gtest.h>

TEST(Graph, AddVertices)
{
    using namespace graphlib;
    graph<vertex, edge> g;
    auto v1 = g.create_vertex();
    EXPECT_EQ(g.vertex_count(), 1);
    auto v2 = g.create_vertex();
    EXPECT_EQ(g.vertex_count(), 2);
    g.add_vertex(v2);
    EXPECT_EQ(g.vertex_count(), 2);
}

TEST(UndirectedGraph, AddEdges)
{
    using namespace graphlib;
    graph<vertex, edge> g;
    auto v1 = g.create_vertex();
    auto v2 = g.create_vertex();
    auto e1 = g.add_edge(v1, v2);
    EXPECT_EQ(g.edge_count(), 1);
    auto v3 = g.create_vertex();
    EXPECT_EQ(g.edge_count(), 1);
    auto e2 = g.add_edge(v1, v3);
    EXPECT_EQ(g.edge_count(), 2);
    auto e3 = g.add_edge(v2, v3);
    EXPECT_EQ(g.edge_count(), 3);
    auto e4 = g.add_edge(v3, v2);
    EXPECT_EQ(g.edge_count(), 3);
    auto e5 = g.add_edge(v3, v3);
    EXPECT_EQ(g.edge_count(), 4);
    EXPECT_TRUE(e5.lock()->is_loop());
}

TEST(UndirectedGraph, AddEdgesCheckAdjacency)
{
    using namespace graphlib;
    graph<vertex, edge> g;
    auto v1 = g.create_vertex();
    auto v2 = g.create_vertex();
    auto e1 = g.add_edge(v1, v2);
    EXPECT_TRUE(v1.lock()->is_adjacent_to(v2));
    EXPECT_TRUE(v2.lock()->is_adjacent_to(v1));
}

TEST(DirectedGraph, AddEdgesCheckAdjacency)
{
    using namespace graphlib;
    graph<vertex, edge, tags<directed_graph_tag>> g;
    auto v1 = g.create_vertex();
    auto v2 = g.create_vertex();
    auto e1 = g.add_edge(v1, v2);
    EXPECT_TRUE(v1.lock()->is_adjacent_to(v2));
    EXPECT_FALSE(v2.lock()->is_adjacent_to(v1));
    auto e2 = g.add_edge(v2, v1);
    EXPECT_TRUE(v2.lock()->is_adjacent_to(v1));
}

TEST(DirectedGraph, AddEdges)
{
    using namespace graphlib;
    graph<vertex, edge, tags<directed_graph_tag>> g;
    auto v1 = g.create_vertex();
    auto v2 = g.create_vertex();
    auto e1 = g.add_edge(v1, v2);
    EXPECT_EQ(g.edge_count(), 1);
    auto v3 = g.create_vertex();
    EXPECT_EQ(g.edge_count(), 1);
    auto e2 = g.add_edge(v1, v3);
    EXPECT_EQ(g.edge_count(), 2);
    auto e3 = g.add_edge(v2, v3);
    EXPECT_EQ(g.edge_count(), 3);
    auto e4 = g.add_edge(v3, v2);
    EXPECT_EQ(g.edge_count(), 4);
    auto e5 = g.add_edge(v3, v3);
    EXPECT_EQ(g.edge_count(), 5);
    EXPECT_TRUE(e5.lock()->is_loop());
}

TEST(UndirectedGraph, IsAcyclic)
{
    using namespace graphlib;
    graph<vertex, edge> g;
    auto v1 = g.create_vertex();
    auto v2 = g.create_vertex();
    auto v3 = g.create_vertex();
    EXPECT_FALSE(is_acyclic(g));
    auto e1 = g.add_edge(v1, v2);
    EXPECT_FALSE(is_acyclic(g));
    auto e2 = g.add_edge(v2, v3);
    EXPECT_FALSE(is_acyclic(g));
    auto e3 = g.add_edge(v3, v1);
    EXPECT_TRUE(is_acyclic(g));
    auto e4 = g.add_edge(v1, v1);
    EXPECT_TRUE(is_acyclic(g));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}