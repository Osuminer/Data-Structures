#pragma once

#include "ICharacter.h"
#include "IRace.h"
#include <memory>

class Barbarian : public ICharacter {
    Barbarian(std::shared_ptr<IRace> race) : ICharacter(race) {
        m_armor = 5;
        m_health = 5;
        m_damage = 3;
        m_crit = 5;
        m_speed = 1;
    }

    virtual ~Barbarian();

    
};