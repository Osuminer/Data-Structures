#pragma once

#include "Card.h"
#include <string>
#include <list>

class PersonWithPointers
{
public:
	PersonWithPointers(std::string name) ;
	PersonWithPointers() = delete;

	PersonWithPointers( const PersonWithPointers &p) = delete;

	PersonWithPointers(PersonWithPointers && obj) = delete;


	std::string GetName() const;

	virtual ~PersonWithPointers();

	void AddCardToHand( Card * c);
	Card * RemoveCardFromHand();
	void PrintOutHand();


    private: 
        std::string m_name;

        std::list< Card *> m_stackOfCards;
        std::list< Card *> m_listOfCards;

};