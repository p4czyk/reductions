#include "3sat.hpp"
#include "sat.hpp"
#include <iterator>
#include <memory>
#include <vector>

ThreeClause::ThreeClause(Literal one) : Clause(std::vector<std::unique_ptr<Literal>>{std::make_unique<Literal>(one)}) {
    
}

ThreeClause::ThreeClause(Literal one, Literal two) : Clause(std::vector<std::unique_ptr<Literal>>{std::make_unique<Literal>(one), std::make_unique<Literal>(two)}) {

}

ThreeClause::ThreeClause(Literal one, Literal two, Literal three) : Clause(std::vector<std::unique_ptr<Literal>>{std::make_unique<Literal>(one), std::make_unique<Literal>(two), std::make_unique<Literal>(three)}) {

}

ThreeSAT::ThreeSAT(std::vector<std::unique_ptr<ThreeClause>>&& clauses) 
    : SAT(std::vector<std::unique_ptr<Clause>>(
        std::make_move_iterator(clauses.begin()), 
        std::make_move_iterator(clauses.end())
    )) {

}