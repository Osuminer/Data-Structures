#pragma once

#include "IRace.h"

class Dwarf : public IRace {
    public:

        Dwarf() : IRace(15,15,2,7,6){}

        virtual ~Dwarf(){}
};