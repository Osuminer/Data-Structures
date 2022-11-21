#include "Party.h"
#include "ICharacter.h"

Party::Party() {}

void Party::AddCharacter(std::shared_ptr<ICharacter> characterToAdd) {
    m_party.push_back(characterToAdd);
    m_size++;
}

bool Party::isDead() {
    for (auto it = m_party.begin(); it != m_party.end(); it++) {
        if ((*it)->GetHealth() <= 0) {
            return false;
        }
    }

    return true;
}

std::shared_ptr<ICharacter> Party::FindTarget() {
    for (auto it = m_party.begin(); it != m_party.end(); it++) {
        if ((*it)->GetHealth() > 0) {
            return *it;
        }
    }
}
