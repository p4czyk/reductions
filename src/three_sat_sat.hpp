#ifndef THREESAT_SAT_HPP
#define THREESAT_SAT_HPP

#include "reduction.hpp"
#include "sat.hpp"
#include "three_sat.hpp"

class ThreeSATSAT : public Reduction<ThreeSAT, SAT> {
public:
    ThreeSATSAT();
    virtual SAT reduce(ThreeSAT from);
};

#endif