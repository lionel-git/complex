#include "path.h"

std::vector<complex_t>
path::get_path(int N) const
{
    auto dz = (end_ - start_) / complex_t(N);
    std::vector<complex_t> v(N + 1);
    for (int i = 0; i <= N; i++)
        v[i] = start_ + complex_t(i) * dz;
    return v;
}
