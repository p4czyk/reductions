#ifndef THREE_SAT_HPP
#define THREE_SAT_HPP

#include "sat.hpp"
#include <memory>
#include <vector>

using namespace std;

class ThreeClause : public Clause {
public:
    ThreeClause(Literal one);
    ThreeClause(Literal one, Literal two);
    ThreeClause(Literal one, Literal two, Literal three);
};

class ThreeSAT : public SAT {
public:
    ThreeSAT(vector<unique_ptr<ThreeClause>> clauses);
};

#endif