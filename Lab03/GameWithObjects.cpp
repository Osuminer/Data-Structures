
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
    std::cout<<"GameWithObjects Destructor Called"<<std::endl;	
}

void GameWithObjects::CheatingAdd(Card c)
{

}

void GameWithObjects::RunCheatGame()
{
    Card card1Object = Card(11,1);

    CheatingAdd(card1Object);
    std::cout<<"End Calling AddCardToHandObject"<<std::endl;
    std::cout<<std::endl<<std::endl;
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
//TODO: draw 5 cards from top of deck to each player

    int input;
    bool turnComplete = false;

    while (isGameComplete() == false) {
        do {
            std::cout << std::endl << "Player 1's turn: Choose choice" << std::endl;
            std::cout << "1: Draw cards from deck" << std::endl;
            std::cout << "2: Remove all cards and start with 5 next turn" << std::endl << std::endl;

            std::cin >> input;

            switch (input) {
                case 1:
                    do {
                    cout << endl << "Pick the number of cards you want to draw: ";
                    cin >> input;
                    } while();


                    break;
                case 2:

                    break;
                default:
                    break;
            }

        } while (!turnComplete);












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

