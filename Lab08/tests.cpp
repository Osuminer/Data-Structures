#include <gtest/gtest.h>

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

std::shared_ptr<Party> party = std::make_shared<Party>();
std::shared_ptr<ICharacter> c;

// Test Health ---------------------------------------------------------------------------------------------------------------------------------
TEST(Health, Barbarians) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::BarbarianType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetHealth(), 10);
}
TEST(Health, Paladins) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::PaladinType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetHealth(), 20);
}
TEST(Health, Monks) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::MonkType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetHealth(), 8);
}
TEST(Health, Wizards) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::WizardType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetHealth(), 10);
}
// Test Damage ---------------------------------------------------------------------------------------------------------------------------------
TEST(Damage, Barbarians) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::BarbarianType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetDamage(), 8);
}
TEST(Damage, Paladins) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::PaladinType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetDamage(), 10);
}
TEST(Damage, Monks) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::MonkType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetDamage(), 9);
}
TEST(Damage, Wizards) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::WizardType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetDamage(), 25);
}
// Test Armor ---------------------------------------------------------------------------------------------------------------------------------
TEST(Armor, Barbarians) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::BarbarianType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetArmor(), 10);
}
TEST(Armor, Paladins) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::PaladinType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetArmor(), 25);
}
TEST(Armor, Monks) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::MonkType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetArmor(), 8);
}
TEST(Armor, Wizards) {
    c = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::WizardType, CharacterFactory::HumanType, party);

    ASSERT_EQ(c->GetArmor(), 10);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}