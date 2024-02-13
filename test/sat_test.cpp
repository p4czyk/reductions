#include <gtest/gtest.h>
#include <iterator>
#include <memory>
#include <utility>
#include <vector>
#include "sat.hpp"

using namespace std;

TEST(SATTest, BasicAssertions) {
    vector<Literal> literals{1, -1, -2};
    unique_ptr<Clause> clause = make_unique<Clause>(literals);
    vector<unique_ptr<Clause>> clauses;
    clauses.push_back(std::move(clause));
    SAT sat(
        vector<unique_ptr<Clause>>(
            make_move_iterator(clauses.begin()), 
            make_move_iterator(clauses.end())));
    EXPECT_STRNE(sat.to_string().c_str(), "[1, -1, -2]\n");
}