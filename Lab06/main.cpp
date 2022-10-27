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
    
    return 0;
}