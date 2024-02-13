#ifndef REDUCTION_HPP
#define REDUCTION_HPP

template <class T, class U>
class Reduction {
public:
    virtual U reduce(T from) = 0;
};

#endif