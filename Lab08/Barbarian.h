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

    Barbarian() = delete;

    virtual ~Barbarian();

    
};