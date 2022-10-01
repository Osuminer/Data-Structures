#pragma once

#include "Card.h"
#include <string>
#include <list>
#include <memory>

class PersonWithSmartPointers
{
public:
	PersonWithSmartPointers(std::string name) ;

	PersonWithSmartPointers() = delete;

	PersonWithSmartPointers( const PersonWithSmartPointers &p) = delete;

	PersonWithSmartPointers(PersonWithSmartPointers && obj) = delete;

	bool playerDiscardedCards = false;

	std::string GetName() const;

	virtual ~PersonWithSmartPointers();

	void AddCardToHand(std::shared_ptr<Card> c);
	std::shared_ptr<Card> RemoveCardFromHand();
	std::shared_ptr<Card> RemoveCardFromHand(int num);
	void PrintOutHand();

	void AddCardToStack(std::shared_ptr<Card> c);
	void PrintOutStack();
	int GetNumCards();

    private: 
        std::string m_name;

        std::list<std::shared_ptr<Card>> m_stackOfCards;
        std::list<std::shared_ptr<Card>> m_listOfCards;

};