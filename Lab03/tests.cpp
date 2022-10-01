// tests.cpp

#include "GameWithObjects.h"
#include "GameWithSmartPointers.h"
#include "PersonWithObjects.h"
#include "PersonWithSmartPointers.h"
#include "DeckWithObjects.h"
#include "DeckWithSmartPointers.h"
#include "Card.h"
#include <gtest/gtest.h>


		//************ Game With Objects ************//
		
 		TEST(GameWithObjectsTests,isGameComplete1){
			GameWithObjects game;
			ASSERT_FALSE(game.isGameComplete());
		}

		TEST(GameWithObjectsTests,RunGame1){
			GameWithObjects game;
			ASSERT_TRUE(game.RunGame());
		}

		TEST(GameWithObjectsTests, PlayerTurn1){
			GameWithObjects game;
			PersonWithObjects player;
			ASSERT_TRUE(game.PlayerTurn(player));
		}

		//Deck With Objects********************************************

		TEST(DeckWithObjectsTests, DrawCard1){
			DeckwithObjects deck;
			ASSERT_TRUE(deck.DrawCard());
		}

		TEST(DeckWithObjectsTests, ReturmCard1){
			DeckwithObjects deck;
			Card card;
			ASSERT_TRUE(deck.ReturnCard(card));
		}

		TEST(DeckWithObjectsTests, PrintDeck1){
			DeckwithObjects deck;
			ASSERT_TRUE(deck.PrintDeck());
		}

		//Person With Objects*******************************************

		TEST(PersonWithObjectsTests, GetName1){
			PersonWithObjects person;
			ASSERT_TRUE(person.GetName());
		}

		TEST(PersonWithObjectsTests, AddCardToHand1){
			PersonWithObjects person;
			Card card;
			ASSERT_TRUE(person.AddCardToHand(card));
		}

		TEST(PersonWithObjectsTests, GetNumCards1){
			PersonWithObjects person;
			ASSERT_TRUE(person.GetNumCardsHand());
		}

		//************Game With Smart Pointers************//

		TEST(GameWithSmartPointersTests,isGameComplete1){
			GameWithSmartPointers game;
			ASSERT_FALSE(game.isGameComplete());
		}

		TEST(GameWithSmartPointersTests,RunGame1){
			GameWithSmartPointers game;
			ASSERT_TRUE(game.RunGame());
		}

		TEST(GameWithSmartPointersTests, PlayerTurn1){
			GameWithSmartPointers game;
			PersonWithSmartPointers player;
			ASSERT_TRUE(game.PlayerTurn(player));
		}
		
		//Deck With Smart Pointers*************************************

		TEST(DeckWithSmartPointersTests, DrawCard1){
			DeckwithSmartPointers deck;
			ASSERT_TRUE(deck.DrawCard());
		}

		TEST(DeckWithSmartPointersTests, ReturmCard1){
			DeckwithSmartPointers deck;
			ASSERT_TRUE(deck.ReturnCard(deck.DrawCard()));
		}

		TEST(DeckWithSmartPointerstests, PrintDeck1){
			DeckwithSmartPointers deck;
			ASSERT_TRUE(deck.PrintDeck());
		}

		//Person With Smart Pointers***********************************

		TEST(PersonWithSmartPointersTests, GetName1){
			PersonWithSmartPointers person;
			ASSERT_TRUE(person.GetName());
		}

		TEST(PersonWithSmartPointersTests, AddCardToHand1){
			PersonWithSmartPointers person;
			Card card;
			ASSERT_TRUE(person.AddCardToHand(card));
		}

		TEST(PersonWithSmartPointersTests, GetNumCards1){
			PersonWithSmartPointers person;
			ASSERT_TRUE(person.GetNumCardsStack());
		}

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
