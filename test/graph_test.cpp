#include <stdafx.hpp>

#include <graph/primitives/edge.hpp>
#include <graph/primitives/graph.hpp>
#include <graph/primitives/vertex.hpp>
#include <gtest/gtest.h>

TEST(Graph, AddVertices)
{
    using namespace graphlib;
    graph<vertex, edge> g;
    auto v1 = g.create_vertex();
    auto v2 = g.create_vertex();
    EXPECT_EQ(g.vertex_count(), 2);
    g.add_vertex(v2);
    EXPECT_EQ(g.vertex_count(), 2);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}