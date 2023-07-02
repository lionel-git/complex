#pragma once

#include "defines.h"
#include "path.h"

#include <vector>

class integrator
{
public:
    integrator(const function& f, int N);

    template<typename T>
    complex_t integrate(T path) const
    {
        complex_t sum = 0;
        auto p = path.get_path(N_);
        for (int i = 0; i < p.size() - 1; ++i)
            sum += f_(p[i]) * (p[i + 1] - p[i]);
        return sum;
    }

    template<typename T>
    complex_t integrate(std::vector<T> paths) const
    {
        complex_t sum = 0;
        for (int i = 0; i < paths.size(); ++i)
            sum += integrate(paths[i]);
        return sum;
    }

private:
    int N_;
    const function& f_;
};

