#ifndef PROBLEM_HPP
#define PROBLEM_HPP

#include <string>

class Problem {
public:
    virtual std::string to_string() = 0;
};

#endif