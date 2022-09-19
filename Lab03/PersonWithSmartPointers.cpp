
#include "PersonWithSmartPointers.h"
#include <iostream>

PersonWithSmartPointers::PersonWithSmartPointers(std::string name) :m_name(name)
{

}




std::string PersonWithSmartPointers::GetName() const
{
    return m_name;
}

PersonWithSmartPointers::~PersonWithSmartPointers()
{
    std::cout << "Deleting PersonWithObjects" << m_name << std::endl;
    
}

void PersonWithSmartPointers::AddCardToHand(std::shared_ptr<Card> c)  
{
    std::cout<<"   AddCardToHandPointer :"<<c->GetValue()<<" "<<c->GetSuit()<<" "<<c->GetGuid()<<std::endl;
    m_listOfCards.push_front(c);
}



std::shared_ptr<Card> PersonWithSmartPointers::RemoveCardFromHand()  
{
    std::shared_ptr<Card> retVal = m_listOfCards.front();
    m_listOfCards.pop_front();
    return retVal;
}


void PersonWithSmartPointers::PrintOutHand()  
{
    
    for(auto it = m_listOfCards.begin(); it != m_listOfCards.end(); it++)
    {
        std::cout<<"   AddCardToHandPointer :"<<(*it)->GetValue()<<" "<<(*it)->GetSuit()<<" "<<(*it)->GetGuid()<<std::endl;
    }
}

