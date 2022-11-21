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


bool IsGameOver(std::shared_ptr<Party> party1, std::shared_ptr<Party> party2) {
    if (party1->isDead()) {
        std::cout << "Game Over: Party 2 wins" << std::endl;
        return true;
    }

    if (party2->isDead()) {
        std::cout << "Game Over: Party 1 wins" << std::endl;
        return true;
    }

    return false;
}


void Attack(std::shared_ptr<ICharacter> attacker, std::shared_ptr<ICharacter> enemy) {
    enemy->SetHealth(enemy->GetHealth() - (attacker->GetDamage() / enemy->GetArmor()));
}


int main() {
    bool isGameEnded;

    Party party11;
    Party party22;

    std::shared_ptr<Party> party1 = std::make_shared<Party>(party11);
    std::shared_ptr<Party> party2 = std::make_shared<Party>(party22);
    std::shared_ptr<ICharacter> c;
    std::map<double, std::shared_ptr<ICharacter>> turnList;

        
    // Generate Party 1 ------------------------------------------------------------------------------------------------------------------

    // Gen Paladin-Human
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::PaladinType, CharacterFactory::HumanType, party1);
    // std::shared_ptr<Paladin> paladin = std::dynamic_pointer_cast<Paladin>(c);
    auto paladin = c;
    
    turnList.insert(std::pair(paladin->GetSpeed(), paladin));
    party1->AddCharacter(paladin);

    // Gen Barbarian-Halfling
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::BarbarianType, CharacterFactory::HalflingType, party1);
    // std::shared_ptr<Barbarian> barbarian = std::dynamic_pointer_cast<Barbarian>(c);
    auto barbarian = c;
    
    turnList.insert(std::pair(barbarian->GetSpeed(), barbarian));
    party1->AddCharacter(barbarian);

    // Gen Wizard-Human
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::WizardType, CharacterFactory::ElfType, party1);
    // std::shared_ptr<Wizard> wizard = std::dynamic_pointer_cast<Wizard>(c);
    auto wizard = c;

    turnList.insert(std::pair(wizard->GetSpeed(), wizard));
    party1->AddCharacter(wizard);


    // Generate Party 2 ------------------------------------------------------------------------------------------------------------------

    // Gen Paladin-Human
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::PaladinType, CharacterFactory::DwarfType, party2);
    // std::shared_ptr<Paladin> paladin2 = std::dynamic_pointer_cast<Paladin>(c);
    auto paladin2 = c;

    turnList.insert(std::pair(paladin2->GetSpeed(), paladin2));
    party2->AddCharacter(paladin2);

    // Gen Barbarian-Halfling
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::BarbarianType, CharacterFactory::HumanType, party2);
    // std::shared_ptr<Barbarian> barbarian2 = std::dynamic_pointer_cast<Barbarian>(c);
    auto barbarian2 = c;

    turnList.insert(std::pair(barbarian2->GetSpeed(), barbarian2));
    party2->AddCharacter(barbarian2);

    // Gen Monk-Halfling
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::MonkType, CharacterFactory::HalflingType, party2);
    // std::shared_ptr<Monk> monk2 = std::dynamic_pointer_cast<Monk>(c);
    auto monk2 = c;

    turnList.insert(std::pair(monk2->GetSpeed(), monk2));
    party2->AddCharacter(monk2);

    //TODO: Remove said characters from list if their health < 0

    // Game loop start -------------------------------------------------------------------------------------------------------------------
    while (!isGameEnded) {
        std::shared_ptr<ICharacter> party1Target;
        std::shared_ptr<ICharacter> party2Target;
        std::shared_ptr<ICharacter> target;

        party1Target = party1->FindTarget();
        party2Target = party2->FindTarget();

        for (auto it = turnList.rbegin(); it != turnList.rend(); it++) {
            if (it->second->GetParty() == party1) {
                target = party2Target;
            } else {
                target = party1Target;
            }

            Attack(it->second, target);
            std::cout << it->second << " attacks " << target << " for " << it->second->GetDamage() << std::endl;
        }

    // for (auto it = turnList.rbegin(); it != turnList.rend(); it++) {
    //     std::cout << it->first << " : " << it->second << std::endl;
    // }

        isGameEnded = IsGameOver(party1, party2);
    }
}