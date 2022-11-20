#pragma once

#include "IRace.h"

class Halfling : public IRace {
    public:

        Halfling() : IRace(3,4,7,5,10){}

        virtual ~Halfling(){}
};