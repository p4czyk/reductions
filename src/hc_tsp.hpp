#ifndef HC_TSP_HPP
#define HC_TSP_HPP

#include "hc.hpp"
#include "reduction.hpp"
#include "tsp.hpp"

/**
 * \brief Reduction from HC to TSP.
 * 
 * A polynomial reduction from Hamiltonian circuit (HC) to Travelling salesperson (TSP) according to [1].
 *
 * This reduction has runtime \f$\mathcal{O}(|V|^2)\f$.
 *
 * [1] Michael R. Garey and David S. Johnson. 1990.
 * Computers and Intractability; A Guide to the Theory of NP-Completeness.
 * W. H. Freeman & Co., USA.
 */
class HCTSP : public Reduction<HC, TSP> {
public:
    HCTSP() {}

    /**
    * \brief Reduces an instance from Hamiltonian circuit (HC) to Traveling salesperson (TSP).
    * 
    * \param from A Hamilton circuit instance.
    * \return A Traveling salesperson instance.
    */
    virtual TSP reduce(HC from);
};

#endif
