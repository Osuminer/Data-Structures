#pragma once

#include "IRace.h"

class Elf : public IRace {
    public:

        Elf() : IRace(2,1,15,15,20){}

        virtual ~Elf(){}
};