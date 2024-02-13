#include "3sat.hpp"
#include "3sat_sat.hpp"

int main() {
    ThreeSAT_SAT reduction;
    SAT reduced = reduction.reduce(ThreeSAT({ThreeClause(1)}));
    return 0;
}