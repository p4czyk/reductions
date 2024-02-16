#include "hc_tsp.hpp"
#include "graph.hpp"
#include "hc.hpp"
#include "tsp.hpp"
#include <boost/graph/detail/adjacency_list.hpp>
#include <boost/graph/graph_concepts.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>

/**
 * @brief Reduces an instance from Hamilton circuit (HC) to Traveling salesperson (TSP).
 * 
 * @param from A Hamilton circuit instance.
 * @return A Traveling salesperson instance.
 */
TSP HCTSP::reduce(HC from) {
    Graph hc_graph = from.get_graph(); // Copy input graph
    Graph reduced(num_vertices(from.get_graph())); // Initialize new graph
    
    property_map<Graph, edge_weight_t>::type weightmap = get(edge_weight, reduced); // Get weights

    // For each vertex, insert an edge to all other vertices
    graph_traits<Graph>::vertex_iterator vi, vi_end, vj, vj_end;
    for (tie(vi, vi_end) = vertices(reduced); vi != vi_end; ++vi) {
        for (vj = vi + 1; vj != vi_end; ++vj) {
            graph_traits<Graph>::edge_descriptor ed;
            bool b;

            tie(ed, b) = add_edge(*vi, *vj, reduced);
            put(weightmap, ed, 2); // Set the weight of the edge to 2
        }
    }

    // For each edge in the initial graph, set the weight in the new graph to 1
    graph_traits<Graph>::edge_iterator ei, ei_end;
    for (tie(ei, ei_end) = edges(hc_graph); ei != ei_end; ++ei) {
        graph_traits<Graph>::vertex_descriptor u, v;
        graph_traits<Graph>::edge_descriptor e;
        bool found;

        u = vertex(source(*ei, hc_graph), reduced);
        v = vertex(target(*ei, hc_graph), reduced);
        tie(e, found) = edge(u, v, reduced);
        put(weightmap, e, 1); // Set the weight of the edge to 1
    }
    return TSP(reduced); // Return the TSP instance
}