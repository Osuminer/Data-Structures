
#include "GameWithObjects.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


GameWithObjects::GameWithObjects(): m_p1("Huey 1"), m_p2("Louie 2"), m_p3("Dewey 3"), m_deck()
{
    
}

GameWithObjects::~GameWithObjects()
{
    // std::cout<<"GameWithObjects Destructor Called"<<std::endl;	
}

void GameWithObjects::CheatingAdd(Card c)
{

}

void GameWithObjects::RunCheatGame()
{
    Card card1Object = Card(11,1);

    CheatingAdd(card1Object);
    // std::cout<<"End Calling AddCardToHandObject"<<std::endl;
    // std::cout<<std::endl<<std::endl;
}

bool GameWithObjects::isGameComplete() {
    if (m_p1.GetNumCards() == 13 || m_p2.GetNumCards() == 13 || m_p3.GetNumCards() == 13) {
        return true;
    } else {
        return false;
    }
}

void GameWithObjects::RunGame()
{
    int input;  // Stores user input
    bool turnComplete = false;  // Token that stores if a turn is complete

    // Game loop
    while (isGameComplete() == false) {
        // Player 1 turn loop ---------------------------------------------------------
        PlayerTurn(m_p1);

        // Player 2 turn loop ---------------------------------------------------------
        PlayerTurn(m_p2);

        // Player 3 turn loop ---------------------------------------------------------
        PlayerTurn(m_p3);

    }

    // Card card1Object = Card(11,1);
    // std::cout<<"Calling AddCardToHandObject"<<std::endl;
    // m_p1.AddCardToHand(std::move(card1Object));
    // std::cout<<"End Calling AddCardToHandObject"<<std::endl;
    // std::cout<<std::endl<<std::endl;

    // std::cout<<"Start Drawing Cards"<<std::endl;
    // std::cout<<"Drawing Cards 1"<<std::endl;
    // m_p1.AddCardToHand(std::move(m_deck.DrawCard()));
    // std::cout<<"Drawing Cards 2"<<std::endl;
    // m_p1.AddCardToHand(std::move(m_deck.DrawCard()));
    // std::cout<<"Drawing Cards 3"<<std::endl;
    // m_p2.AddCardToHand(std::move(m_deck.DrawCard()));
    // std::cout<<"Drawing Cards 4"<<std::endl;
    // m_p2.AddCardToHand(std::move(m_deck.DrawCard()));
    // std::cout<<"Drawing Cards 5"<<std::endl;
    // m_p3.AddCardToHand(std::move(m_deck.DrawCard()));
    // std::cout<<"Drawing Cards 6"<<std::endl;
    // m_p3.AddCardToHand(std::move(m_deck.DrawCard()));

    // std::cout << "P1 Player::PrintOutHand" << std::endl;
    // m_p1.PrintOutHand();
    // std::cout << "P2 Player::PrintOutHand" << std::endl;
    // m_p2.PrintOutHand();
    // std::cout << "P4 Player::PrintOutHand" << std::endl;
    // m_p3.PrintOutHand();
    // std::cout << "End Player::PrintOutHand" << std::endl;

    // std::cout << "PrintDeck" << std::endl;
    // m_deck.PrintDeck();

    // m_deck.ReturnCard(std::move(m_p1.RemoveCardFromHand()));
    // m_deck.ReturnCard(std::move(m_p1.RemoveCardFromHand()));

    // m_deck.ReturnCard(std::move(m_p2.RemoveCardFromHand()));
    // m_deck.ReturnCard(std::move(m_p3.RemoveCardFromHand()));

    // std::cout << "PrintDeck" << std::endl;
    // m_deck.PrintDeck();
    // std::cout << "P1 Player::PrintOutHand" << std::endl;
    // m_p1.PrintOutHand();
    // std::cout << "P2 Player::PrintOutHand" << std::endl;
    // m_p2.PrintOutHand();
    // std::cout << "P3 Player::PrintOutHand" << std::endl;
    // m_p3.PrintOutHand();
    // std::cout << "End Player::PrintOutHand" << std::endl;
}

int GameWithObjects::PlayerTurn(PersonWithObjects &player) {
    int input;
    bool turnComplete = false;
    char response;

    // Draw one card at  start of turn
    player.AddCardToHand(std::move(m_deck.DrawCard()));

    // If player discraded cards last turn, draw 5 new ones
    if (player.playerDiscardedCards) {
        for (int i = 0; i < 5; i++) {
            player.AddCardToHand(std::move(m_deck.DrawCard()));
        }

        player.playerDiscardedCards = false;
    }

    do {
        cout << "\n" << player.GetName() << "'s turn: Choose choice" << endl;
        player.PrintOutHand();
        cout << "1: Draw cards from deck" << endl;
        cout << "2: Remove all cards and start with 5 next turn" << endl;
        cout << "3: Place card in stack\n" << endl;

        cin >> input;

        switch(input) {
            case 1:
                DrawCardFromDeck(player);
                cout << "============================================================" << endl;
                break;
            case 2:
                RemoveCardFromHand(player);
                cout << "============================================================" << endl;
                break;
            case 3:
                PlaceCardInStack(player);
                cout << "============================================================" << endl;
                break;
        }

        cout << "\nAre you done with your turn(y/n): ";
        cin >> response;

        if(response == 'y') {
            turnComplete = true;
        }

    } while (!turnComplete);

    
    cout << "============================================================" << endl;

    return input;
}

void GameWithObjects::DrawCardFromDeck(PersonWithObjects &player) {
    int numCards = player.GetNumCards();
    int input;

    // Check for valid input
    do {
        cout << endl << "Pick the number of cards you want to draw: ";
        cin >> input;
        cout << endl;
    } while(input > 6 - numCards);

    // Move number of cards from top of deck to players hand
    for (int i = 0; i < input; i++) {
        player.AddCardToHand(std::move(m_deck.DrawCard()));
    }
}

void GameWithObjects::RemoveCardFromHand(PersonWithObjects &player) {
    int numCards = player.GetNumCards();

    // Remove all cards from hand
    for (int i = 0; i < numCards; i++) {
        m_deck.ReturnCard(std::move(player.RemoveCardFromHand()));
    }

    player.playerDiscardedCards = true;
}

void GameWithObjects::PlaceCardInStack(PersonWithObjects &player) {
    bool turnDone = false;
    int input;
    char response;

    do {
    cout << "\n" << player.GetName() << "'s hand: " << endl;
    player.PrintOutHand();

    cout << "\n" << player.GetName() << "'s stack: " << endl;
    player.PrintOutStack();

    cout << "\n\nEnter card id to move: ";
    cin >> input;

    player.AddCardToStack(std::move(player.RemoveCardFromHand(input)));

    player.PrintOutStack();

    cout << "Would you like to draw a new card(y/n): ";
    cin >> response;

    if(response == 'y') {
        turnDone = true;
    }

    } while(!turnDone);

}