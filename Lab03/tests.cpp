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
			game.RunGame();
			ASSERT_TRUE(game.isGameComplete());

		}

		TEST(GameWithObjectsTests, PlayerTurn1){
			GameWithObjects game;
			PersonWithObjects player("Player1");
			ASSERT_TRUE(game.PlayerTurn(player));
		}

		//Deck With Objects********************************************

		TEST(DeckWithObjectsTests, DrawCard1){
			DeckWithObjects deck;
			ASSERT_TRUE(deck.DrawCard());
		}

		TEST(DeckWithObjectsTests, ReturmCard1){
			DeckWithObjects deck;
			Card card(1,1);
			ASSERT_ANY_THROW(deck.ReturnCard(card));
			
		}

		TEST(DeckWithObjectsTests, PrintDeck1){
			DeckWithObjects deck;
			ASSERT_ANY_THROW(deck.PrintDeck());
		}

		//Person With Objects*******************************************

		TEST(PersonWithObjectsTests, GetName1){
			PersonWithObjects person("player1");
			ASSERT_EQ(person.GetName() , "player1");
		}

		TEST(PersonWithObjectsTests, GetNumCards1){
			PersonWithObjects person("player1");
			ASSERT_EQ(person.GetNumCardsHand(), 0);
		}

		TEST(PersonWithObjectsTests, GetNumCards2){
			PersonWithObjects person("player1");
			ASSERT_TRUE(person.GetNumCardsHand());
		}

		//************Game With Smart Pointers************//

		TEST(GameWithSmartPointersTests,isGameComplete1){
			GameWithSmartPointers game;
			ASSERT_FALSE(game.isGameComplete());
		}

		TEST(GameWithSmartPointersTests,RunGame1){
			GameWithSmartPointers game;
			ASSERT_ANY_THROW(game.RunGame());
		}

		TEST(GameWithSmartPointersTests, PlayerTurn1){
			GameWithSmartPointers game;
			PersonWithSmartPointers player("player1");
			ASSERT_TRUE(game.PlayerTurn(player));
		}
		
		//Deck With Smart Pointers*************************************

		TEST(DeckWithSmartPointersTests, DrawCard1){
			DeckWithSmartPointers deck;
			ASSERT_TRUE(deck.DrawCard());
		}

		TEST(DeckWithSmartPointersTests, ReturmCard1){
			DeckWithSmartPointers deck;
			ASSERT_ANY_THROW(deck.ReturnCard(deck.DrawCard()));
		}

		TEST(DeckWithSmartPointerstests, PrintDeck1){
			DeckWithSmartPointers deck;
			ASSERT_ANY_THROW(deck.PrintDeck());
		}

		//Person With Smart Pointers***********************************

		TEST(PersonWithSmartPointersTests, GetName1){
			PersonWithSmartPointers person("player1");
			ASSERT_EQ(person.GetName() , "player1");
		}

		TEST(PersonWithSmartPointersTests, AddCardToHand1){
			PersonWithSmartPointers person("player1");
			std::shared_ptr<Card> c;
			ASSERT_ANY_THROW(person.AddCardToHand(c));
		}

		TEST(PersonWithSmartPointersTests, GetNumCards1){
			PersonWithSmartPointers person("player1");
			ASSERT_TRUE(person.GetNumCardsStack());
		}

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
