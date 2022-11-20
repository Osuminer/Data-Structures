#include "Party.h"

void Party::AddFrontRow(std::shared_ptr<ICharacter> characterToAdd) {
    m_frontRow.push_back(characterToAdd);
}

void Party::AddBackRow(std::shared_ptr<ICharacter> characterToAdd) {
    m_backRow.push_back(characterToAdd);
}