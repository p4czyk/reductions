#include "3sat.hpp"
#include "3sat_sat.hpp"
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using namespace std;

int main() {
    unique_ptr<ThreeClause> three_clause = make_unique<ThreeClause>(1);
    vector<unique_ptr<ThreeClause>> three_clauses;
    three_clauses.push_back(std::move(three_clause));
    ThreeSAT three_sat(std::move(three_clauses));
    ThreeSAT_SAT reduction;
    SAT reduced = reduction.reduce(three_sat);

    cout << reduced.to_string() << endl;
    cout << three_sat.to_string() << endl;
    return 0;
}