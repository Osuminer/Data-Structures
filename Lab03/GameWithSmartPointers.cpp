#include "GameWithSmartPointers.h"
#include <iostream>
#include <list>
#include "Card.h"
#include "PersonWithSmartPointers.h"
#include "DeckWithSmartPointers.h"

GameWithSmartPointers::GameWithSmartPointers()
{
    m_p1 = std::make_unique<PersonWithSmartPointers>("Huey 1");
    m_p2 = std::make_unique<PersonWithSmartPointers>("Louie 2");
    m_p3 = std::make_unique<PersonWithSmartPointers>("Dewey 3");
    m_deck = std::make_unique<DeckWithSmartPointers> ();
}

GameWithSmartPointers::~GameWithSmartPointers()
{
    std::cout<<"GameWithSmartPointers Destructor Called"<<std::endl;	

}

void GameWithSmartPointers::RunGame()
{


    std::shared_ptr<Card> card1Pointer = std::make_shared<Card> (1,1);
    std::cout<<"Calling Smart Pointer Version"<<std::endl;
    m_p1->AddCardToHand(card1Pointer);
    std::cout<<"End Calling Smart Pointer Version"<<std::endl;

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

