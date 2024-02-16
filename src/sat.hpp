#ifndef SAT_HPP
#define SAT_HPP

#include <memory>
#include <string>
#include <vector>
#include "problem.hpp"

using namespace std;

typedef int Literal;

/**
 * @brief 
 * 
 */
class Clause {
private:
    vector<Literal> literals;

public:
    Clause(vector<Literal>);
    vector<Literal> get_literals();
};

class SAT : public Problem {
private:
    vector<unique_ptr<Clause>> clauses;
public:
    SAT(vector<unique_ptr<Clause>> clauses);
    virtual string to_string();
};

#endif