#include <boost/graph/graph_concepts.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include <boost/pending/property.hpp>
#include <gtest/gtest.h>
#include "graph.hpp"
#include "hc.hpp"
#include "hc_tsp.hpp"

using namespace std;
using namespace boost;

TEST(HCTSP, Reduce) {
    Graph g(4);
    Edge edge_array[] = {
        Edge(0, 1),
        Edge(1, 2),
        Edge(2, 3),
        Edge(3, 0)
    };

    const int num_edges = sizeof(edge_array) / sizeof(edge_array[0]);
    ASSERT_EQ(num_edges, 4);

    for (size_t j = 0; j < num_edges; ++j) {
        typename graph_traits<Graph>::edge_descriptor ed;
        bool inserted;
        tie(ed, inserted) = add_edge(edge_array[j].first, edge_array[j].second, g);
    }

    ASSERT_EQ(4, boost::num_vertices(g));

    HC hc = HC(g);
    HCTSP hctsp = HCTSP();
    TSP tsp = hctsp.reduce(hc);

    Graph reduced = tsp.get_graph();

    graph_traits<Graph>::vertices_size_type vertices_size;
    vertices_size = boost::num_vertices(reduced);
    ASSERT_EQ(4, vertices_size);

    graph_traits<Graph>::edges_size_type num;
    num = boost::num_edges(reduced);
    ASSERT_EQ(6, num);

    graph_traits<Graph>::edge_descriptor e1, e2, e3, e4, e5, e6;
    bool found;
    graph_traits<Graph>::vertex_descriptor a, b, c, d;
    a = vertex(0, reduced);
    b = vertex(1, reduced);
    c = vertex(2, reduced);
    d = vertex(3, reduced);
    tie(e1, found) = edge(a, b, reduced);
    ASSERT_TRUE(found);
    tie(e2, found) = edge(b, c, reduced);
    ASSERT_TRUE(found);
    tie(e3, found) = edge(c, d, reduced);
    ASSERT_TRUE(found);
    tie(e4, found) = edge(d, a, reduced);
    ASSERT_TRUE(found);
    tie(e5, found) = edge(a, c, reduced);
    ASSERT_TRUE(found);
    tie(e6, found) = edge(b, d, reduced);
    ASSERT_TRUE(found);

    property_map<Graph, edge_weight_t>::type weight = get(edge_weight, reduced);
    ASSERT_EQ(get(weight, e5), 2);
    ASSERT_EQ(get(weight, e6), 2);
    ASSERT_EQ(get(weight, e1), 1);
    ASSERT_EQ(get(weight, e2), 1);
    ASSERT_EQ(get(weight, e3), 1);
    ASSERT_EQ(get(weight, e4), 1);
}