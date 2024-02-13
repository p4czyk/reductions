#include "sat.hpp"
#include <memory>
#include <sstream>
#include <string>
#include <vector>

Clause::Clause(std::vector<std::unique_ptr<Literal>> literals) {
    this->literals = literals;
}

SAT::SAT(std::vector<std::unique_ptr<Clause>> clauses) {
    this->clauses = clauses;
}

std::vector<std::unique_ptr<Literal>> Clause::get_literals() {
    return literals;
}

std::string SAT::to_string() {
    std::stringstream stream;
    for (int i = 0; i < clauses.size(); i++) {
        stream << "[";
        int literal_i = 0;
        for (; literal_i < clauses[i]->get_literals().size() - 1; literal_i++) {
            stream << *clauses[i]->get_literals()[literal_i] << ", ";
        }
        stream << *clauses[i]->get_literals()[literal_i + 1] << "]";
        if (clauses[i] != clauses[clauses.size() - 1]) {
            stream << ", ";
        }
    }
    return stream.str();
}