
#include "GameWithObjects.h"
#include <iostream>


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

void GameWithObjects::RunGame()
{


    Card card1Object = Card(11,1);
    std::cout<<"Calling AddCardToHandObject"<<std::endl;
    m_p1.AddCardToHand(std::move(card1Object));
    std::cout<<"End Calling AddCardToHandObject"<<std::endl;
    std::cout<<std::endl<<std::endl;

    std::cout<<"Start Drawing Cards"<<std::endl;
    std::cout<<"Drawing Cards 1"<<std::endl;
    m_p1.AddCardToHand(std::move(m_deck.DrawCard()));
    std::cout<<"Drawing Cards 2"<<std::endl;
    m_p1.AddCardToHand(std::move(m_deck.DrawCard()));
    std::cout<<"Drawing Cards 3"<<std::endl;
    m_p2.AddCardToHand(std::move(m_deck.DrawCard()));
    std::cout<<"Drawing Cards 4"<<std::endl;
    m_p2.AddCardToHand(std::move(m_deck.DrawCard()));
    std::cout<<"Drawing Cards 5"<<std::endl;
    m_p3.AddCardToHand(std::move(m_deck.DrawCard()));
    std::cout<<"Drawing Cards 6"<<std::endl;
    m_p3.AddCardToHand(std::move(m_deck.DrawCard()));

    std::cout << "P1 Player::PrintOutHand" << std::endl;
    m_p1.PrintOutHand();
    std::cout << "P2 Player::PrintOutHand" << std::endl;
    m_p2.PrintOutHand();
    std::cout << "P4 Player::PrintOutHand" << std::endl;
    m_p3.PrintOutHand();
    std::cout << "End Player::PrintOutHand" << std::endl;

    std::cout << "PrintDeck" << std::endl;
    m_deck.PrintDeck();

    m_deck.ReturnCard(std::move(m_p1.RemoveCardFromHand()));
    m_deck.ReturnCard(std::move(m_p1.RemoveCardFromHand()));

    m_deck.ReturnCard(std::move(m_p2.RemoveCardFromHand()));
    m_deck.ReturnCard(std::move(m_p3.RemoveCardFromHand()));

    std::cout << "PrintDeck" << std::endl;
    m_deck.PrintDeck();
    std::cout << "P1 Player::PrintOutHand" << std::endl;
    m_p1.PrintOutHand();
    std::cout << "P2 Player::PrintOutHand" << std::endl;
    m_p2.PrintOutHand();
    std::cout << "P3 Player::PrintOutHand" << std::endl;
    m_p3.PrintOutHand();
    std::cout << "End Player::PrintOutHand" << std::endl;

}

