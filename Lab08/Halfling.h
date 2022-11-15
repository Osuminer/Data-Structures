#pragma once

#include "IRace.h"

class Halfling : IRace {
    public:

        Halfling() : IRace(3,4,7,5,10){}

        virtual ~Halfling(){}
};