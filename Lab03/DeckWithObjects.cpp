#include "DeckWithObjects.h"
#include <exception>
#include <iostream>

DeckWithObjects::DeckWithObjects()
{
    // For demo purposes reducing number of cards
    // for(int i = 1 ; i <=13; i++)
    for(int i = 1 ; i <=3; i++)
    {
        this->m_deck.push_back(std::move(Card(i,0)));
        this->m_deck.push_back(std::move(Card(i,1)));
        this->m_deck.push_back(std::move(Card(i,2)));
        this->m_deck.push_back(std::move(Card(i,3)));
    }
}
DeckWithObjects::~DeckWithObjects()
{
    std::cout << "Deleting DeckWithObjects"  << std::endl;
    m_deck.clear();
}

Card DeckWithObjects::DrawCard()
{

    if (!m_deck.empty())
    {
        Card c = std::move(m_deck.front());
        m_deck.pop_front();
        return std::move(c);
    }

    throw "Deck not empty";


}

void DeckWithObjects::ReturnCard(Card c)
{
    m_deck.push_back(std::move(c));
}

void DeckWithObjects::PrintDeck()
{
    
    for (auto it = m_deck.begin(); it != m_deck.end(); it++)
    {
        std::cout << (*it).GetSuit() << " " << (*it).GetValue() << " " << (*it).GetGuid()<< std::endl;
    }
    std::cout << std::endl;

}