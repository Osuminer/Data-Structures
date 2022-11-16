#pragma once

#include "ICharacter.h"
#include "IRace.h"
#include <memory>

class Wizard : public ICharacter {
    Wizard(std::shared_ptr<IRace> race) : ICharacter(race) {
        m_armor = 5;
        m_health = 5;
        m_damage = 20;
        m_crit = 15;
        m_speed = 5;
    }

    virtual ~Wizard();

    
};