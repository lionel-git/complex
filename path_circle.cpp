#define _USE_MATH_DEFINES

#include "path_circle.h"

static
double my_arg(complex_t z)
{
    auto res = std::arg(z);
    if (res < 0.0)
        res += 2*M_PI;
    return res;
}


path_circle::path_circle(complex_t start, complex_t end, double l) : 
    path(start, end)
{
    auto mid = (start_ + end_) / 2.0;
    auto half_diag = (end_ - start_) / 2.0;
    center_ = mid + complex_t(0.0, l) * half_diag;
    radius_ = std::sqrt(std::norm(end_ - center_));
    
    arg_start_ = my_arg(start_ - center_);
    arg_end_ = my_arg(end_ - center_);

    while (arg_end_<arg_start_)
        arg_end_ += 2 * M_PI;

    // Some checks
    auto radius2 = std::sqrt(std::norm(start_ - center_));
    if (std::abs(radius2 - radius_) > 1e-8)
        throw std::runtime_error("Internal error");
}

std::vector<complex_t> 
path_circle::get_path(int N) const
{
    auto dt = (arg_end_ - arg_start_) / N;
    std::vector<complex_t> v(N + 1);
    for (int i = 0; i <= N; i++)
        v[i] = center_ + std::polar(radius_, arg_start_ + i * dt);
    return v;
}