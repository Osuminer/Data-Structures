#pragma once
#include "PersonWithObjects.h"
#include "DeckWithObjects.h"
#include "Card.h"



class GameWithObjects
{
	public:
		GameWithObjects();

		virtual ~GameWithObjects();

		void RunGame();
		void RunCheatGame();
		void CheatingAdd(Card c);

		bool isGameComplete();

		void DrawCardFromDeck(PersonWithObjects &player);
		void RemoveCardFromHand(PersonWithObjects &player);
		void PlaceCardInStack(PersonWithObjects &player);
		int PlayerTurn(PersonWithObjects &player);

    private:

		void PrintOutQueueOfPeople();

		void PrintOutStackOfPeople();

		// bool isGameCopmlete;
        PersonWithObjects m_p1;
        PersonWithObjects m_p2;
        PersonWithObjects m_p3;
        DeckWithObjects m_deck;
};