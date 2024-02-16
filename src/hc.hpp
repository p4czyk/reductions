#ifndef HC_HPP
#define HC_HPP

#include "graph.hpp"
#include "problem.hpp"

using namespace boost;

/**
 * \brief The Hamiltonian circuit problem.
 * 
 * INSTANCE: A graph \f$G = (V, E)\f$.
 *
 * QUESTION: Does \f$G\f$ contain a Hamiltonian circuit?
 * 
 */
class HC : public Problem {
private:
    Graph graph;
public:
    HC(Graph graph);
    Graph get_graph();
    virtual string to_string();
};

#endif