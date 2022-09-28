#pragma once

#include "Card.h"
#include <string>
#include <list>

class PersonWithObjects
{
public:
	PersonWithObjects(std::string name) ;

	PersonWithObjects() = delete;

	PersonWithObjects(const PersonWithObjects &p);

	PersonWithObjects(PersonWithObjects && obj) noexcept;


	std::string GetName() const;

	bool playerDiscardedCards = false;

	virtual ~PersonWithObjects();

	void AddCardToHand(Card  c);
	void AddCardToHand(Card& c);
	Card RemoveCardFromHand();
	Card RemoveCardFromHand(int num);
	void PrintOutHand();

	void AddCardToStack(Card c);
	void PrintOutStack();
	int GetNumCards();

    private: 
        std::string m_name;
        std::list< Card > m_stackOfCards;
        std::list< Card > m_listOfCards;

};