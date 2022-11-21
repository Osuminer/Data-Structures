#pragma once

#include "ICharacter.h"
#include "IRace.h"
#include <memory>

class Monk : public ICharacter {
    public:
        virtual double GetHealth() override {
            double retVal = m_health;
            return retVal;
        }
        virtual double GetArmor() override {
            double retVal = m_armor;
            return retVal;
        }
        virtual double GetDamage() override {
            double retVal = m_damage;
            return retVal;
        }
        virtual double GetCrit() override {
            double retVal = m_crit;
            return retVal;
        }
        virtual double GetSpeed() override {
            double retVal = m_speed;
            return retVal;
        }
        virtual std::shared_ptr<Party> GetParty() override {
            return m_party;
        }


        virtual void SetHealth(double newHealth) override {
            m_health = newHealth;
        }

        Monk(std::shared_ptr<IRace> race, std::shared_ptr<Party> party) : ICharacter(race, party) {
            m_armor = 3 + m_race->GetArmorMod();
            m_health = 3 + m_race->GetHealthMod();
            m_damage = 4 + m_race->GetDamageMod();
            m_crit = 10 + m_race->GetCritChanceMod();
            m_speed = 5 + m_race->GetSpeedMod();
        }

        Monk() = delete;

        virtual ~Monk() {}

    
};