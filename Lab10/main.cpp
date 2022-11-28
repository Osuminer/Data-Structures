#include "HashTable.h"
#include "Node.h"

int main() {
    HashTable<int, Node<int>> h(5);

    Node<int> a(1, 7);
    Node<int> b(7, 3);
    Node<int> c(1, 4);

    h.AddItem(a);
    h.AddItem(b);
    h.AddItem(c);

    h.GetItem(c);
}