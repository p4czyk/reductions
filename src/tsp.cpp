#include "tsp.hpp"

TSP::TSP(Graph graph) {
    this->graph = graph;
}

Graph TSP::get_graph() {
    return graph;
}

string TSP::to_string() {
    return "";
}