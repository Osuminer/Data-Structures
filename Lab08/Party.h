#pragma once

#include <vector>
#include <memory>

class ICharacter;

class Party {
    public:
        Party();

        void AddCharacter(std::shared_ptr<ICharacter>);
        bool isDead();
        std::shared_ptr<ICharacter> FindTarget(); 

    private:
        int m_size;
        std::vector<std::shared_ptr<ICharacter>> m_party;
};