#ifndef HC_TSP_HPP
#define HC_TSP_HPP

#include "hc.hpp"
#include "reduction.hpp"
#include "tsp.hpp"

class HCTSP : public Reduction<HC, TSP> {
public:
    HCTSP();
    virtual TSP reduce(HC from);
};

#endif