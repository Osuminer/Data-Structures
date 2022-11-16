#pragma once

#include "ICharacter.h"
#include "IRace.h"
#include <memory>

class Paladin : public ICharacter {
    Paladin(std::shared_ptr<IRace> race) : ICharacter(race) {
        m_armor = 20;
        m_health = 15;
        m_damage = 5;
        m_crit = 3;
        m_speed = 1;
    }

    virtual ~Paladin();

    
};