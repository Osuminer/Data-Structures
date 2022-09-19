#include "GameWithPointers.h"
#include <iostream>
#include <list>
#include "Card.h"
#include "PersonWithPointers.h"
#include "DeckWithPointers.h"

GameWithPointers::GameWithPointers()
{
    m_p1 = new PersonWithPointers("Huey 1");
    m_p2 = new PersonWithPointers("Louie 2");
    m_p3 = new PersonWithPointers("Dewey 3");
    m_deck = new DeckWithPointers();
}

GameWithPointers::~GameWithPointers()
{
    std::cout<<"GameWithPointers Destructor Called"<<std::endl;	
    delete m_p1;
    delete m_p2;
    delete m_p3;
    delete m_deck;

}

void GameWithPointers::RunGame()
{
    Card * card1Pointer = new Card(1,1);
    std::cout<<"Calling Pointer Version"<<std::endl;
    m_p1->AddCardToHand(card1Pointer);
    std::cout<<"End Calling Pointer Version"<<std::endl;

    std::cout<<"Start Drawing Cards"<<std::endl;
    std::cout<<"Drawing Cards 1"<<std::endl;
    m_p1->AddCardToHand(m_deck->DrawCard());
    std::cout<<"Drawing Cards 2"<<std::endl;
    m_p1->AddCardToHand(m_deck->DrawCard());
    std::cout<<"Drawing Cards 3"<<std::endl;
    m_p2->AddCardToHand(m_deck->DrawCard());
    std::cout<<"Drawing Cards 4"<<std::endl;
    m_p2->AddCardToHand(m_deck->DrawCard());
    std::cout<<"Drawing Cards 5"<<std::endl;
    m_p3->AddCardToHand(m_deck->DrawCard());
    std::cout<<"Drawing Cards 6"<<std::endl;
    m_p3->AddCardToHand(m_deck->DrawCard());

    std::cout << "P1 Player::PrintOutHand" << std::endl;
    m_p1->PrintOutHand();
    std::cout << "P2 Player::PrintOutHand" << std::endl;
    m_p2->PrintOutHand();
    std::cout << "P4 Player::PrintOutHand" << std::endl;
    m_p3->PrintOutHand();
    std::cout << "End Player::PrintOutHand" << std::endl;

    std::cout << "PrintDeck" << std::endl;
    m_deck->PrintDeck();

    m_deck->ReturnCard(m_p1->RemoveCardFromHand());
    m_deck->ReturnCard(m_p1->RemoveCardFromHand());

    m_deck->ReturnCard(m_p2->RemoveCardFromHand());
    m_deck->ReturnCard(m_p3->RemoveCardFromHand());

    std::cout << "PrintDeck" << std::endl;
    m_deck->PrintDeck();
    std::cout << "P1 Player::PrintOutHand" << std::endl;
    m_p1->PrintOutHand();
    std::cout << "P2 Player::PrintOutHand" << std::endl;
    m_p2->PrintOutHand();
    std::cout << "P3 Player::PrintOutHand" << std::endl;
    m_p3->PrintOutHand();
    std::cout << "End Player::PrintOutHand" << std::endl;

}

