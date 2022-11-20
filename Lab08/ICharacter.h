#pragma once

#include "IRace.h"
#include <memory>

class ICharacter {
    public:
        ICharacter(std::shared_ptr<IRace> race) {
            m_health = 0;
            m_armor = 0;
            m_damage = 0;
            m_speed = 0;
            m_crit = 0;
            m_race = race;
        }

        virtual double GetHealth() = 0;
        virtual double GetArmor() = 0;
        virtual double GetDamage() = 0;
        virtual double GetSpeed() = 0;
        virtual double GetCrit() = 0;

    protected:
        std::shared_ptr<IRace> m_race;
        double m_health;
        double m_armor;
        double m_damage;
        double m_speed;
        double m_crit;

};