#include <gtest/gtest.h>
#include "HashTable.h"
#include "Node.h"


// Add ---------------------------------------------------------------------
TEST(Add, Add1) {
    HashTable<int, Node<int>> h(5);
    Node<int> a(0, 4);

    h.AddItem(a);

    ASSERT_EQ(h.Contains(), 1);
}
TEST(Add, Add2) {
    HashTable<int, Node<int>> h(5);
    Node<int> a(8, 3);
    Node<int> b(2, 6);

    h.AddItem(a);
    h.AddItem(b);

    ASSERT_EQ(h.Contains(), 2);
}

// Hash ---------------------------------------------------------------------
TEST(Hash, Hash1) {
    HashTable<int, Node<int>> h(5);
    Node<int> a(8, 3);

    ASSERT_EQ(h.Hash(a.key), 0);
}
TEST(Hash, Hash2) {
    HashTable<int, Node<int>> h(5);
    Node<int> a(2, 6);

    ASSERT_EQ(h.Hash(a.key), 2);
}

// Contains ---------------------------------------------------------------------
TEST(Contains, Contains1) {
    HashTable<int, Node<int>> h(5);
    Node<int> a(0, 4);
    Node<int> b(5, 9);
    Node<int> c(9, 3);

    h.AddItem(a);
    h.AddItem(b);
    h.AddItem(c);

    ASSERT_EQ(h.Contains(), 3);
}
TEST(Contains, Contains2) {
    HashTable<int, Node<int>> h(5);

    ASSERT_EQ(h.Contains(), 0);
}

// Get Item ---------------------------------------------------------------------
TEST(GetItem, GetItem1) {
    HashTable<int, Node<int>> h(5);
    Node<int> a(8, 3);

    h.AddItem(a);

    ASSERT_EQ(h.GetItem(a)->data, a.data);
}
TEST(GetItem, GetItem2) {
    HashTable<int, Node<int>> h(5);
    Node<int> a(0, 4);
    Node<int> b(5, 9);
    Node<int> c(9, 3);

    h.AddItem(a);
    h.AddItem(b);
    h.AddItem(c);

    ASSERT_EQ(h.GetItem(c)->data, c.data);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}