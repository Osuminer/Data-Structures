#pragma once
#include <list>
#include <memory>

//Fwd declaration
class Card;

class DeckWithSmartPointers
{
    public:
        DeckWithSmartPointers();
        virtual ~DeckWithSmartPointers();

        std::shared_ptr<Card> DrawCard();
        void ReturnCard(std::shared_ptr<Card> c);

        void PrintDeck();

    private:

        std::list<std::shared_ptr<Card>> m_deck;

};