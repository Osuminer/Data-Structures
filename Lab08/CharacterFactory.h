#pragma once

#include "ICharacter.h"
#include <memory>
#include <map>

class IRace;

class CharacterFactory {
    public:
        enum enumOfCharacters {BarbarianType, MonkType, PaladinType, WizardType};
        enum raceOfCharacters {DwarfType, ElfType, GigachadType, HalflingType, HumanType};


        std::shared_ptr<ICharacter> CreateCharacter(enumOfCharacters charType, raceOfCharacters raceType, std::shared_ptr<Party> party);

        static CharacterFactory& GetCharacterFactory();

        CharacterFactory(const CharacterFactory&) = delete;
        CharacterFactory & operator = (const CharacterFactory&) = delete;

    private:
        std::map<raceOfCharacters, std::shared_ptr<IRace>> m_raceMap;

        CharacterFactory();
        ~CharacterFactory();

};
