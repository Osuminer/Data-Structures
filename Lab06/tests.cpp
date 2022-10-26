#include <gtest/gtest.h>
#include "BinaryTree.h"

// Insert test cases ****************************************

TEST(Insert, insert1){
    BinaryTree<int> cheese;
    Node<int> one(1);
    Node<int> two(2);
    cheese.Insert(one); 
    ASSERT_TRUE( cheese.Insert(two) );

}

TEST(Insert, insert2){
    BinaryTree<int> cheese;
    Node<int> one(1);
    Node<int> two(2);
    Node<int> three(3);
    Node<int> four(4);
    Node<int> five(5);

    cheese.Insert(one);
    cheese.Insert(two);
    cheese.Insert(three);
    cheese.Insert(four);
    cheese.Insert(five);

    ASSERT_EQ( cheese.Size() , 5);
}

// Find test cases ******************************************

TEST(Find, find1){

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

}

TEST(AllAscending, getAllAscending2){

}

// Clear test cases *******************************************

TEST(Clear, clear1){

}

TEST(Clear, clear2){

}