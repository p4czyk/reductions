#include "three_sat.hpp"
#include "three_sat_sat.hpp"
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using namespace std;

int main() {
    unique_ptr<ThreeClause> three_clause = make_unique<ThreeClause>(3, 3, 3);
    vector<unique_ptr<ThreeClause>> three_clauses;
    three_clauses.push_back(std::move(three_clause));
    ThreeSAT three_sat(std::move(three_clauses));
    ThreeSATSAT reduction;
    cout << "Vanilla: " << three_sat.to_string() << endl;
    SAT reduced = reduction.reduce(std::move(three_sat));
    cout << "Reduced: " << reduced.to_string() << endl;

    return 0;
}