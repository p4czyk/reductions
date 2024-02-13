#include "three_sat.hpp"
#include "sat.hpp"
#include <iterator>
#include <memory>
#include <vector>

using namespace std;

ThreeClause::ThreeClause(Literal one) : Clause(vector<Literal>{one}) {
    
}

ThreeClause::ThreeClause(Literal one, Literal two) : Clause(vector<Literal>{one, two}) {

}

ThreeClause::ThreeClause(Literal one, Literal two, Literal three) : Clause(vector<Literal>{one, two, three}) {

}

ThreeSAT::ThreeSAT(std::vector<unique_ptr<ThreeClause>> clauses) 
    : SAT(vector<unique_ptr<Clause>>(
        make_move_iterator(clauses.begin()), 
        make_move_iterator(clauses.end())
    )) {
    
}