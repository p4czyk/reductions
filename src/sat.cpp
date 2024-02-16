#include "sat.hpp"
#include <memory>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Clause::Clause(vector<Literal> literals) {
    this->literals = literals;
}

SAT::SAT(vector<unique_ptr<Clause>> clauses) {
    this->clauses = std::move(clauses);
}

vector<Literal> Clause::get_literals() {
    return literals;
}

string SAT::to_string() {
    stringstream stream;
    for (int i = 0; i < clauses.size(); i++) {
        stream << "[";
        int literal_i = 0;
        for (; literal_i < clauses[i]->get_literals().size() - 1; literal_i++) {
            stream << clauses[i]->get_literals()[literal_i] << ", ";
        }
        stream << clauses[i]->get_literals()[literal_i] << "]";
        if (clauses[i] != clauses[clauses.size() - 1]) {
            stream << ", ";
        }
    }
    return stream.str();
}