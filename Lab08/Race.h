class IRace {
    public:
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

class Human : IRace {};

class Elf : IRace {};

class Dwarf : IRace {};

class Halfling : IRace {};

class GigaChad : IRace {};