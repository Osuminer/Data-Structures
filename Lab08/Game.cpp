#include <iostream>
#include <memory>
#include <random>

#include "CharacterFactory.h"
#include "ICharacter.h"
#include "IRace.h"

#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Gigachad.h"
#include "Halfling.h"

#include "Monk.h"
#include "Barbarian.h"
#include "Paladin.h"
#include "Party.h"
#include "Wizard.h"

int main() {
    bool isGameEnded;

    Party party1;
    Party party2;
    std::shared_ptr<ICharacter> c;
        
    // Generate Party 1 ------------------------------------------------------------------------------------------------------------------

    // Gen Paladin-Human
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::PaladinType, CharacterFactory::HumanType);
    std::shared_ptr<Paladin> paladin = std::dynamic_pointer_cast<Paladin>(c);

    party1.AddFrontRow(paladin);

    // Gen Barbarian-Halfling
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::BarbarianType, CharacterFactory::HalflingType);
    std::shared_ptr<Barbarian> barbarian = std::dynamic_pointer_cast<Barbarian>(c);

    party1.AddFrontRow(barbarian);

    // Gen Wizard-Human
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::WizardType, CharacterFactory::ElfType);
    std::shared_ptr<Wizard> wizard = std::dynamic_pointer_cast<Wizard>(c);

    party1.AddBackRow(wizard);


    // Generate Party 2 ------------------------------------------------------------------------------------------------------------------

    // Gen Paladin-Human
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::PaladinType, CharacterFactory::DwarfType);
    std::shared_ptr<Paladin> paladin2 = std::dynamic_pointer_cast<Paladin>(c);

    party2.AddFrontRow(paladin2);

    // Gen Barbarian-Halfling
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::BarbarianType, CharacterFactory::HumanType);
    std::shared_ptr<Barbarian> barbarian2 = std::dynamic_pointer_cast<Barbarian>(c);

    party2.AddFrontRow(barbarian2);

    // Gen Wizard-Human
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::MonkType, CharacterFactory::ElfType);
    std::shared_ptr<Monk> monk2 = std::dynamic_pointer_cast<Monk>(c);

    party2.AddBackRow(monk2);


    // Game loop start -------------------------------------------------------------------------------------------------------------------
    while (!isGameEnded) {





    }
}