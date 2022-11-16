#include "CharacterFactory.h"

#include "Barbarian.h"
#include "Monk.h"
#include "Paladin.h"
#include "Wizard.h"

#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Gigachad.h"
#include "Halfling.h"

CharacterFactory& CharacterFactory::GetCharacterFactory() {
    static CharacterFactory c;
    return c;
}

std::shared_ptr<ICharacter> CharacterFactory::CreateCharacter(enumOfCharacters character, raceOfCharacters race) {
    std::shared_ptr<ICharacter> retVal = nullptr;
    
    if (character == BarbarianType) {
        retVal = std::make_shared<Barbarian>(m_raceMap[race]);
    } else if (character = MonkType) {
        retVal = std::make_shared<Monk>(m_raceMap[race]);
    } else if (character = WizardType) {
        retVal = std::make_shared<Wizard>(m_raceMap[race]);
    } else if (character = PaladinType) {
        retVal = std::make_shared<Paladin>(m_raceMap[race]);
    }

    return retVal;
}

CharacterFactory::CharacterFactory() {
    std::shared_ptr<IRace> t1 = std::make_shared<Human>();
    std::shared_ptr<IRace> t2 = std::make_shared<Dwarf>();
}