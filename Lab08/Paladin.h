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

    virtual double GetHealth() override {
        double retVal = m_health + m_race->GetHealthMod();
        return retVal;
    }
    virtual double GetArmor() override {
        double retVal = m_armor + m_race->GetArmorMod();
        return retVal;
    }
    virtual double GetDamage() override {
        double retVal = m_damage + m_race->GetDamageMod();
        return retVal;
    }
    virtual double GetCrit() override {
        double retVal = m_crit + m_race->GetCritChanceMod();
        return retVal;
    }
    virtual double GetSpeed() override {
        double retVal = m_speed + m_race->GetSpeedMod();
        return retVal;
    }

    Paladin() = delete;

    virtual ~Paladin();

    
};