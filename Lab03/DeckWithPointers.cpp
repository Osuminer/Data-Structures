#include "DeckWithPointers.h"
#include "Card.h"
#include "PersonWithPointers.h"
#include "DeckWithPointers.h"
#include <iostream>

DeckWithPointers::DeckWithPointers()
{
    // For demo purposes reducing number of cards
    //for(int i = 1 ; i <=13; i++)
    for(int i = 1 ; i <=3; i++)
    {
        this->m_deck.push_back(new Card(i,0));
        this->m_deck.push_back(new Card(i,1));
        this->m_deck.push_back(new Card(i,2));
        this->m_deck.push_back(new Card(i,3));
    }

}
DeckWithPointers::~DeckWithPointers()
{
    std::cout<<"DeckWithPointers Destructor Called"<<std::endl;	
    for(auto it = m_deck.begin(); it != m_deck.end(); it++)
    {
        delete *it;
    }
    m_deck.clear();
}

void DeckWithPointers::PrintDeck()
{

    for (auto it = m_deck.begin(); it != m_deck.end(); it++)
    {
        std::cout << (*it)->GetSuit() << " " << (*it)->GetValue() << " " << (*it)->GetGuid()<< std::endl;
    }
    std::cout << std::endl;
}

Card * DeckWithPointers::DrawCard()
{   
    Card * retVal = nullptr;

    if(!m_deck.empty())
    {
        retVal = m_deck.front();
        m_deck.pop_front();
    }
    return retVal;
}

void DeckWithPointers::ReturnCard(Card * c)
{
    if(c != nullptr)
    {
        m_deck.push_back(c);
        return;
    }
    else
    {
        throw "Attempting to add a nullptr in DeckWithPointers::ReturnCard";
    }

}

