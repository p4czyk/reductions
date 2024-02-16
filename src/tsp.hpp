#ifndef TSP_HPP
#define TSP_HPP

#include "graph.hpp"
#include "problem.hpp"

using namespace std;

class TSP : public Problem {
    Graph graph;
public:
    TSP(Graph graph);
    Graph get_graph();
    virtual string to_string();
};

#endif