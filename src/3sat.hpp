#ifndef THREE_SAT_HPP
#define THREE_SAT_HPP

#include "sat.hpp"
#include <memory>
#include <vector>

class ThreeClause : public Clause {
public:
    ThreeClause(Literal one);
    ThreeClause(Literal one, Literal two);
    ThreeClause(Literal one, Literal two, Literal three);
};

class ThreeSAT : public SAT {
public:
    ThreeSAT(std::vector<std::unique_ptr<ThreeClause>>&& clauses);
};

#endif