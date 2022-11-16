#pragma once

#include "ICharacter.h"
#include "IRace.h"
#include <memory>

class Monk : public ICharacter {
    Monk(std::shared_ptr<IRace> race) : ICharacter(race) {
        m_armor = 3;
        m_health = 3;
        m_damage = 4;
        m_crit = 10;
        m_speed = 5;
    }

    virtual ~Monk();

    
};