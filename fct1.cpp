#include "fct1.h"

complex_t 
fct1::operator()(complex_t z) const
{
    return 1.0 / (z);
}
