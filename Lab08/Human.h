#pragma once

#include "IRace.h"

class Human : IRace {
    public:

        Human() : IRace(5,5,5,5,5){}

        virtual ~Human(){}
};