
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
    // std::cout << "Deleting PersonWithObjects" << m_name << std::endl;
    
}

void PersonWithSmartPointers::AddCardToHand(std::shared_ptr<Card> c)  
{
    std::cout<<c->GetValue()<<" "<<c->GetSuit()<<" "<<c->GetGuid()<<std::endl;
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
        std::cout <<(*it)->GetValue()<<" "<<(*it)->GetSuit()<<" "<<(*it)->GetGuid()<<std::endl;
    }
}

void PersonWithSmartPointers::PrintOutStack() {
    for (auto it = m_stackOfCards.begin(); it != m_stackOfCards.end(); it++) {
        std::cout << (*it)->GetSuit() << " " << (*it)->GetValue() << " " << (*it)->GetGuid()<< std::endl;
    }
    std::cout << std::endl;
}

std::shared_ptr<Card> PersonWithSmartPointers::RemoveCardFromHand(int num) {    
    for (auto it = m_listOfCards.begin(); it != m_listOfCards.end(); it++) {
        if((*it)->GetGuid() == num) {
            m_listOfCards.remove(*it);
            return *it;
        }
    }
}

void PersonWithSmartPointers::AddCardToStack(std::shared_ptr<Card> c) {
    m_stackOfCards.push_front(std::move(c));
}

int PersonWithSmartPointers::GetNumCards() {
    return m_stackOfCards.size();
}