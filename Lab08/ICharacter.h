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

        double GetHealth(){return m_health;}
        double GetArmor(){return m_armor;}
        double GetDamage(){return m_damage;}
        double GetSpeed(){return m_speed;}
        double GetCrit(){return m_crit;}

    protected:
        std::shared_ptr<IRace> m_race;
        double m_health;
        double m_armor;
        double m_damage;
        double m_speed;
        double m_crit;

};