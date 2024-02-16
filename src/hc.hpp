#ifndef HC_HPP
#define HC_HPP

#include "graph.hpp"
#include "problem.hpp"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_concepts.hpp>
#include <boost/graph/graph_selectors.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include <boost/pending/property.hpp>

using namespace boost;

class HC : public Problem {
private:
    Graph graph;
public:
    HC(Graph graph);
    Graph get_graph();
    virtual string to_string();
};

#endif