
#include "PersonWithPointers.h"
#include <iostream>

PersonWithPointers::PersonWithPointers(std::string name) :m_name(name)
{

}




std::string PersonWithPointers::GetName() const
{
    return m_name;
}

PersonWithPointers::~PersonWithPointers()
{
    std::cout << "Deleting PersonWithObjects" << m_name << std::endl;
    for(auto it = m_listOfCards.begin(); it != m_listOfCards.end(); it++)
    {
        delete *it;
    }
    m_listOfCards.clear();
}

void PersonWithPointers::AddCardToHand( Card * c)  
{
    std::cout<<"   AddCardToHandPointer :"<<c->GetValue()<<" "<<c->GetSuit()<<" "<<c->GetGuid()<<std::endl;
    m_listOfCards.push_front(c);
}

Card * PersonWithPointers::RemoveCardFromHand()
{
    Card * retVal = m_listOfCards.front();
    m_listOfCards.pop_front();
    return retVal;

}

void PersonWithPointers::PrintOutHand()
{
    for(auto it = m_listOfCards.begin(); it != m_listOfCards.end(); it++)
    {
        std::cout<<"   AddCardToHandPointer :"<<(*it)->GetValue()<<" "<<(*it)->GetSuit()<<" "<<(*it)->GetGuid()<<std::endl;
    }
}
