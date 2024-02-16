#include "hc_tsp.hpp"
#include "graph.hpp"
#include "hc.hpp"
#include "tsp.hpp"
#include <boost/graph/detail/adjacency_list.hpp>
#include <boost/graph/graph_concepts.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include <iostream>

HCTSP::HCTSP() {
}

TSP HCTSP::reduce(HC from) {
    Graph hc_graph = from.get_graph();
    Graph g(from.get_graph().m_vertices.size());
    
    typedef graph_traits<Graph>::vertex_iterator vertex_iter;
    typedef property_map<Graph, vertex_index_t>::type IndexMap;

    IndexMap index = get(vertex_index, g);

    property_map<Graph, edge_weight_t>::type weightmap = get(edge_weight, g);

    graph_traits<Graph>::vertex_iterator vi, vi_end, vj, vj_end;
    for (tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi) {
        for (vj = vi + 1; vj != vi_end; ++vj) {
            typename graph_traits<Graph>::edge_descriptor ed;
            bool b;
            tie(ed, b) = add_edge(index[*vi], index[*vj], g);
            put(weightmap, ed, 2);
            std::cout << get(weightmap, ed) << std::endl;
        }
    }
    graph_traits<Graph>::edge_iterator ei, ei_end;
    for (tie(ei, ei_end) = edges(hc_graph); ei != ei_end; ++ei) {
        graph_traits<Graph>::vertex_descriptor u, v;
        graph_traits<Graph>::edge_descriptor e;
        bool found;
        u = vertex(source(*ei, hc_graph), g);
        v = vertex(target(*ei, hc_graph), g);
        tie(e, found) = edge(u, v, g);
        put(weightmap, e, 1);
        std::cout << get(weightmap, *ei) << std::endl;
    }
    return TSP(g);
}