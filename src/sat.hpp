#ifndef SAT_HPP
#define SAT_HPP

#include <vector>

typedef int Literal;

class Clause {
    std::vector<Literal> literals;
};

class SAT {
private:
    std::vector<Clause> clauses;
};

#endif