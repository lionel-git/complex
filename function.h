#pragma once

#include "defines.h"

class function
{
public:
    virtual complex_t operator()(complex_t z) const = 0;
};

