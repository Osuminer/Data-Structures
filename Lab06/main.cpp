#include "BinaryTree.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    BinaryTree<std::string> BST;

    Node<std::string>* node = new Node<std::string>("Star Wars");
    Node<std::string>* node2 = new Node<std::string>("Star Trek");
    Node<std::string>* node3 = new Node<std::string>("Space Balls");
    Node<std::string>* node4 = new Node<std::string>("Galaxy Quest");

    BST.Insert(node);
    BST.Insert(node2);
    BST.Insert(node3);
    BST.Insert(node4);

    cout << "\n\n";

    for (auto i: BST.GetAllAscending()) {
        cout << i << ", ";
    }

    cout << endl;

    BST.Clear();

    // First --------------------------------------------------------------------

    Node<std::string>* node5 = new Node<std::string>("Cars");
    Node<std::string>* node6 = new Node<std::string>("Monsters, Inc");
    Node<std::string>* node7 = new Node<std::string>("The Incredibles");
    Node<std::string>* node8 = new Node<std::string>("Wall-E");

    BST.Insert(node5);
    BST.Insert(node6);
    BST.Insert(node7);
    BST.Insert(node8);

    cout << "\n\n";

    for (auto i: BST.GetAllAscending()) {
        cout << i << ", ";
    }

    cout << endl;

    BST.Clear();

    // Second --------------------------------------------------------------------

    Node<std::string>* node9 = new Node<std::string>("Halloween");
    Node<std::string>* node10 = new Node<std::string>("A Nightmare On Elm Street");
    Node<std::string>* node11 = new Node<std::string>("Hocus Pocus");
    Node<std::string>* node12 = new Node<std::string>("Beetlejuice");

    BST.Insert(node9);
    BST.Insert(node10);
    BST.Insert(node11);
    BST.Insert(node12);

    cout << "\n\n";

    for (auto i: BST.GetAllAscending()) {
        cout << i << ", ";
    }

    cout << "\n" << endl;
    
    return 0;
}