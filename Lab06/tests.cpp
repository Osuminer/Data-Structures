#include <gtest/gtest.h>
#include "BinaryTree.h"
#include <vector>

// Insert test cases ****************************************

TEST(Insert, insert1){
    Node<int>* node = new Node<int>(10);
    Node<int>* node2 = new Node<int>(9);
    Node<int>* node3 = new Node<int>(12);

    // std::shared_ptr<Node<int>> node(new Node<int>(10));

    BinaryTree<int> BST;

    BST.Insert(node);
    BST.Insert(node2);

    ASSERT_TRUE( BST.Insert(node3) );
}

TEST(Insert, insert2){
    BinaryTree<int> cheese;
    Node<int> one(1);
    Node<int> two(2);
    Node<int> three(3);
    Node<int> four(4);
    Node<int> five(5);

    // cheese.Insert(one);
    // cheese.Insert(two);
    // cheese.Insert(three);
    // cheese.Insert(four);
    // cheese.Insert(five);

    // ASSERT_EQ( cheese.Size() , 5);
}

// Find test cases ******************************************

TEST(Find, find1){
    Node<int>* node = new Node<int>(10);
    Node<int>* node2 = new Node<int>(9);
    Node<int>* node3 = new Node<int>(12);

    BinaryTree<int> BST;

    BST.Insert(node);
    BST.Insert(node2);
    BST.Insert(node3);

    ASSERT_EQ(node2->ReturnValue(), BST.Find(9).ReturnValue());
}

TEST(Find, find2){

}

// Size test Cases *******************************************

TEST(Size, nullsize){

}

TEST(Size, size1){

}

// Get All Ascending test cases *******************************

TEST(AllAscending, getAllAscending1){
    Node<int>* node = new Node<int>(10);
    Node<int>* node2 = new Node<int>(9);
    Node<int>* node3 = new Node<int>(12);

    // std::shared_ptr<Node<int>> node(new Node<int>(10));

    BinaryTree<int> BST;

    BST.Insert(node);
    BST.Insert(node2);
    BST.Insert(node3);

    std::vector<int> v;
    v.push_back(9);
    v.push_back(10);
    v.push_back(12);

    ASSERT_EQ(v, BST.GetAllAscending());
}

TEST(AllAscending, getAllAscending2){

}

// Clear test cases *******************************************

TEST(Clear, clear1){

}

TEST(Clear, clear2){

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}