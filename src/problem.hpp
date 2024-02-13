#ifndef PROBLEM_HPP
#define PROBLEM_HPP

#include <string>

using namespace std;

class Problem {
public:
    virtual string to_string() = 0;
};

#endif