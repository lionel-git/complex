#pragma once

#include "path.h"

class path_circle : public path
{
public:
    path_circle(complex_t start, complex_t end, double l);

    virtual std::vector<complex_t> get_path(int N) const;

private:
    complex_t center_;
    double radius_;
    double arg_start_;
    double arg_end_;
};
