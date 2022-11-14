#pragma once

class IRace {
    public:
        IRace(double health_mod, double armor_mod, double speed_mod, double damage_mod, double crit_mod) {
            m_health_mod = health_mod;
            m_armor_mod = armor_mod;
            m_speed_mod = speed_mod;
            m_damage_mod = damage_mod;
            m_crit_mod = crit_mod;
        }

        ~IRace() {}

        double GetHealthMod(){return m_health_mod;}
        double GetArmorMod(){return m_armor_mod;}
        double GetSpeedMod(){return m_speed_mod;}
        double GetDamageMod(){return m_damage_mod;}
        double GetCritChanceMod(){return m_crit_mod;}

    protected:
        double m_health_mod;
        double m_armor_mod;
        double m_speed_mod;
        double m_damage_mod;
        double m_crit_mod;
};
