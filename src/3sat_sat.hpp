#ifndef THREESAT_SAT_HPP
#define THREESAT_SAT_HPP

#include "reduction.hpp"
#include "sat.hpp"
#include "3sat.hpp"

class ThreeSAT_SAT : public Reduction<ThreeSAT, SAT> {
public:
    ThreeSAT_SAT();
    virtual SAT reduce(ThreeSAT from);
};

#endif