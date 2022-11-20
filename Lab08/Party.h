#pragma once

#include <vector>
#include <memory>

class ICharacter;

class Party {
    public:
        Party();

        void AddFrontRow(std::shared_ptr<ICharacter>);
        void AddBackRow(std::shared_ptr<ICharacter>);

        bool IsFrontDead();

    private:
        int m_size;
        
        std::vector<std::shared_ptr<ICharacter>> m_frontRow;
        std::vector<std::shared_ptr<ICharacter>> m_backRow;
};