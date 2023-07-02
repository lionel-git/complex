#pragma once

#include "function.h"

class fct1 : public function
{
public:
    fct1() {}

    virtual complex_t operator()(complex_t z) const;
};

