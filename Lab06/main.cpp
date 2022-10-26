#include "BinaryTree.h"

int main() {

    Node<int>* node = new Node<int>(10);
    Node<int>* node2 = new Node<int>(12);

    BinaryTree<int> BST;

    BST.Insert(node);
    
    return 0;
}