#pragma once
#include <list>
#include <memory>

class DeckWithSmartPointers;
class PersonWithSmartPointers;

class GameWithSmartPointers
{
	public:


		GameWithSmartPointers();

		virtual ~GameWithSmartPointers();

		void RunGame();

		bool isGameComplete();

		void DrawCardFromDeck(PersonWithSmartPointers &player);
		void RemoveCardFromHand(PersonWithSmartPointers &player);
		void PlaceCardInStack(PersonWithSmartPointers &player);
		int PlayerTurn(PersonWithSmartPointers &player);


    private:
        std::unique_ptr<PersonWithSmartPointers> m_p1;
        std::unique_ptr<PersonWithSmartPointers> m_p2;
        std::unique_ptr<PersonWithSmartPointers> m_p3;
        std::unique_ptr<DeckWithSmartPointers> m_deck;
        void PrintOutQueueOfPeople();
        void PrintOutStackOfPeople();

};