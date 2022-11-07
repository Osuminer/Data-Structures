class Class {
    public:
        double GetHealth(){return m_health;}
        double GetArmor(){return m_armor;}
        double GetDamage(){return m_damage;}
        double GetSpeed(){return m_speed;}
        double GetCrit(){return m_crit;}

    protected:
        double m_health;
        double m_armor;
        double m_damage;
        double m_speed;
        double m_crit;

};