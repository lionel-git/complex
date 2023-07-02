#include <iostream>
#include <complex>
#include "path.h"
#include "path_circle.h"

#include "integrator.h"
#include "fct1.h"

int main(int argc, char** argv)
{
    try
    {
        complex_t A( 1.0,  1.0);
        complex_t B(-1.0,  1.0);
        complex_t C(-1.0, -1.0);
        complex_t D( 1.0, -1.0);

        path p1(A, B);
        path p2(B, C);
        path p3(C, D);
        path p4(D, A);

        path_circle p1c(A, B, 1.0);
        path_circle p2c(B, C, 1.0);
        path_circle p3c(C, D, 1.0);
        path_circle p4c(D, A, 1.0);

        std::vector<path> paths{p1, p2, p3, p4};
        std::vector<path_circle> paths_c{p1c, p2c, p3c, p4c}; 
        
        fct1 f1;
        integrator integr(f1, 1000);

        auto res1 = integr.integrate(paths);
        std::cout << "res1=" << res1 << std::endl;

        auto res2 = integr.integrate(paths_c);
        std::cout << "res2=" << res2 << std::endl;


    }
    catch (std::exception ex)
    {
        std::cout << ex.what() << std::endl;
    }
}