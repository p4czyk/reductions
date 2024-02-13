#ifndef SAT_HPP
#define SAT_HPP

#include <memory>
#include <string>
#include <vector>
#include "problem.hpp"

typedef int Literal;

class Clause {
private:
    std::vector<std::unique_ptr<Literal>> literals;

public:
    Clause(std::vector<std::unique_ptr<Literal>>);
    std::vector<std::unique_ptr<Literal>> get_literals();
};

class SAT : public Problem {
private:
    std::vector<std::unique_ptr<Clause>> clauses;
public:
    SAT(std::vector<std::unique_ptr<Clause>> clauses);
    virtual std::string to_string();
};

#endif