#pragma once

#include "defines.h"
#include "function.h"

#include <vector>

class path
{
public:
    path(complex_t start, complex_t end) : start_(start), end_(end) {}
    virtual std::vector<complex_t> get_path(int N) const;
        
protected:
    complex_t start_;
    complex_t end_;
};
