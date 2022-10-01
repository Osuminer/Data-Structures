
#include "PersonWithObjects.h"
#include <iostream>

PersonWithObjects::~PersonWithObjects( )
{
    std::cout << "Deleting PersonWithObjects" << m_name << std::endl;
}

PersonWithObjects::PersonWithObjects(std::string name) :m_name(name)
{

}

PersonWithObjects::PersonWithObjects( const PersonWithObjects &p)
{
    std::cout<<"    BAD!!!! Copy Person Constructor being called.  I shouldn't really be callled!!!"<<std::endl;
    m_name = p.m_name;
}

PersonWithObjects::PersonWithObjects(PersonWithObjects && obj) noexcept
{
    // std::cout <<"    Calling Person Move Constructor"<<std::endl;
    this->m_name = std::move(obj.m_name);
    this->m_listOfCards = std::move(obj.m_listOfCards);
    this->m_stackOfCards = std::move(obj.m_stackOfCards);
}


std::string PersonWithObjects::GetName() const
{
    return m_name;
}

void PersonWithObjects::AddCardToHand( Card  c)
{
    // std::cout<<"   AddCardToHandObject :"<<c.GetValue()<<" "<<c.GetSuit() << " " << c.GetGuid() << std::endl;
    m_listOfCards.push_front(std::move(c));
}

void PersonWithObjects::AddCardToHand(Card & c)
{
    // std::cout << "   AddCardToHandObject (by ref) :" << c.GetValue() << " " << c.GetSuit() << " " << c.GetGuid() << std::endl;
    m_listOfCards.push_front(std::move(c));
}

Card PersonWithObjects::RemoveCardFromHand()
{
    Card c = std::move(m_listOfCards.front());
    m_listOfCards.pop_front();
    return std::move(c);
}

void PersonWithObjects::PrintOutHand()
{
    for (auto it = m_listOfCards.begin(); it != m_listOfCards.end(); it++)
    {
        std::cout << (*it).GetSuit() << " " << (*it).GetValue() << " " << (*it).GetGuid()<< std::endl;
    }
    std::cout << std::endl;

}

void PersonWithObjects::PrintOutStack() {
    for (auto it = m_stackOfCards.begin(); it != m_stackOfCards.end(); it++) {
        std::cout << (*it).GetSuit() << " " << (*it).GetValue() << " " << (*it).GetGuid()<< std::endl;
    }
    std::cout << std::endl;
}

Card PersonWithObjects::RemoveCardFromHand(int num) {    
    for (auto it = m_listOfCards.begin(); it != m_listOfCards.end(); it++) {
        if((*it).GetGuid() == num) {
            Card c = std::move(*it);
            m_listOfCards.remove(*it);
            return std::move(c);
        }
    }
}

void PersonWithObjects::AddCardToStack(Card  c) {
    m_stackOfCards.push_front(std::move(c));
}

int PersonWithObjects::GetNumCardsStack() {
    return m_stackOfCards.size();
}

int PersonWithObjects::GetNumCardsHand() {
    return m_listOfCards.size();
}