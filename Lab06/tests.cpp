#include <gtest/gtest.h>
#include "BinaryTree.h"

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
    BinaryTree<int> BST;
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2);
    Node<int>* node3 = new Node<int>(3);
    Node<int>* node4 = new Node<int>(4);
    Node<int>* node5 = new Node<int>(5);

    BST.Insert(node1);
    BST.Insert(node2);
    BST.Insert(node3);
    BST.Insert(node4);
    BST.Insert(node5);

    ASSERT_EQ( BST.Size() , 5);
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
    Node<double>* node1 = new Node<double>(1.11);
    Node<double>* node2 = new Node<double>(1.12);
    Node<double>* node3 = new Node<double>(1.13);

    BinaryTree<double> BST;

    BST.Insert(node1);
    BST.Insert(node2);
    BST.Insert(node3);

    ASSERT_EQ( node3->ReturnValue(), BST.Find(1.13).ReturnValue() );
}

// Size test Cases *******************************************

TEST(Size, nullsize){
    BinaryTree<int> BST;

    ASSERT_EQ( BST.Size(), 0 );
}

TEST(Size, size1){
    BinaryTree<int> BST;
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2);
    Node<int>* node3 = new Node<int>(3);
    Node<int>* node4 = new Node<int>(4);
    Node<int>* node5 = new Node<int>(5);

    BST.Insert(node1);
    BST.Insert(node2);
    BST.Insert(node3);
    BST.Insert(node4);
    BST.Insert(node5);

    ASSERT_EQ( BST.Size() , 5);
}


// Get All Ascending test cases *******************************

TEST(AllAscending, getAllAscending1){

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